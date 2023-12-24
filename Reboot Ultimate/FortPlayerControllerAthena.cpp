#include "FortPlayerControllerAthena.h"
#include "FortPlayerPawn.h"
#include "FortKismetLibrary.h"

#include "SoftObjectPtr.h"
#include "globals.h"
#include "GameplayStatics.h"
#include "hooking.h"
#include "FortAthenaMutator_GiveItemsAtGamePhaseStep.h"
#include "DataTableFunctionLibrary.h"
#include "AthenaResurrectionComponent.h"
#include "FortAthenaMutator_InventoryOverride.h"
#include "FortGadgetItemDefinition.h"
#include "gui.h"
#include "FortAthenaMutator_GG.h"

void AFortPlayerControllerAthena::GiveXP(AFortPlayerControllerAthena* PC, int CombatXP, int SurvivalXP, int BonusMedalXP, int ChallengeXP, int MatchXP)
{
	UFortPlayerControllerAthenaXPComponent* XPComponent = PC->GetXPComponent();

	if (XPComponent)
	{
		XPComponent->GetCombatXp() += CombatXP;
		XPComponent->GetSurvivalXp() += SurvivalXP;
		XPComponent->GetMedalBonusXP() += BonusMedalXP;
		XPComponent->GetChallengeXp() += ChallengeXP;
		XPComponent->GetMatchXp() += MatchXP;
		XPComponent->GetTotalXpEarned() += (CombatXP + SurvivalXP + BonusMedalXP + ChallengeXP + MatchXP);
		XPComponent->GetCachedLevelInfo().GetLevelXp() += XPComponent->GetTotalXpEarned();
		XPComponent->GetCachedLevelInfo().GetBookLevelXp() += XPComponent->GetTotalXpEarned();
		XPComponent->OnXpUpdated(CombatXP, SurvivalXP, BonusMedalXP, ChallengeXP, MatchXP, XPComponent->GetTotalXpEarned());
	}
}

void AFortPlayerControllerAthena::ProgressQuest(AFortPlayerControllerAthena* PC, UFortQuestItemDefinition* QuestDef, FName BackendName)
{
	PC->GetQuestManager(ESubGame::Athena)->SelfCompletedUpdatedQuest(PC, QuestDef, BackendName, 1, 1, nullptr, true, false);
	AFortPlayerStateAthena* PlayerState = (AFortPlayerStateAthena*)PC->GetPlayerState();
	for (size_t i = 0; i < PlayerState->GetPlayerTeam()->GetTeamMembers().Num(); i++)
	{
		auto pc = (AFortPlayerControllerAthena*)PlayerState->GetPlayerTeam()->GetTeamMembers()[i];
		if (pc && pc != PC)
		{
			pc->GetQuestManager(ESubGame::Athena)->SelfCompletedUpdatedQuest(PC, QuestDef, BackendName, 1, 1, PlayerState, true, false);
		}
	}
	auto QuestItem = PC->GetQuestManager(ESubGame::Athena)->GetQuestWithDefinition(QuestDef);

	FXPEventEntry XPEventEntry{};

	XPEventEntry.EventXpValue = 5000;//still skunked i will make it so it gets real xp value from datatable
	XPEventEntry.QuestDef = QuestDef;
	XPEventEntry.Time = UGameplayStatics::GetTimeSeconds(GetWorld());
	PC->GetXPComponent()->GetChallengeXp() += XPEventEntry.EventXpValue;
	PC->GetXPComponent()->GetTotalXpEarned() += XPEventEntry.EventXpValue;
	XPEventEntry.TotalXpEarnedInMatch = PC->GetXPComponent()->GetTotalXpEarned();
	XPEventEntry.SimulatedXpEvent = QuestDef->GetSingleLineDescription();
	PC->GetXPComponent()->GetRestXP() += XPEventEntry.EventXpValue;
	PC->GetXPComponent()->GetInMatchProfileVer()++;
	PC->GetXPComponent()->OnInMatchProfileUpdate(PC->GetXPComponent()->GetInMatchProfileVer());
	PC->GetXPComponent()->OnProfileUpdated();
	PC->GetXPComponent()->OnXpUpdated(PC->GetXPComponent()->GetCombatXp(), PC->GetXPComponent()->GetSurvivalXp(), PC->GetXPComponent()->GetMedalBonusXP(), PC->GetXPComponent()->GetChallengeXp(), PC->GetXPComponent()->GetMatchXp(), PC->GetXPComponent()->GetTotalXpEarned());
	PC->GetXPComponent()->GetWaitingQuestXp().Add(XPEventEntry);
	PC->GetXPComponent()->HighPrioXPEvent(XPEventEntry);
}

