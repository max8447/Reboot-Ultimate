#pragma once

#include "FortGameModeAthena.h"
#include "FortAthenaAIBotController.h"
#include "FortAIPawn.h"
#include "FortServerBotManagerAthena.h"
#include "FortAthenaAIBotCustomizationData.h"
#include "FortAthenaAISpawnerData.h"
#include "KismetTextLibrary.h"
#include "KismetMathLibrary.h"
#include "FortBotNameSettings.h"
#include "AIStimulus.h"
#include "FortAthenaNpcPatrollingComponent.h"

#include "botnames.h"

inline UFortServerBotManagerAthena* BotManager = nullptr;

class PlayerBot
{
public:
	AController* Controller = nullptr;
	AFortAthenaAIBotController* AIBotController = nullptr;
	AFortPlayerPawnAthena* Pawn = nullptr;
	AFortPlayerStateAthena* PlayerState = nullptr;

public:

	static bool ShouldUseAIBotController()
	{
		return Fortnite_Version >= 11 && Engine_Version < 500;
	}

	void PickRandomLoadout()
	{
		auto AllHeroTypes = GetAllObjectsOfClass(FindObject<UClass>(L"/Script/FortniteGame.FortHeroType"));
		std::vector<UFortItemDefinition*> AthenaHeroTypes;

		UFortItemDefinition* HeroType = FindObject<UFortItemDefinition>(L"/Game/Athena/Heroes/HID_030_Athena_Commando_M_Halloween.HID_030_Athena_Commando_M_Halloween");

		for (int i = 0; i < AllHeroTypes.size(); ++i)
		{
			auto CurrentHeroType = (UFortItemDefinition*)AllHeroTypes.at(i);

			if (CurrentHeroType->GetPathName().starts_with("/Game/Athena/Heroes/"))
				AthenaHeroTypes.push_back(CurrentHeroType);
		}

		if (AthenaHeroTypes.size())
		{
			HeroType = AthenaHeroTypes.at(UKismetMathLibrary::RandomIntegerInRange(0, AthenaHeroTypes.size() - 1));
		}

		static auto HeroTypeOffset = PlayerState->GetOffset("HeroType");
		PlayerState->Get(HeroTypeOffset) = HeroType;
	}

	void ApplyCosmeticLoadout()
	{
		static auto HeroTypeOffset = PlayerState->GetOffset("HeroType");
		const auto CurrentHeroType = PlayerState->Get(HeroTypeOffset);

		if (!CurrentHeroType)
		{
			LOG_WARN(LogBots, "CurrentHeroType called with an invalid HeroType!");
			return;
		}

		ApplyHID(Pawn, CurrentHeroType, true);
	}

	void SetupInventory()
	{
		if (!ShouldUseAIBotController())
		{
			AFortInventory** Inventory = nullptr;

			if (auto FortPlayerController = Cast<AFortPlayerController>(Controller))
			{
				Inventory = &FortPlayerController->GetWorldInventory();
			}
			else
			{
				if (Controller->IsA(AFortAthenaAIBotController::StaticClass()))
				{
					static auto InventoryOffset = Controller->GetOffset("Inventory");
					Inventory = Controller->GetPtr<AFortInventory*>(InventoryOffset);
				}
			}

			if (!Inventory)
			{
				LOG_ERROR(LogBots, "No inventory pointer!");

				Pawn->K2_DestroyActor();
				Controller->K2_DestroyActor();
				return;
			}

			FTransform InventorySpawnTransform{};

			static auto FortInventoryClass = FindObject<UClass>(L"/Script/FortniteGame.FortInventory"); // AFortInventory::StaticClass()
			*Inventory = GetWorld()->SpawnActor<AFortInventory>(FortInventoryClass, InventorySpawnTransform, CreateSpawnParameters(ESpawnActorCollisionHandlingMethod::AlwaysSpawn, false, Controller));

			if (!*Inventory)
			{
				LOG_ERROR(LogBots, "Failed to spawn Inventory!");

				Pawn->K2_DestroyActor();
				Controller->K2_DestroyActor();
				return;
			}

			(*Inventory)->GetInventoryType() = EFortInventoryType::World;

			if (auto FortPlayerController = Cast<AFortPlayerController>(Controller))
			{
				static auto bHasInitializedWorldInventoryOffset = FortPlayerController->GetOffset("bHasInitializedWorldInventory");
				FortPlayerController->Get<bool>(bHasInitializedWorldInventoryOffset) = true;
			}
		}
	}

