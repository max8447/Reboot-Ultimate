#include "GameModeBase.h"

#include "reboot.h"
#include "FortPlayerControllerAthena.h"
#include "FortGameModeAthena.h"
#include "FortLootPackage.h"
#include "FortAthenaMutator_GiveItemsAtGamePhaseStep.h"
#include "DataTableFunctionLibrary.h"
#include "FortAthenaMutator_GG.h"
#include "FortAthenaMutator_InventoryOverride.h"

UClass* AGameModeBase::GetDefaultPawnClassForController(AController* InController)
{
	static auto GetDefaultPawnClassForControllerFn = FindObject<UFunction>("/Script/Engine.GameModeBase.GetDefaultPawnClassForController");
	struct
	{
		AController* InController;                                             // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
		UClass* ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	} AGameModeBase_GetDefaultPawnClassForController_Params{InController};

	this->ProcessEvent(GetDefaultPawnClassForControllerFn, &AGameModeBase_GetDefaultPawnClassForController_Params);

	return AGameModeBase_GetDefaultPawnClassForController_Params.ReturnValue;
}

APawn* AGameModeBase::SpawnDefaultPawnForHook(AGameModeBase* GameMode, AController* NewPlayer, AActor* StartSpot)
{
	LOG_INFO(LogDev, "SpawnDefaultPawnFor: 0x{:x}!", __int64(_ReturnAddress()) - __int64(GetModuleHandleW(0)));

	// auto PawnClass = GameMode->GetDefaultPawnClassForController(NewPlayer);
	// LOG_INFO(LogDev, "PawnClass: {}", PawnClass->GetFullName());

	static auto PawnClass = FindObject<UClass>("/Game/Athena/PlayerPawn_Athena.PlayerPawn_Athena_C");
	GameMode->Get<UClass*>("DefaultPawnClass") = PawnClass;

	constexpr bool bUseSpawnActor = false;

	static auto fn = FindObject<UFunction>(L"/Script/Engine.GameModeBase.SpawnDefaultPawnAtTransform");

	FTransform SpawnTransform = StartSpot->GetTransform();
	APawn* NewPawn = nullptr;

	FActorSpawnParameters SpawnParameters{};
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	if constexpr (bUseSpawnActor)
	{
		NewPawn = GetWorld()->SpawnActor<APawn>(PawnClass, SpawnTransform, SpawnParameters);
	}
	else
	{
		struct { AController* NewPlayer; FTransform SpawnTransform; APawn* ReturnValue; }
		AGameModeBase_SpawnDefaultPawnAtTransform_Params{ NewPlayer, SpawnTransform };

		GameMode->ProcessEvent(fn, &AGameModeBase_SpawnDefaultPawnAtTransform_Params);

		NewPawn = AGameModeBase_SpawnDefaultPawnAtTransform_Params.ReturnValue;
	}

	if (!NewPawn)
		return nullptr;

	bool bIsRespawning = false;

	if (!bIsRespawning)
	{
		auto NewPlayerAsAthena = Cast<AFortPlayerControllerAthena>(NewPlayer);

		auto GameState = ((AFortGameModeAthena*)GameMode)->GetGameStateAthena();
		auto PlayerStateAthena = NewPlayerAsAthena->GetPlayerStateAthena();
		
		if (!PlayerStateAthena)
			return nullptr;

		auto ASC = PlayerStateAthena->GetAbilitySystemComponent();

		GET_PLAYLIST(GameState);

		if (CurrentPlaylist) // Apply gameplay effects from playlist // We need to move this!
		{
			CurrentPlaylist->ApplyModifiersToActor(PlayerStateAthena);
		}

		auto PlayerAbilitySet = GetPlayerAbilitySet(); // Apply default gameplay effects // We need to move maybe?

		if (PlayerAbilitySet && ASC)
		{
			PlayerAbilitySet->ApplyGrantedGameplayAffectsToAbilitySystem(ASC);
		}

		if (NewPlayerAsAthena)
		{
			auto WorldInventory = NewPlayerAsAthena->GetWorldInventory();

			if (!WorldInventory)
				return NewPawn;

			if (!WorldInventory->GetPickaxeInstance())
			{
				// TODO Check Playlist->bRequirePickaxeInStartingInventory

				auto CosmeticLoadout = NewPlayerAsAthena->GetCosmeticLoadoutOffset() != -1 ? NewPlayerAsAthena->GetCosmeticLoadout() : nullptr;
				auto CosmeticLoadoutPickaxe = CosmeticLoadout ? CosmeticLoadout->GetPickaxe() : nullptr;

				static auto WeaponDefinitionOffset = FindOffsetStruct("/Script/FortniteGame.AthenaPickaxeItemDefinition", "WeaponDefinition", false);

				auto PickaxeDefinition = CosmeticLoadoutPickaxe ? CosmeticLoadoutPickaxe->Get<UFortItemDefinition*>(WeaponDefinitionOffset)
					: FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Weapons/WID_Harvest_Pickaxe_Athena_C_T01.WID_Harvest_Pickaxe_Athena_C_T01");

				static UFortItemDefinition* EditToolItemDefinition = FindObject<UFortItemDefinition>(L"/Game/Items/Weapons/BuildingTools/EditTool.EditTool");
				static UFortItemDefinition* BuildingItemData_Wall = FindObject<UFortItemDefinition>(L"/Game/Items/Weapons/BuildingTools/BuildingItemData_Wall.BuildingItemData_Wall");
				static UFortItemDefinition* BuildingItemData_Floor = FindObject<UFortItemDefinition>(L"/Game/Items/Weapons/BuildingTools/BuildingItemData_Floor.BuildingItemData_Floor");
				static UFortItemDefinition* BuildingItemData_Stair_W = FindObject<UFortItemDefinition>(L"/Game/Items/Weapons/BuildingTools/BuildingItemData_Stair_W.BuildingItemData_Stair_W");
				static UFortItemDefinition* BuildingItemData_RoofS = FindObject<UFortItemDefinition>(L"/Game/Items/Weapons/BuildingTools/BuildingItemData_RoofS.BuildingItemData_RoofS");
				static UFortItemDefinition* WoodItemData = FindObject<UFortItemDefinition>(L"/Game/Items/ResourcePickups/WoodItemData.WoodItemData");
				static UFortItemDefinition* DamageTrap = FindObject<UFortItemDefinition>(L"/Game/Athena/Items/Traps/TID_ContextTrap_Athena.TID_ContextTrap_Athena");

				WorldInventory->AddItem(PickaxeDefinition, nullptr);
				WorldInventory->AddItem(EditToolItemDefinition, nullptr);
				WorldInventory->AddItem(BuildingItemData_Wall, nullptr);
				WorldInventory->AddItem(BuildingItemData_Floor, nullptr);
				WorldInventory->AddItem(BuildingItemData_Stair_W, nullptr);
				WorldInventory->AddItem(BuildingItemData_RoofS, nullptr);

				/* if (Globals::bLateGame)
				{
					auto SpawnIslandTierGroup = UKismetStringLibrary::Conv_StringToName(L"Loot_AthenaFloorLoot_Warmup");

					for (int i = 0; i < 5; i++)
					{
						auto LootDrops = PickLootDrops(SpawnIslandTierGroup);

						for (auto& LootDrop : LootDrops)
						{
							WorldInventory->AddItem(LootDrop.ItemDefinition, nullptr, LootDrop.Count, LootDrop.LoadedAmmo);
						}
					}
				} */

				auto AddInventoryOverrideTeamLoadouts = [&](AFortAthenaMutator* Mutator)
				{
					if (auto InventoryOverride = Cast<AFortAthenaMutator_InventoryOverride>(Mutator))
					{
						auto TeamIndex = PlayerStateAthena->GetTeamIndex();
						auto LoadoutContainer = InventoryOverride->GetLoadoutContainerForTeamIndex(TeamIndex);

						for (int i = 0; i < LoadoutContainer.Loadout.Num(); i++)
						{
							auto& ItemAndCount = LoadoutContainer.Loadout.at(i);
							WorldInventory->AddItem(ItemAndCount.GetItem(), nullptr, ItemAndCount.GetCount());
						}
					}
				};

				LoopMutators(AddInventoryOverrideTeamLoadouts);

				WorldInventory->Update();
			}
		}
	}

	return NewPawn;
}