void AFortPlayerControllerAthena::StartGhostModeHook(UObject* Context, FFrame* Stack, void* Ret)
{
	LOG_INFO(LogDev, __FUNCTION__);

	auto PlayerController = (AFortPlayerControllerAthena*)Context;

	UFortWorldItemDefinition* ItemProvidingGhostMode = nullptr;

	Stack->StepCompiledIn(&ItemProvidingGhostMode);

	if (!ItemProvidingGhostMode)
	{
		LOG_INFO(LogDev, "Null item!");
		return StartGhostModeOriginal(Context, Stack, Ret);
	}

	if (!PlayerController->HasAuthority()) // for real
		return StartGhostModeOriginal(Context, Stack, Ret);
	
	LOG_INFO(LogDev, "Attempting to give item {}", ItemProvidingGhostMode->IsValidLowLevel() ? ItemProvidingGhostMode->GetFullName() : "BadRead");

	auto GhostModeRepData = PlayerController->GetGhostModeRepData();

	if (GhostModeRepData->IsInGhostMode())
	{
		LOG_INFO(LogDev, "Player is already in ghost mode!");
		return StartGhostModeOriginal(Context, Stack, Ret);
	}

	auto WorldInventory = PlayerController->GetWorldInventory();
	
	if (!WorldInventory)
		return StartGhostModeOriginal(Context, Stack, Ret);

	auto PickaxeInstance = WorldInventory->GetPickaxeInstance();

	// LOG_INFO(LogDev, "PickaxeInstance: {}", __int64(PickaxeInstance));

	if (PickaxeInstance)
	{
		WorldInventory->RemoveItem(PickaxeInstance->GetItemEntry()->GetItemGuid(), nullptr, REMOVE_ALL_ITEMS, true);
		// WorldInventory->Update();
	}

	bool bShouldUpdate = false;
	auto NewAndModifiedInstances = WorldInventory->AddItem(ItemProvidingGhostMode, &bShouldUpdate, 1);
	auto GhostModeItemInstance = NewAndModifiedInstances.first[0];

	if (!GhostModeItemInstance)
		return StartGhostModeOriginal(Context, Stack, Ret);

	// if (bShouldUpdate)
	WorldInventory->Update();

	PlayerController->AddPickaxeToInventory();
	WorldInventory->Update();

	PlayerController->ServerExecuteInventoryItemHook(PlayerController, GhostModeItemInstance->GetItemEntry()->GetItemGuid());
	PlayerController->ClientEquipItem(GhostModeItemInstance->GetItemEntry()->GetItemGuid(), true);
	LOG_INFO(LogDev, "Finished!");

	return StartGhostModeOriginal(Context, Stack, Ret);
}

void AFortPlayerControllerAthena::EndGhostModeHook(AFortPlayerControllerAthena* PlayerController)
{
	// I believe there are a lot of other places we should remove it (go to XREFs of K2_RemoveItemFromPlayer on a version like 6.21, and there will be something checking ghost stuff).

	LOG_INFO(LogDev, __FUNCTION__);

	if (!PlayerController->HasAuthority()) // for real
		return EndGhostModeOriginal(PlayerController);

	auto WorldInventory = PlayerController->GetWorldInventory();

	if (!WorldInventory)
		return EndGhostModeOriginal(PlayerController);

	FGhostModeRepData* GhostModeRepData = PlayerController->GetGhostModeRepData();
	UFortWorldItemDefinition* GhostModeItemDef = GhostModeRepData->GetGhostModeItemDef();

	LOG_INFO(LogDev, "GhostModeItemDef: {}", GhostModeItemDef->IsValidLowLevel() ? GhostModeItemDef->GetFullName() : "BadRead");

	if (!GhostModeItemDef) // bro IDFK
	{
		GhostModeItemDef = FindObject<UFortWorldItemDefinition>("/Game/Athena/Items/Gameplay/SpookyMist/AGID_SpookyMist.AGID_SpookyMist");
	}

	if (!GhostModeItemDef)
		return EndGhostModeOriginal(PlayerController);

	auto GhostModeItemInstance = WorldInventory->FindItemInstance(GhostModeItemDef);

	LOG_INFO(LogDev, "GhostModeItemInstance: {}", GhostModeItemInstance->IsValidLowLevel() ? GhostModeItemInstance->GetFullName() : "BadRead");

	if (!GhostModeItemInstance)
		return EndGhostModeOriginal(PlayerController);

	auto PickaxeInstance = PlayerController->AddPickaxeToInventory();

	WorldInventory->ForceNetUpdate();
	PlayerController->ForceNetUpdate();

	bool bShouldUpdate = false;
	int Count = GhostModeItemInstance->GetItemEntry()->GetCount(); // 1
	bool bForceRemoval = true; // false
	WorldInventory->RemoveItem(GhostModeItemInstance->GetItemEntry()->GetItemGuid(), &bShouldUpdate, Count, bForceRemoval);

	// if (bShouldUpdate)
	WorldInventory->Update();

	if (PickaxeInstance)
	{
		PlayerController->ClientEquipItem(PickaxeInstance->GetItemEntry()->GetItemGuid(), true);
	}

	return EndGhostModeOriginal(PlayerController);
}