	void ChangeName()
	{
		bool bUseOverrideName = false;

		FString NewName;

		if (bUseOverrideName)
		{
			NewName = L"Override";
		}
		else
		{
			static int CurrentBotNum = 1;
			std::wstring BotNumWStr;

			if (Fortnite_Version < 9)
			{
				BotNumWStr = std::to_wstring(CurrentBotNum++);
				NewName = (L"RebootBot" + BotNumWStr).c_str();

				if (auto PlayerController = Cast<AFortPlayerController>(Controller))
					PlayerController->ServerChangeName(NewName);
			}
			else
			{
				if (Fortnite_Version < 11)
				{
					BotNumWStr = std::to_wstring(CurrentBotNum++ + 200);
					NewName = (std::format(L"Anonymous[{}]", BotNumWStr)).c_str();
				}
				else
				{
					if (!PlayerBotNames.empty())
					{
						int RandomIndex = std::rand() % PlayerBotNames.size();
						std::string RandomBotName = PlayerBotNames[RandomIndex];
						NewName = std::wstring(RandomBotName.begin(), RandomBotName.end()).c_str();
						PlayerBotNames.erase(PlayerBotNames.begin() + RandomIndex);
					}
				}

				PlayerState->SetPlayerName(NewName);
			}
		}

		LOG_INFO(LogBots, "NewName: {}", NewName.ToString());
	}

public:

	void Initialize(const FTransform& SpawnTransform, AActor* SpawnActor = nullptr)
	{
		auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

		static UClass* PawnClass = nullptr;
		static UClass* ControllerClass = nullptr;

		if (!ShouldUseAIBotController())
		{
			if (!PawnClass)
				PawnClass = FindObject<UClass>(L"/Game/Athena/PlayerPawn_Athena.PlayerPawn_Athena_C");

			if (!ControllerClass)
				ControllerClass = AFortPlayerControllerAthena::StaticClass();

			if (!ControllerClass || !PawnClass)
			{
				LOG_ERROR(LogBots, "Failed to find a class for the bots!");
				return;
			}

			Controller = GetWorld()->SpawnActor<AController>(ControllerClass);
			Pawn = GetWorld()->SpawnActor<AFortPlayerPawnAthena>(PawnClass, SpawnTransform, CreateSpawnParameters(ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn));
			PlayerState = Cast<AFortPlayerStateAthena>(Controller->GetPlayerState());

			if (!Pawn || !PlayerState)
				return;

			PlayerState->OnRep_PlayerName();
			Controller->Possess(Pawn);
		}
		else
		{
			if (!PawnClass)
				PawnClass = LoadObject<UClass>(L"/Game/Athena/AI/Phoebe/BP_PlayerPawn_Athena_Phoebe.BP_PlayerPawn_Athena_Phoebe_C", BGACLASS);

			if (!SpawnActor)
				return;

			Pawn = BotManager->GetCachedBotMutator()->SpawnBot(PawnClass, SpawnActor, SpawnTransform.Translation, SpawnTransform.Rotation.Rotator(), false);

			if (Fortnite_Version < 17)
				AIBotController = Cast<AFortAthenaAIBotController>(Pawn->GetController());
			else
				AIBotController = GetWorld()->SpawnActor<AFortAthenaAIBotController>(Pawn->GetAIControllerClass());

			PlayerState = Cast<AFortPlayerStateAthena>(AIBotController->GetPlayerState());
		}

		if (Fortnite_Version >= 20)
			LOG_INFO(LogBots, "Bot spawned at {}", Pawn->GetActorLocation().ToString().ToString());

		ChangeName();

		if (Addresses::PickTeam)
			PlayerState->GetTeamIndex() = GameMode->Athena_PickTeamHook(GameMode, 0, Controller ? Controller : AIBotController);

		static auto SquadIdOffset = PlayerState->GetOffset("SquadId", false);

		if (SquadIdOffset != -1)
			PlayerState->GetSquadId() = PlayerState->GetTeamIndex() - NumToSubtractFromSquadId;

		GameState->AddPlayerStateToGameMemberInfo(PlayerState);

		PlayerState->SetIsBot(true);

		Pawn->SetHealth(21);
		Pawn->SetMaxHealth(21);
		Pawn->SetShield(21);

		auto PlayerAbilitySet = GetPlayerAbilitySet();
		auto AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();

		if (PlayerAbilitySet)
		{
			PlayerAbilitySet->GiveToAbilitySystem(AbilitySystemComponent);
		}

		SetupInventory();
		PickRandomLoadout();
		ApplyCosmeticLoadout();

		if (!ShouldUseAIBotController())
		{
			GameState->GetPlayersLeft()++;
			GameState->OnRep_PlayersLeft();

			if (auto FortPlayerControllerAthena = Cast<AFortPlayerControllerAthena>(Controller))
				GameMode->GetAlivePlayers().Add(FortPlayerControllerAthena);
		}
	}

public:

	virtual void OnDied(AFortPlayerStateAthena* KillerState = nullptr)
	{
		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());
		auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
		AFortPlayerControllerAthena* KillerController = nullptr;
		AFortPawn* KillerPawn = nullptr;

		if (KillerState)
		{
			KillerController = Cast<AFortPlayerControllerAthena>(KillerState->GetOwner());

			if (KillerController)
				KillerPawn = KillerController->GetMyFortPawn();
		}

		void* DeathReport = nullptr;

		auto DeathLocation = Pawn->GetActorLocation();

		(AFortPlayerStateAthena*)((AFortPlayerState**)DeathReport + MemberOffsets::DeathReport::KillerPlayerState);

		uint8_t DeathCause = 0;

		static auto FallDamageEnumValue = 1;

		auto DeathInfo = PlayerState->GetDeathInfo(); // Alloc<void>(DeathInfoStructSize);
		PlayerState->ClearDeathInfo();

		auto Tags = MemberOffsets::FortPlayerPawn::CorrectTags == 0 ? FGameplayTagContainer()
			: Pawn->Get<FGameplayTagContainer>(MemberOffsets::FortPlayerPawn::CorrectTags);

		DeathCause = PlayerState->ToDeathCause(Tags, false, Pawn); // DeadPawn->IsDBNO() ??

		FGameplayTagContainer CopyTags;

		for (int i = 0; i < Tags.GameplayTags.Num(); ++i)
		{
			CopyTags.GameplayTags.Add(Tags.GameplayTags.at(i));
		}

		for (int i = 0; i < Tags.ParentTags.Num(); ++i)
		{
			CopyTags.ParentTags.Add(Tags.ParentTags.at(i));
		}

		LOG_INFO(LogDev, "DeathCause: {}", (int)DeathCause);
		LOG_INFO(LogDev, "DeadPawn->IsDBNO(): {}", Pawn->IsDBNO());
		LOG_INFO(LogDev, "KillerPlayerState: {}", __int64(KillerState));

		*(bool*)(__int64(DeathInfo) + MemberOffsets::DeathInfo::bDBNO) = Pawn->IsDBNO();
		*(uint8*)(__int64(DeathInfo) + MemberOffsets::DeathInfo::DeathCause) = DeathCause;
		*(AActor**)(__int64(DeathInfo) + MemberOffsets::DeathInfo::FinisherOrDowner) = KillerState ? KillerState : PlayerState;

		if (MemberOffsets::DeathInfo::DeathLocation != -1)
			*(FVector*)(__int64(DeathInfo) + MemberOffsets::DeathInfo::DeathLocation) = DeathLocation;

		if (MemberOffsets::DeathInfo::DeathTags != -1)
			*(FGameplayTagContainer*)(__int64(DeathInfo) + MemberOffsets::DeathInfo::DeathTags) = CopyTags;

		if (MemberOffsets::DeathInfo::bInitialized != -1)
			*(bool*)(__int64(DeathInfo) + MemberOffsets::DeathInfo::bInitialized) = true;

		if (DeathCause == FallDamageEnumValue)
		{
			if (MemberOffsets::FortPlayerPawnAthena::LastFallDistance != -1)
				*(float*)(__int64(DeathInfo) + MemberOffsets::DeathInfo::Distance) = Pawn->Get<float>(MemberOffsets::FortPlayerPawnAthena::LastFallDistance);
		}
		else
		{
			if (MemberOffsets::DeathInfo::Distance != -1)
				*(float*)(__int64(DeathInfo) + MemberOffsets::DeathInfo::Distance) = KillerPawn && Pawn ? KillerPawn->GetDistanceTo_Manual(Pawn) : 0;
		}

		if (MemberOffsets::FortPlayerState::PawnDeathLocation != -1)
			PlayerState->Get<FVector>(MemberOffsets::FortPlayerState::PawnDeathLocation) = DeathLocation;