void AFortPlayerControllerAthena::EnterAircraftHook(UObject* PC, AActor* Aircraft)
{
	auto PlayerController = Cast<AFortPlayerController>(Engine_Version < 424 ? PC : ((UActorComponent*)PC)->GetOwner());
	
	if (!PlayerController)
		return;

	LOG_INFO(LogDev, "EnterAircraftHook");

	EnterAircraftOriginal(PC, Aircraft);

	// TODO Check if the player successfully got in the aircraft.

	auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());
	auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());

	auto WorldInventory = PlayerController->GetWorldInventory();

	if (!WorldInventory)
		return;

	std::vector<std::pair<FGuid, int>> GuidAndCountsToRemove;

	auto& InventoryList = WorldInventory->GetItemList();

	auto& ItemInstances = InventoryList.GetItemInstances();

	for (int i = 0; i < ItemInstances.Num(); ++i)
	{
		auto ItemEntry = ItemInstances.at(i)->GetItemEntry();
		auto ItemDefinition = Cast<UFortWorldItemDefinition>(ItemEntry->GetItemDefinition());

		if (!ItemDefinition)
			continue;

		if (!ItemDefinition->CanBeDropped())
			continue;

		GuidAndCountsToRemove.push_back({ ItemEntry->GetItemGuid(), ItemEntry->GetCount() });
	}

	for (auto& Pair : GuidAndCountsToRemove)
	{
		WorldInventory->RemoveItem(Pair.first, nullptr, Pair.second, true);
	}

	std::vector<std::pair<AFortAthenaMutator*, UFunction*>> FunctionsToCall;
	LoopMutators([&](AFortAthenaMutator* Mutator) { FunctionsToCall.push_back(std::make_pair(Mutator, Mutator->FindFunction("OnGamePhaseStepChanged"))); });

	auto HandleGiveItemsAtGamePhaseStepMutator = [&](AFortAthenaMutator* Mutator) {
		if (auto GiveItemsAtGamePhaseStepMutator = Cast<AFortAthenaMutator_GiveItemsAtGamePhaseStep>(Mutator))
		{
			auto PhaseToGive = GiveItemsAtGamePhaseStepMutator->GetPhaseToGiveItems();
			auto& ItemsToGive = GiveItemsAtGamePhaseStepMutator->GetItemsToGive();

			LOG_INFO(LogDev, "PhaseToGiveItems: {} ItemsToGive.Num(): {}", (int)PhaseToGive, ItemsToGive.Num());

			if (PhaseToGive <= 5) // Flying or lower
			{
				for (int j = 0; j < ItemsToGive.Num(); j++)
				{
					auto ItemToGive = ItemsToGive.AtPtr(j, FItemsToGive::GetStructSize());

					if (!ItemToGive->GetItemToDrop())
						continue;

					float Out2 = 0;

					if (!IsBadReadPtr(ItemToGive->GetNumberToGive().GetCurve().CurveTable, 8) && ItemToGive->GetNumberToGive().GetCurve().RowName.IsValid())
					{
						Out2 = UDataTableFunctionLibrary::EvaluateCurveTableRow(ItemToGive->GetNumberToGive().GetCurve().CurveTable, ItemToGive->GetNumberToGive().GetCurve().RowName, 0.f);
					}

					LOG_INFO(LogDev, "[{}] Out2: {} ItemToGive.ItemToDrop: {}", j, Out2, ItemToGive->GetItemToDrop()->IsValidLowLevel() ? ItemToGive->GetItemToDrop()->GetFullName() : "BadRead");

					if (!Out2) // ?
						continue;

					WorldInventory->AddItem(ItemToGive->GetItemToDrop(), nullptr, Out2);
				}
			}
		}
	};

	LoopMutators(HandleGiveItemsAtGamePhaseStepMutator);

	/* if (auto GGMutator = Cast<AFortAthenaMutator_GG>(Mutator))
	{
		auto& WeaponEntries = GGMutator->GetWeaponEntries();

		LOG_INFO(LogDev, "[{}] WeaponEntries.Num(): {}", i, WeaponEntries.Num());

		for (int j = 0; j < WeaponEntries.Num(); j++)
		{
			WorldInventory->AddItem(WeaponEntries.at(j).Weapon, nullptr, 1);
		}
	} */

	auto PlayerStateAthena = Cast<AFortPlayerStateAthena>(PlayerController->GetPlayerState());

	auto AddInventoryOverrideTeamLoadouts = [&](AFortAthenaMutator* Mutator)
	{
		if (auto InventoryOverride = Cast<AFortAthenaMutator_InventoryOverride>(Mutator))
		{
			auto TeamIndex = PlayerStateAthena->GetTeamIndex();
			auto LoadoutTeam = InventoryOverride->GetLoadoutTeamForTeamIndex(TeamIndex);

			if (LoadoutTeam.UpdateOverrideType == EAthenaInventorySpawnOverride::AircraftPhaseOnly)
			{
				auto LoadoutContainer = InventoryOverride->GetLoadoutContainerForTeamIndex(TeamIndex);

				for (int i = 0; i < LoadoutContainer.Loadout.Num(); ++i)
				{
					auto& ItemAndCount = LoadoutContainer.Loadout.at(i);
					WorldInventory->AddItem(ItemAndCount.GetItem(), nullptr, ItemAndCount.GetCount());
				}
			}
		}
	};

	LoopMutators(AddInventoryOverrideTeamLoadouts);

	if (Globals::bTeamRumble)
	{
		static UFortWeaponItemDefinition* ArDef = FindObject<UFortWeaponItemDefinition>("/Game/Athena/Items/Weapons/WID_Assault_Auto_Athena_UC_Ore_T03.WID_Assault_Auto_Athena_UC_Ore_T03");
		static UFortWeaponItemDefinition* PumpDef = FindObject<UFortWeaponItemDefinition>("/Game/Athena/Items/Weapons/WID_Shotgun_Standard_Athena_C_Ore_T03.WID_Shotgun_Standard_Athena_C_Ore_T03");

		WorldInventory->AddItem(PumpDef, nullptr, 1, 5);
		WorldInventory->AddItem(ArDef, nullptr, 1, 30);
		WorldInventory->AddItem(PumpDef->GetAmmoWorldItemDefinition_BP(), nullptr, 15);
		WorldInventory->AddItem(ArDef->GetAmmoWorldItemDefinition_BP(), nullptr, 60);
	}

	if (Globals::bArsenal)
	{
		static UFortItemDefinition* WoodDef = FindObject<UFortItemDefinition>("/Game/Items/ResourcePickups/WoodItemData.WoodItemData");
		static UFortItemDefinition* StoneDef = FindObject<UFortItemDefinition>("/Game/Items/ResourcePickups/StoneItemData.StoneItemData");
		static UFortItemDefinition* MetalDef = FindObject<UFortItemDefinition>("/Game/Items/ResourcePickups/MetalItemData.MetalItemData");

		WorldInventory->AddItem(WoodDef, nullptr, 9999);
		WorldInventory->AddItem(StoneDef, nullptr, 9999);
		WorldInventory->AddItem(MetalDef, nullptr, 9999);

		AFortAthenaMutator_GG* Mutator = (AFortAthenaMutator_GG*)GameState->GetMutatorByClass(GameMode, AFortAthenaMutator_GG::StaticClass());

		if (Mutator && Mutator->GetWeaponEntries()[0].GetWeapon())
		{
			WorldInventory->AddItem(Mutator->GetWeaponEntries()[0].GetWeapon(), nullptr, 1, Cast<UFortWeaponItemDefinition>(Mutator->GetWeaponEntries()[0].GetWeapon())->GetClipSize());
		}
	}

	if (Globals::bStormKing)
	{
		static UFortItemDefinition* WoodDef = FindObject<UFortItemDefinition>("/Game/Items/ResourcePickups/WoodItemData.WoodItemData");
		static UFortItemDefinition* StoneDef = FindObject<UFortItemDefinition>("/Game/Items/ResourcePickups/StoneItemData.StoneItemData");
		static UFortItemDefinition* MetalDef = FindObject<UFortItemDefinition>("/Game/Items/ResourcePickups/MetalItemData.MetalItemData");
		static UFortWeaponItemDefinition* ScarDef = FindObject<UFortWeaponItemDefinition>("/Game/Athena/Items/Weapons/Boss/WID_Boss_Adventure_AR.WID_Boss_Adventure_AR");
		static UFortWeaponItemDefinition* DrumgunDef = FindObject<UFortWeaponItemDefinition>("/Game/Athena/Items/Weapons/Boss/WID_Boss_Midas.WID_Boss_Midas");
		static UFortWeaponItemDefinition* SlurpFishDef = FindObject<UFortWeaponItemDefinition>("/Game/Athena/Items/Consumables/Flopper/Effective/WID_Athena_Flopper_Effective.WID_Athena_Flopper_Effective");
		static UFortWeaponItemDefinition* SmallShieldDef = FindObject<UFortWeaponItemDefinition>("/Game/Athena/Items/Consumables/ShieldSmall/Athena_ShieldSmall.Athena_ShieldSmall");

		static UFortWeaponItemDefinition* GraveDiggerDef = FindObject<UFortWeaponItemDefinition>("/Game/Items/Weapons/Ranged/Assault/Auto/WID_Assault_Auto_Halloween_SR_Ore_T01.WID_Assault_Auto_Halloween_SR_Ore_T01");
		static UFortWeaponItemDefinition* NocturnoDef = FindObject<UFortWeaponItemDefinition>("/Game/Items/Weapons/Ranged/Assault/Auto_High/WID_Assault_Auto_Founders_SR_Ore_T05.WID_Assault_Auto_Founders_SR_Ore_T05");
		static UFortWeaponItemDefinition* MeleeDef1 = FindObject<UFortWeaponItemDefinition>("/Game/Items/Weapons/Melee/Edged/Sword_NeonGlow/WID_Edged_Sword_NeonGlow_SR_Ore_T05.WID_Edged_Sword_NeonGlow_SR_Ore_T05");
		static UFortWeaponItemDefinition* MeleeDef2 = FindObject<UFortWeaponItemDefinition>("/Game/Items/Weapons/Melee/Edged/Sword_Medium_Laser/WID_Edged_Sword_Medium_Laser_Founders_SR_Crystal_T05.WID_Edged_Sword_Medium_Laser_Founders_SR_Crystal_T05");

		WorldInventory->AddItem(WoodDef, nullptr, 9999);
		WorldInventory->AddItem(StoneDef, nullptr, 9999);
		WorldInventory->AddItem(MetalDef, nullptr, 9999);
		//WorldInventory->AddItem(ScarDef, nullptr, 1, 30);
		//WorldInventory->AddItem(GraveDiggerDef, nullptr, 1, 0, 144);
		//WorldInventory->AddItem(NocturnoDef, nullptr, 1, 0, 86);
		WorldInventory->AddItem(SlurpFishDef, nullptr, 3);
		WorldInventory->AddItem(SmallShieldDef, nullptr, 6);
		//WorldInventory->AddItem(MeleeDef1, nullptr, 1);
		//WorldInventory->AddItem(MeleeDef2, nullptr, 1);
		WorldInventory->AddItem(ScarDef, nullptr, 1, 30);
		WorldInventory->AddItem(DrumgunDef, nullptr, 1, 40);
		//WorldInventory->AddItem(NocturnoDef->GetAmmoWorldItemDefinition_BP(), nullptr, 9999);
		//WorldInventory->AddItem(GraveDiggerDef->GetAmmoWorldItemDefinition_BP(), nullptr, 9999);
		WorldInventory->AddItem(ScarDef->GetAmmoWorldItemDefinition_BP(), nullptr, 9999);

		auto Aircraft = GameState->GetAircraft(0);
		auto PoiManager = GameState->GetPoiManager();

		if (PoiManager)
		{
			Aircraft->GetFlightInfo().GetFlightSpeed() = 1500.f;
			FVector Loc = (GameState->GetPoiManager()->GetAllPoiVolumes()[0]->GetActorLocation() - (GameState->GetPoiManager()->GetAllPoiVolumes()[0]->GetActorForwardVector() * 5000));
			Loc.Z = 15000;
			Aircraft->GetFlightInfo().GetFlightStartLocation() = (FVector_NetQuantize100)Loc;
			BusLocation = GameState->GetPoiManager()->GetAllPoiVolumes()[0]->GetActorLocation();
			BusLocation.Z = 0;
		}
	}

	if (Globals::bTravis)
	{
		LOG_INFO(LogGame, "Travis!!!");

		//X: 62590.7 Y : -75501.8 Z : 13982.4
		auto Aircraft = GameState->GetAircraft(0);
		FVector Loc = FVector(62590, -75501, 13982);
		Aircraft->GetFlightInfo().GetFlightStartLocation() = (FVector_NetQuantize100)Loc;
		Aircraft->GetFlightInfo().GetFlightSpeed() = 1000;
		Aircraft->GetFlightInfo().GetTimeTillDropStart() = 1;
		Aircraft->GetDropStartTime() = UGameplayStatics::GetTimeSeconds(GetWorld()) + 1;
		GameState->AircraftIsLocked() = false;
		BusLocation = Loc;
	}

	WorldInventory->Update();
	
	// Should we equip the pickaxe for older builds here?

	if (Fortnite_Version < 2.5) // idk
	{
		/* auto PickaxeInstance = WorldInventory->GetPickaxeInstance();

		if (!PickaxeInstance)
			return;
				
		AFortPlayerController::ServerExecuteInventoryItemHook(PlayerController, PickaxeInstance->GetItemEntry()->GetItemGuid()); */
	}
}

void AFortPlayerControllerAthena::ServerRequestSeatChangeHook(AFortPlayerControllerAthena* PlayerController, int TargetSeatIndex)
{
	auto Pawn = Cast<AFortPlayerPawn>(PlayerController->GetPawn());
	
	if (!Pawn)
		return ServerRequestSeatChangeOriginal(PlayerController, TargetSeatIndex);

	auto Vehicle = Pawn->GetVehicle();

	if (!Vehicle)
		return ServerRequestSeatChangeOriginal(PlayerController, TargetSeatIndex);

	auto OldVehicleWeaponDefinition = Pawn->GetVehicleWeaponDefinition(Vehicle);
	
	LOG_INFO(LogDev, "OldVehicleWeaponDefinition: {}", OldVehicleWeaponDefinition ? OldVehicleWeaponDefinition->GetFullName() : "BadRead");

	if (!OldVehicleWeaponDefinition)
		return ServerRequestSeatChangeOriginal(PlayerController, TargetSeatIndex);

	auto WorldInventory = PlayerController->GetWorldInventory();

	if (!WorldInventory)
		return ServerRequestSeatChangeOriginal(PlayerController, TargetSeatIndex);

	auto OldVehicleWeaponInstance = WorldInventory->FindItemInstance(OldVehicleWeaponDefinition);

	if (OldVehicleWeaponInstance)
	{
		bool bShouldUpdate = false;
		WorldInventory->RemoveItem(OldVehicleWeaponInstance->GetItemEntry()->GetItemGuid(), &bShouldUpdate, OldVehicleWeaponInstance->GetItemEntry()->GetCount(), true);

		if (bShouldUpdate)
			WorldInventory->Update();
	}

	auto RequestingVehicleWeaponDefinition = Vehicle->GetVehicleWeaponForSeat(TargetSeatIndex);

	if (!RequestingVehicleWeaponDefinition)
	{
		auto PickaxeInstance = WorldInventory->GetPickaxeInstance();

		if (!PickaxeInstance)
			return ServerRequestSeatChangeOriginal(PlayerController, TargetSeatIndex);

		AFortPlayerController::ServerExecuteInventoryItemHook(PlayerController, PickaxeInstance->GetItemEntry()->GetItemGuid()); // Bad, we should equip the last weapon.
		return ServerRequestSeatChangeOriginal(PlayerController, TargetSeatIndex);
	}

	auto NewAndModifiedInstances = WorldInventory->AddItem(RequestingVehicleWeaponDefinition, nullptr);
	auto RequestedVehicleInstance = NewAndModifiedInstances.first[0];

	if (!RequestedVehicleInstance)
		return ServerRequestSeatChangeOriginal(PlayerController, TargetSeatIndex);

	WorldInventory->Update();

	auto RequestedVehicleWeapon = Pawn->EquipWeaponDefinition(RequestingVehicleWeaponDefinition, RequestedVehicleInstance->GetItemEntry()->GetItemGuid());

	return ServerRequestSeatChangeOriginal(PlayerController, TargetSeatIndex);
}