		static auto OnRep_DeathInfoFn = FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerStateAthena.OnRep_DeathInfo");

		if (OnRep_DeathInfoFn)
		{
			PlayerState->ProcessEvent(OnRep_DeathInfoFn);
		}

		if (KillerState && KillerState != PlayerState)
		{
			if (MemberOffsets::FortPlayerStateAthena::KillScore != -1)
				KillerState->Get<int>(MemberOffsets::FortPlayerStateAthena::KillScore)++;

			if (MemberOffsets::FortPlayerStateAthena::TeamKillScore != -1)
				KillerState->Get<int>(MemberOffsets::FortPlayerStateAthena::TeamKillScore)++;

			KillerState->ClientReportKill(PlayerState);
		}

		if (Globals::AmountOfHealthSiphon != 0)
		{
			if (KillerPawn && KillerPawn != Pawn && KillerController && Cast<AController>(KillerController) != Cast<AController>(AIBotController))
			{
				auto WorldInventory = KillerController->GetWorldInventory();

				if (!WorldInventory)
					return;

				static auto WoodItemData = FindObject<UFortItemDefinition>(L"/Game/Items/ResourcePickups/WoodItemData.WoodItemData");
				static auto StoneItemData = FindObject<UFortItemDefinition>(L"/Game/Items/ResourcePickups/StoneItemData.StoneItemData");
				static auto MetalItemData = FindObject<UFortItemDefinition>(L"/Game/Items/ResourcePickups/MetalItemData.MetalItemData");

				WorldInventory->AddItem(WoodItemData, nullptr, 50);
				WorldInventory->AddItem(StoneItemData, nullptr, 50);
				WorldInventory->AddItem(MetalItemData, nullptr, 50);

				WorldInventory->Update();

				float Health = KillerPawn->GetHealth();
				float Shield = KillerPawn->GetShield();

				int MaxHealth = 100;
				int MaxShield = 100;
				int AmountGiven = 0;

				if ((MaxHealth - Health) > 0)
				{
					int AmountToGive = MaxHealth - Health >= Globals::AmountOfHealthSiphon ? Globals::AmountOfHealthSiphon : MaxHealth - Health;
					KillerPawn->SetHealth(Health + AmountToGive);
					AmountGiven += AmountToGive;
				}

				if ((MaxShield - Shield) > 0 && AmountGiven < Globals::AmountOfHealthSiphon)
				{
					int AmountToGive = MaxShield - Shield >= Globals::AmountOfHealthSiphon ? Globals::AmountOfHealthSiphon : MaxShield - Shield;
					AmountToGive -= AmountGiven;

					if (AmountToGive > 0)
					{
						KillerPawn->SetShield(Shield + AmountToGive);
						AmountGiven += AmountToGive;
					}
				}
			}
		}

		GameState->GetPlayersLeft()--;
		GameState->OnRep_PlayersLeft();

		LOG_INFO(LogDev, "Removed!");