void AFortPlayerControllerAthena::ServerRestartPlayerHook(AFortPlayerControllerAthena* Controller)
{
	static auto FortPlayerControllerZoneDefault = FindObject<UClass>(L"/Script/FortniteGame.Default__FortPlayerControllerZone");
	static auto ServerRestartPlayerFn = FindObject<UFunction>(L"/Script/Engine.PlayerController.ServerRestartPlayer");
	static auto ZoneServerRestartPlayer = __int64(FortPlayerControllerZoneDefault->VFTable[GetFunctionIdxOrPtr(ServerRestartPlayerFn) / 8]);
	static void (*ZoneServerRestartPlayerOriginal)(AFortPlayerController*) = decltype(ZoneServerRestartPlayerOriginal)(__int64(ZoneServerRestartPlayer));
	
	LOG_INFO(LogDev, "ServerRestartPlayerHook Call 0x{:x} returning with 0x{:x}!", ZoneServerRestartPlayer - __int64(_ReturnAddress()), __int64(ZoneServerRestartPlayerOriginal) - __int64(GetModuleHandleW(0)));
	return ZoneServerRestartPlayerOriginal(Controller);
}

void AFortPlayerControllerAthena::ServerGiveCreativeItemHook(AFortPlayerControllerAthena* Controller, FFortItemEntry CreativeItem)
{
	// Don't worry, the validate has a check if it is a creative enabled mode or not, but we need to add a volume check and permission check I think.

	auto CreativeItemPtr = &CreativeItem;
	auto ItemDefinition = CreativeItemPtr->GetItemDefinition();

	if (!ItemDefinition)
		return;

	bool bShouldUpdate = false;
	auto LoadedAmmo = -1; // CreativeItemPtr->GetLoadedAmmo()
	Controller->GetWorldInventory()->AddItem(ItemDefinition, &bShouldUpdate, CreativeItemPtr->GetCount(), LoadedAmmo, false);

	if (bShouldUpdate)
		Controller->GetWorldInventory()->Update(Controller);
}