		auto AllPlayerStates = UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFortPlayerStateAthena::StaticClass());

		bool bDidSomeoneWin = AllPlayerStates.Num() == 0;

		for (int i = 0; i < AllPlayerStates.Num(); ++i)
		{
			auto CurrentPlayerState = (AFortPlayerStateAthena*)AllPlayerStates.at(i);

			if (CurrentPlayerState->GetPlace() <= 1)
			{
				bDidSomeoneWin = true;
				break;
			}
		}

		if (bDidSomeoneWin && !GameState->IsRespawningAllowed(PlayerState) && GameMode->IsMatchInProgress())
		{
			LOG_INFO(LogDev, "Won!");

			TArray<AFortPlayerControllerAthena*> PlayerControllersArray;

			if (KillerController)
				PlayerControllersArray.Add(KillerController);

			auto AllPlayerStates = UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFortPlayerStateAthena::StaticClass());

			for (int i = 0; i < AllPlayerStates.Num(); ++i)
			{
				auto CurrentPlayerState = (AFortPlayerStateAthena*)AllPlayerStates.at(i);

				if (CurrentPlayerState && CurrentPlayerState != PlayerState && !CurrentPlayerState->IsBot())
				{
					LOG_INFO(LogBots, "PlayerState: {}", PlayerState->GetFullName());

					for (int i = 0; i < CurrentPlayerState->GetPlayerTeam()->GetTeamMembers().Num(); ++i) // i hope it doesn't crash if the current playerstate's controller is a bot controller
						PlayerControllersArray.Add(Cast<AFortPlayerControllerAthena>(CurrentPlayerState->GetPlayerTeam()->GetTeamMembers().at(i)));
				}
			}

			for (int i = 0; i < PlayerControllersArray.Num(); ++i)
			{
				auto ArrayController = PlayerControllersArray.at(i);
				auto ArrayPlayerState = ArrayController->GetPlayerState();
				auto ArrayPawn = ArrayController->GetMyFortPawn();

				if (!ArrayController || !ArrayPlayerState || !ArrayPawn)
					continue;

				TArray<UFortWeaponItemDefinition*> KillerWeaponsArray;

				for (int i = 0; i < ArrayController->GetWorldInventory()->GetItemList().GetItemInstances().Num(); ++i)
				{
					auto KillerWeapon = ArrayController->GetWorldInventory()->GetItemList().GetItemInstances().at(i)->GetItemEntry()->GetItemDefinition();

					if (!KillerWeapon)
						continue;

					if (KillerWeapon->IsA(UFortWeaponItemDefinition::StaticClass()))
					{
						auto KillerWeaponDefinition = (UFortWeaponItemDefinition*)KillerWeapon;

						KillerWeaponsArray.Add(KillerWeaponDefinition);
					}
				}

				for (int i = 0; i < KillerWeaponsArray.Num(); ++i)
				{
					auto KillerWeapon = KillerWeaponsArray.at(i);

					ArrayController->PlayWinEffects(ArrayPawn, KillerWeapon, DeathCause, false);
					ArrayController->ClientNotifyWon(ArrayPawn, KillerWeapon, DeathCause);
					ArrayController->ClientNotifyTeamWon(ArrayPawn, KillerWeapon, DeathCause);
				}

				if (ArrayPlayerState == KillerState && ArrayPawn)
				{
					ArrayController->PlayWinEffects(ArrayPawn, ArrayPawn->GetCurrentWeapon()->GetWeaponData(), DeathCause, false);
					ArrayController->ClientNotifyWon(ArrayPawn, ArrayPawn->GetCurrentWeapon()->GetWeaponData(), DeathCause);
					ArrayController->ClientNotifyTeamWon(ArrayPawn, ArrayPawn->GetCurrentWeapon()->GetWeaponData(), DeathCause);
				}

				if (ArrayPlayerState != PlayerState)
				{
					Cast<AFortPlayerStateAthena>(ArrayPlayerState)->GetPlace() = 1;
					Cast<AFortPlayerStateAthena>(ArrayPlayerState)->OnRep_Place();
				}
			}

			GameState->GetWinningPlayerState() = KillerState ? KillerState : PlayerState;
			GameState->GetWinningTeam() = KillerState ? KillerState->GetTeamIndex() : PlayerState->GetTeamIndex();
			GameState->OnRep_WinningPlayerState();
			GameState->OnRep_WinningTeam();
			GameMode->EndMatch();
		}

		if (AIBotController && false) // not yet
		{
			if (!AIBotController->GetInventory())
				return;

			for (int i = 0; i < AIBotController->GetInventory()->GetItemList().GetReplicatedEntries().Num(); i++)
			{
				if (AIBotController->GetInventory()->GetItemList().GetReplicatedEntries()[i].GetItemDefinition()->IsA(FindObject<UClass>("/Script/FortniteGame.FortWeaponMeleeItemDefinition")) || (Cast<UFortWorldItemDefinition>(AIBotController->GetInventory()->GetItemList().GetReplicatedEntries()[i].GetItemDefinition()) && !Cast<UFortWorldItemDefinition>(AIBotController->GetInventory()->GetItemList().GetReplicatedEntries()[i].GetItemDefinition())->CanBeDropped()))
					continue;

				PickupCreateData CreateData;
				CreateData.bToss = true;
				// CreateData.PawnOwner = Pawn;
				CreateData.ItemEntry = Cast<UFortItem>(AIBotController->GetInventory()->GetItemList().GetReplicatedEntries()[i].GetItemDefinition())->GetItemEntry();
				CreateData.SpawnLocation = Pawn->GetActorLocation();
				CreateData.SourceType = EFortPickupSourceTypeFlag::GetPlayerValue();
				CreateData.bRandomRotation = true;
				CreateData.bShouldFreeItemEntryWhenDeconstructed = true;

				AFortPickup::SpawnPickup(CreateData);
			}
		}
	}
};

inline std::vector<PlayerBot> AllPlayerBotsToTick;