void AFortPlayerControllerAthena::ServerTeleportToPlaygroundLobbyIslandHook(AFortPlayerControllerAthena* Controller)
{
	LOG_INFO(LogDev, "ServerTeleportToPlaygroundLobbyIslandHook!");

	auto Pawn = Controller->GetMyFortPawn();

	if (!Pawn)
		return;

	// TODO IsTeleportToCreativeHubAllowed

	static auto FortPlayerStartCreativeClass = FindObject<UClass>(L"/Script/FortniteGame.FortPlayerStartCreative");
	auto AllCreativePlayerStarts = UGameplayStatics::GetAllActorsOfClass(GetWorld(), FortPlayerStartCreativeClass);

	for (int i = 0; i < AllCreativePlayerStarts.Num(); ++i)
	{
		auto CurrentPlayerStart = AllCreativePlayerStarts.at(i);

		static auto PlayerStartTagsOffset = CurrentPlayerStart->GetOffset("PlayerStartTags");
		auto bHasSpawnTag = CurrentPlayerStart->Get<FGameplayTagContainer>(PlayerStartTagsOffset).Contains("Playground.LobbyIsland.Spawn");

		if (!bHasSpawnTag)
			continue;

		Pawn->TeleportTo(CurrentPlayerStart->GetActorLocation(), Pawn->GetActorRotation());
		break;
	}

	AllCreativePlayerStarts.Free();
}