namespace Bots
{
	static AController* SpawnBot(FTransform SpawnTransform, AActor* SourceActor = nullptr)
	{
		auto playerBot = PlayerBot();
		playerBot.Initialize(SpawnTransform, SourceActor);
		AllPlayerBotsToTick.push_back(playerBot);
		return playerBot.Controller;
	}
}

class Boss
{
public:
	AFortAthenaAIBotController* Controller = nullptr;
	AFortPlayerPawnAthena* Pawn = nullptr;
	AFortPlayerStateAthena* PlayerState = nullptr;
	FVector StartLocation;
	AActor* TargetActor = nullptr;
	bool bTickEnabled = false;

public:
	void Initialize(AActor* SpawnLocator, const FTransform& SpawnTransform, UFortAthenaAIBotCustomizationData* CustomizationData)
	{
		auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

		auto PawnClass = CustomizationData->GetPawnClass();

		FVector SpawnLocation = SpawnTransform.Translation;
		FRotator SpawnRotation = SpawnTransform.Rotation.Rotator();

		Pawn = BotManager->GetCachedBotMutator()->SpawnBot(PawnClass, SpawnLocator, SpawnLocation, SpawnRotation, false);

		if (Fortnite_Version >= 17)
			Controller = GetWorld()->SpawnActor<AFortAthenaAIBotController>(Pawn->GetAIControllerClass(), SpawnTransform);
		else
			Controller = Cast<AFortAthenaAIBotController>(Pawn->GetController());

		PlayerState = Cast<AFortPlayerStateAthena>(Controller->GetPlayerState());
		StartLocation = SpawnLocation;

		Pawn->GetController() = Controller;
		Controller->GetPlayerBotPawn() = Pawn;
		Controller->GetCachedBotMutator() = BotManager->GetCachedBotMutator();
		Controller->GetCachedGameMode() = GameMode;
		Controller->GetBotData() = CustomizationData;

		auto BehaviorTree = CustomizationData->GetBehaviorTree();
		auto BlackboardComponent = Controller->GetBlackboard();

		Controller->RunBehaviorTree(BehaviorTree);
		Controller->UseBlackboard(BehaviorTree->GetBlackboardAsset(), &BlackboardComponent);
		Controller->OnUsingBlackBoard(BlackboardComponent, BehaviorTree->GetBlackboardAsset());

		if (Controller->GetBotData()->HasCustomSquadId())
			Controller->SwitchTeam(Controller->GetBotData()->GetCustomSquadId());

		UObject* CharacterToApply = nullptr;

		if (!CharacterToApply)
		{
			auto DefaultCharacterName = CustomizationData->GetCharacterCustomization()->GetCustomizationLoadout()->GetCharacter()->GetName();

			if (DefaultCharacterName != "CID_556_Athena_Commando_F_RebirthDefaultA")
			{
				CharacterToApply = CustomizationData->GetCharacterCustomization()->GetCustomizationLoadout()->GetCharacter();
			}
			else
			{
				if (CustomizationData->GetFullName().contains("Alter"))
				{
					CharacterToApply = FindObject<UObject>("CID_780_Athena_Commando_M_HenchmanBadShorts", nullptr, ANY_PACKAGE);
				}
				else if (CustomizationData->GetFullName().contains("Ego"))
				{
					CharacterToApply = FindObject<UObject>("CID_779_Athena_Commando_M_HenchmanGoodShorts", nullptr, ANY_PACKAGE);
				}
				else
				{
					CharacterToApply = FindObject<UObject>("CID_NPC_Athena_Commando_M_HenchmanGood", nullptr, ANY_PACKAGE);
				}
			}
		}

		static auto HeroDefinitionOffset = CharacterToApply->GetOffset("HeroDefinition");

		if (HeroDefinitionOffset != 1)
		{
			auto HeroDefinition = CharacterToApply->Get(HeroDefinitionOffset);

			if (HeroDefinition)
				ApplyHID(Pawn, HeroDefinition, true);
		}

		auto BotNameSettings = CustomizationData->GetBotNameSettings();
		FString OverrideName = UKismetTextLibrary::Conv_TextToString(BotNameSettings->GetOverrideName());

		PlayerState->SetPlayerName(OverrideName);

		Controller->GetInventory() = GetWorld()->SpawnActor<AFortInventory>(AFortInventory::StaticClass(), FTransform(), CreateSpawnParameters(ESpawnActorCollisionHandlingMethod::AlwaysSpawn, true, Controller));

		if (Controller->GetInventory())
		{
			auto StartupInventoryItems = CustomizationData->GetStartupInventory()->GetItems();

			for (int i = 0; i < StartupInventoryItems.Num(); i++)
			{
				auto StartupInventoryItem = StartupInventoryItems.at(i);

				// Controller->GiveItem(StartupInventoryItem.GetItem(), StartupInventoryItem.GetCount());
			}
		}
		else
		{
			LOG_WARN(LogBots, "No Inventory!");
		}

		Controller->AddDigestedSkillSets();

		bTickEnabled = true;

		LOG_INFO(LogBots, "Finish boss initialization.");
	}

public:

	bool ShouldToggleShoot()
	{
		return UKismetMathLibrary::RandomBoolWithWeight(0.02f);
	}

	bool ShouldToggleCrouch()
	{
		return UKismetMathLibrary::RandomBoolWithWeight(0.009f);
	}

	bool ShouldLootAtTargetDuringMove()
	{
		if (Pawn->IsDBNO())
			return true;

		return UKismetMathLibrary::RandomBoolWithWeight(0.05f);
	}

	void StartFire()
	{
		if (!ShouldToggleShoot())
			return;

		LOG_INFO(LogBots, "[Henchman]: FIRE");

		Pawn->PawnStartFire(0);
	}

	void StopFire()
	{
		if (!ShouldToggleShoot())
			return;

		Pawn->PawnStopFire(0);
	}

	void ToggleCrouch()
	{
		if (!ShouldToggleCrouch())
			return;

		if (!Pawn->IsCrouched())
		{
			Pawn->Crouch(false);
		}
		else
		{
			Pawn->UnCrouch(false);
		}
	}

	void LootAtLocation(FVector FocalPoint)
	{
		auto LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Pawn->GetActorLocation(), FocalPoint);
		Controller->SetControlRotation(LookAtRotation);
	}

	void LootAtActor(AActor* FocalActor)
	{
		LootAtLocation(FocalActor->GetActorLocation());
	}

	void WalkInDirection(FVector WorldDirection)
	{
		Pawn->AddMovementInput(WorldDirection, 1.f, true);
	}

	void MoveToLocation(FVector Dest)
	{
		if (ShouldLootAtTargetDuringMove())
			LootAtLocation(Dest);

		WalkInDirection(Dest - Pawn->GetActorLocation());
		ToggleCrouch();
	}

	void MoveToActor(AActor* Goal)
	{
		MoveToLocation(Goal->GetActorLocation());
	}

public:

	virtual void OnDied(AFortPlayerStateAthena* KillerState = nullptr)
	{
		if (!Controller->GetBotData())
			return;

		auto StartupInventoryItems = Controller->GetBotData()->GetStartupInventory()->GetItems();

		for (int i = 0; i < StartupInventoryItems.Num(); ++i)
		{
			auto StartupInventoryItem = StartupInventoryItems.at(i);

			if (auto WorldItemDefinition = Cast<UFortWorldItemDefinition>(StartupInventoryItem.GetItem()))
			{
				if (WorldItemDefinition->CanBeDropped())
				{
					PickupCreateData PickupData;
					PickupData.bToss = true;
					PickupData.ItemEntry = FFortItemEntry::MakeItemEntry(WorldItemDefinition, StartupInventoryItem.GetCount(), -1, MAX_DURABILITY, WorldItemDefinition->GetFinalLevel(Cast<AFortGameStateAthena>(GetWorld()->GetGameState())->GetWorldLevel()));
					PickupData.SpawnLocation = Pawn->GetActorLocation();
					PickupData.SourceType = EFortPickupSourceTypeFlag::GetAIValue();
					PickupData.bRandomRotation = true;
					PickupData.bShouldFreeItemEntryWhenDeconstructed = true;

					AFortPickup::SpawnPickup(PickupData);

					LOG_INFO(LogBots, "ItemToDrop: {}", WorldItemDefinition->GetFullName());

					if (auto WeaponItemDefinition = Cast<UFortWeaponItemDefinition>(WorldItemDefinition))
					{
						if (WeaponItemDefinition->GetAmmoData() && WeaponItemDefinition->GetAmmoData() != WeaponItemDefinition && WeaponItemDefinition->GetAmmoData()->CanBeDropped())
						{
							PickupCreateData PickupData;
							PickupData.bToss = true;
							PickupData.ItemEntry = FFortItemEntry::MakeItemEntry(WeaponItemDefinition->GetAmmoData(), WeaponItemDefinition->GetAmmoData()->GetDropCount(), -1, MAX_DURABILITY, WorldItemDefinition->GetAmmoWorldItemDefinition_BP()->GetFinalLevel(Cast<AFortGameStateAthena>(GetWorld()->GetGameState())->GetWorldLevel()));
							PickupData.SpawnLocation = Pawn->GetActorLocation();
							PickupData.SourceType = EFortPickupSourceTypeFlag::GetAIValue();
							PickupData.bRandomRotation = true;
							PickupData.bShouldFreeItemEntryWhenDeconstructed = true;

							AFortPickup::SpawnPickup(PickupData);

							LOG_INFO(LogBots, "AmmoToDrop: {}", WeaponItemDefinition->GetAmmoData()->GetFullName());
						}
					}
				}
			}
		}
	}

	virtual void OnPerceptionSensed(AActor* SourceActor, FAIStimulus Stim)
	{
		LOG_INFO(LogBots, "OnPerceptionSensed!");

		if (Stim.WasSuccessfullySensed() && Controller->LineOfSightTo(SourceActor, FVector(), true) && Pawn->GetDistanceTo_Manual(SourceActor) < 7500)
			TargetActor = SourceActor;
	}