void AFortPlayerControllerAthena::ServerAcknowledgePossessionHook(APlayerController* Controller, APawn* Pawn)
{
	static auto AcknowledgedPawnOffset = Controller->GetOffset("AcknowledgedPawn");

	const APawn* OldAcknowledgedPawn = Controller->Get<APawn*>(AcknowledgedPawnOffset);
	Controller->Get<APawn*>(AcknowledgedPawnOffset) = Pawn;

	auto ControllerAsFort = Cast<AFortPlayerController>(Controller);
	auto PawnAsFort = Cast<AFortPlayerPawn>(Pawn);
	auto PlayerStateAsFort = Cast<AFortPlayerState>(Pawn->GetPlayerState());

	if (!PawnAsFort)
		return;

	if (OldAcknowledgedPawn != PawnAsFort)
	{
		PawnAsFort->SetShield(StartingShield);
	}

	if (Globals::bNoMCP)
	{
		static auto CustomCharacterPartClass = FindObject<UClass>("/Script/FortniteGame.CustomCharacterPart");
		static auto backpackPart = LoadObject("/Game/Characters/CharacterParts/Backpacks/NoBackpack.NoBackpack", CustomCharacterPartClass);

		// PawnAsFort->ServerChoosePart(EFortCustomPartType::Backpack, backpackPart);

		return;
	}

	ControllerAsFort->ApplyCosmeticLoadout();
}

void AFortPlayerControllerAthena::ServerPlaySquadQuickChatMessageHook(AFortPlayerControllerAthena* PlayerController, __int64 ChatEntry, __int64 SenderID)
{
	using UAthenaEmojiItemDefinition = UFortItemDefinition;

	auto PlayerStateAthena = Cast<AFortPlayerStateAthena>(PlayerController->GetPlayerState());

	if (!PlayerStateAthena)
		return;

	static auto IndexOffset = FindOffsetStruct("/Script/FortniteGame.AthenaQuickChatActiveEntry", "Index");
	auto Index = *(int8*)(__int64(ChatEntry) + IndexOffset);

	LOG_INFO(LogDev, "Index: {}", (int)Index);

	uint8 NewTeamMemberState = 0;

	switch (Index)
	{
	case 0:
		NewTeamMemberState = 8;
		break;
	case 1:
		NewTeamMemberState = 9;
		break;
	case 2:
		NewTeamMemberState = 11;
		break;
	case 3:
		NewTeamMemberState = 10;
		break;
	case 4:
		NewTeamMemberState = 12;
		break;
	case 5:
		NewTeamMemberState = 3;
		break;
	case 6:
		NewTeamMemberState = 4;
		break;
	case 7:
		NewTeamMemberState = 2;
		break;
	case 8:
		NewTeamMemberState = 5;
		break;
	case 9:
		NewTeamMemberState = 6;
		break;
	default:
		break;
	}

	NewTeamMemberState -= AmountToSubtractIndex;

	PlayerStateAthena->Get<uint8_t>("ReplicatedTeamMemberState") = NewTeamMemberState;
	PlayerStateAthena->Get<uint8_t>("TeamMemberState") = NewTeamMemberState; // pretty sure unneeded

	static auto EmojiComm = FindObject<UAthenaEmojiItemDefinition>(L"/Game/Athena/Items/Cosmetics/Dances/Emoji/Emoji_Comm.Emoji_Comm");
	PlayerController->ServerPlayEmoteItemHook(PlayerController, EmojiComm);

	static auto OnRep_ReplicatedTeamMemberStateFn = FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerStateAthena.OnRep_ReplicatedTeamMemberState");
	PlayerStateAthena->ProcessEvent(OnRep_ReplicatedTeamMemberStateFn);
}

void AFortPlayerControllerAthena::GetPlayerViewPointHook(AFortPlayerControllerAthena* PlayerController, FVector& Location, FRotator& Rotation)
{
	// I don't know why but GetActorEyesViewPoint only works on some versions.
	/* static auto GetActorEyesViewPointFn = FindObject<UFunction>(L"/Script/Engine.Actor.GetActorEyesViewPoint");
	static auto GetActorEyesViewPointIndex = GetFunctionIdxOrPtr(GetActorEyesViewPointFn) / 8;

	void (*GetActorEyesViewPointOriginal)(AActor* Actor, FVector* OutLocation, FRotator* OutRotation) = decltype(GetActorEyesViewPointOriginal)(PlayerController->VFTable[GetActorEyesViewPointIndex]);
	return GetActorEyesViewPointOriginal(PlayerController, &Location, &Rotation); */

	if (auto MyFortPawn = PlayerController->GetMyFortPawn())
	{
		Location = MyFortPawn->GetActorLocation();
		Rotation = PlayerController->GetControlRotation();
		return;
	}

	return AFortPlayerControllerAthena::GetPlayerViewPointOriginal(PlayerController, Location, Rotation);
}