public:

	void OnTick()
	{
		if (!bTickEnabled)
			return;

		if (!Controller || !Pawn || !PlayerState)
			return;

		if (Pawn->IsDBNO())
		{
			TargetActor = nullptr;

			if (Pawn->GetActorLocation().DistanceTo(StartLocation) > 100)
			{
				MoveToLocation(StartLocation);
			}
			else
			{
				Controller->StopMovement();
			}

			return;
		}

		if (TargetActor)
		{
			switch (Controller->GetCurrentAlertLevel())
			{
			case EAlertLevel::Unaware:
				break;
			case EAlertLevel::Alerted:
				if (UKismetMathLibrary::RandomBoolWithWeight(0.008f))
					LootAtActor(TargetActor);
				break;
			case EAlertLevel::LKP:
				if (UKismetMathLibrary::RandomBoolWithWeight(0.04f))
					LootAtActor(TargetActor);
				break;
			case EAlertLevel::Threatened:
				if (Pawn->GetDistanceTo_Manual(TargetActor) <= 7500)
				{
					MoveToActor(TargetActor);
				}

				if (Controller->LineOfSightTo(TargetActor, FVector(), true))
				{
					StartFire();
					StopFire();
				}
				break;
			case EAlertLevel::Count:
				break;
			case EAlertLevel::EAlertLevel_MAX:
				Controller->GetCurrentAlertLevel() = EAlertLevel::Unaware;
				break;
			default:
				break;
			}
		}
		else
		{
			if (Controller->GetCachedPatrollingComponent())
			{

			}
		}
	}
};

inline std::vector<Boss> AllBossesToTick;

namespace Bosses
{
	static AFortAthenaAIBotController* SpawnBoss(AActor* SpawnLocator, FTransform SpawnTransform, UFortAthenaAIBotCustomizationData* CustomizationData)
	{
		auto boss = Boss();
		boss.Initialize(SpawnLocator, SpawnTransform, CustomizationData);
		AllBossesToTick.push_back(boss);
		return boss.Controller;
	}
}

class FortAI
{
public:
	AFortAIPawn* Pawn = nullptr;
	AController* Controller = nullptr;

public:
	void Initialize(const FTransform& SpawnTransform, UFortAthenaAISpawnerData* SpawnerData)
	{
		auto SpawnParams = SpawnerData->GetSpawnParamsComponent();
		auto PawnClass = SpawnParams->GetPawnClass();

		FVector SpawnLocation = SpawnTransform.Translation;
		FRotator SpawnRotation = SpawnTransform.Rotation.Rotator();

		Pawn = GetWorld()->SpawnActor<AFortAIPawn>(PawnClass, SpawnTransform);
		Controller = GetWorld()->SpawnActor<AController>(Pawn->GetAIControllerClass(), SpawnTransform);
	}
};

inline std::vector<FortAI> AllAIsToTick;

namespace AIs
{
	static AController* SpawnFortAI(FTransform SpawnTransform, UFortAthenaAISpawnerData* SpawnerData)
	{
		auto ai = FortAI();
		ai.Initialize(SpawnTransform, SpawnerData);
		AllAIsToTick.push_back(ai);
		return ai.Controller;
	}
}