void AFortPlayerControllerAthena::ServerReadyToStartMatchHook(AFortPlayerControllerAthena* PlayerController)
{
	LOG_INFO(LogDev, "ServerReadyToStartMatch!");

	if (Fortnite_Version <= 2.5) // techinally we should do this at the end of OnReadyToStartMatch
	{
		static auto QuickBarsOffset = PlayerController->GetOffset("QuickBars", false);

		if (QuickBarsOffset != -1)
		{
			auto& QuickBars = PlayerController->Get<AActor*>(QuickBarsOffset);

			// LOG_INFO(LogDev, "QuickBarsOld: {}", __int64(QuickBars));

			if (QuickBars)
				return ServerReadyToStartMatchOriginal(PlayerController);

			static auto FortQuickBarsClass = FindObject<UClass>("/Script/FortniteGame.FortQuickBars");

			QuickBars = GetWorld()->SpawnActor<AActor>(FortQuickBarsClass);

			// LOG_INFO(LogDev, "QuickBarsNew: {}", __int64(QuickBars));

			if (!QuickBars)
				return ServerReadyToStartMatchOriginal(PlayerController);

			PlayerController->Get<AActor*>(QuickBarsOffset)->SetOwner(PlayerController);
		}
	}

	return ServerReadyToStartMatchOriginal(PlayerController);
}


void AFortPlayerControllerAthena::UpdateTrackedAttributesHook(AFortPlayerControllerAthena* PlayerController)
{
	LOG_INFO(LogDev, "UpdateTrackedAttributesHook Return: 0x{:x}", __int64(_ReturnAddress()) - __int64(GetModuleHandleW(0)));

	// IDK IF GADGET IS A PARAM OR WHAT

	auto PlayerState = Cast<AFortPlayerStateAthena>(PlayerController->GetPlayerState()); // really we only need zone

	if (!PlayerState)
		return;

	auto ASC = PlayerState->GetAbilitySystemComponent();

	if (!ASC)
		return;

	auto WorldInventory = PlayerController->GetWorldInventory();

	if (!WorldInventory)
		return;

	auto& ItemInstances = WorldInventory->GetItemList().GetItemInstances();

	std::vector<UFortItem*> ItemInstancesToRemove;

	for (int i = 0; i < ItemInstances.Num(); ++i)
	{
		auto ItemInstance = ItemInstances.at(i);
		auto GadgetItemDefinition = Cast<UFortGadgetItemDefinition>(ItemInstance->GetItemEntry()->GetItemDefinition());

		if (!GadgetItemDefinition)
			continue;

		if (!GadgetItemDefinition->ShouldDestroyGadgetWhenTrackedAttributesIsZero())
			continue;

		bool bIsTrackedAttributesZero = true;

		for (int i = 0; i < GadgetItemDefinition->GetTrackedAttributes().Num(); ++i)
		{
			auto& CurrentTrackedAttribute = GadgetItemDefinition->GetTrackedAttributes().at(i);

			int CurrentAttributeValue = -1;

			for (int i = 0; i < ASC->GetSpawnedAttributes().Num(); ++i)
			{
				auto CurrentSpawnedAttribute = ASC->GetSpawnedAttributes().at(i);

				if (CurrentSpawnedAttribute->IsA(CurrentTrackedAttribute.AttributeOwner))
				{
					auto PropertyOffset = CurrentSpawnedAttribute->GetOffset(CurrentTrackedAttribute.GetAttributePropertyName());

					if (PropertyOffset != -1)
					{
						if (CurrentSpawnedAttribute->GetPtr<FFortGameplayAttributeData>(PropertyOffset)->GetCurrentValue() > 0)
						{
							bIsTrackedAttributesZero = false;
							break; // hm
						}
					}
				}
			}
		}

		if (bIsTrackedAttributesZero)
		{
			ItemInstancesToRemove.push_back(ItemInstance);
		}
	}

	for (auto ItemInstanceToRemove : ItemInstancesToRemove)
	{
		auto GadgetItemDefinition = Cast<UFortGadgetItemDefinition>(ItemInstanceToRemove->GetItemEntry()->GetItemDefinition());

		WorldInventory->RemoveItem(ItemInstanceToRemove->GetItemEntry()->GetItemGuid(), nullptr, ItemInstanceToRemove->GetItemEntry()->GetCount(), true);

		static auto MulticastTriggerOnGadgetTrackedAttributeDestroyedFXFn = FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerStateZone.MulticastTriggerOnGadgetTrackedAttributeDestroyedFX");
		PlayerState->ProcessEvent(MulticastTriggerOnGadgetTrackedAttributeDestroyedFXFn, &GadgetItemDefinition);
	}

	if (ItemInstancesToRemove.size() > 0)
		WorldInventory->Update();
}