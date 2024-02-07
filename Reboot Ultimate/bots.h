#pragma once

#include "FortGameModeAthena.h"
#include "OnlineReplStructs.h"
#include "BuildingContainer.h"
#include "FortAthenaMutator_Bots.h"
#include "FortAthenaAIBotController.h"
#include "FortAthenaAIBotCharacterCustomization.h"
#include "EnvQueryTypes.h"
#include "KismetMathLibrary.h"
#include "FortPlayerController.h"
#include "BlackBoard.h"
#include "AthenaNavSystem.h"
#include "FortPlayerPawn.h"
#include "AIHotSpot.h"

inline AFortAthenaMutator_Bots* BotMutator = nullptr;

inline bool AircraftHasEnteredDropZone = false;
inline bool AircraftHasExitedDropZone = false;
inline int DeadBotID = 0;
inline bool BotDied = false;
inline AFortPlayerStateAthena* KillerState = nullptr;
inline bool HenchmanDied = false;
inline AFortPlayerStateAthena* HenchmanKillerState = nullptr;
inline APawn* DeadHenchmanPawn = nullptr;

enum class EFortMovementStyle : uint8
{
	Running = 0,
	Walking = 1,
	Charging = 2,
	Sprinting = 3,
	PersonalVehicle = 4,
	Flying = 5,
	Tethered = 6,
	EFortMovementStyle_MAX = 7,
};

enum EBotWarmupBehaviour : uint8
{
	PlayEmote = 0,
	LootAndShoot = 1,
	Idle = 2,
	EBotWarmupBehaviour_MAX = 3,
};

enum EBotState : uint8
{
	Warmup,
	InBus,
	SkydivingFromBus,
	Landed,
	Looting,
	MovingToZone,
	LookingForPlayers,
	Stuck,
	MAX
};

inline std::map<AActor*, AFortAthenaAIBotController*> ChestsForBots{};
inline std::vector<UObject*> HIDs{};
inline std::vector<UObject*> Pickaxes{};
inline std::vector<UObject*> Backpacks{};
inline std::vector<UObject*> Gliders{};
inline std::vector<UObject*> Contrails{};
inline std::vector<UObject*> Dances{};

struct PhoebeBot
{
public:
	AFortAthenaAIBotController* PlayerController = nullptr;
	AFortPlayerPawnAthena* Pawn = nullptr;
	AFortPlayerStateAthena* PlayerState = nullptr;
	bool bIsEmoting = false;
	bool ThankedBusDriver = false;
	FVector TargetPOI = FVector();
	AActor* TargetActor = nullptr;
	AActor* PreviousActor = nullptr;
	bool TickEnabled = false;
	float FloatValue = 0.f;
	bool JumpedFromBus = false;
	ABuildingActor* StuckActor = nullptr;
	bool Running = false;
	AActor* TargetGoTo = nullptr;
	bool Emoting = false;
	bool Crouching = false;
	EBotWarmupBehaviour WarmupBehaviour = EBotWarmupBehaviour::LootAndShoot;
	float SecondsPassed = 0.f;
	AActor* PoiToLandAt = nullptr;

	EBotState State = EBotState::Warmup;
	EBotState PreviousState = EBotState::MAX;

public:
	UFortAthenaAIBotWarmupSkillSet* WarmupSkillSet = nullptr;

public:
	void ApplyCosmeticLoadout(AFortAthenaAIBotController* PlayerController, AFortPlayerPawnAthena* Pawn)
	{
		auto HID = HIDs[UKismetMathLibrary::RandomIntegerInRange(0, HIDs.size() - 1)];
		auto Backpack = Backpacks[UKismetMathLibrary::RandomIntegerInRange(0, Backpacks.size() - 1)];
		auto Glider = Gliders[UKismetMathLibrary::RandomIntegerInRange(0, Gliders.size() - 1)];
		auto Contrail = Contrails[UKismetMathLibrary::RandomIntegerInRange(0, Contrails.size() - 1)];

		std::vector<UFortItemDefinition*> AthenaHeroTypes;

		for (int i = 0; i < HIDs.size(); ++i)
		{
			auto CurrentHeroType = Cast<UFortItemDefinition>(HIDs.at(i));

			if (CurrentHeroType->GetPathName().starts_with("/Game/Athena/Heroes/"))
				AthenaHeroTypes.push_back(CurrentHeroType);
		}

		if (AthenaHeroTypes.size())
		{
			HID = AthenaHeroTypes.at(std::rand() % AthenaHeroTypes.size());
		}

		ApplyHID(Pawn, HID, true);
	}

	void GiveAndEquipItem(UFortItemDefinition* Def, int Count = 1, int LoadedAmmo = 0)
	{
		auto Inventory = PlayerController->GetInventory();

		bool bShouldUpdate = true;

		Inventory->AddItem(Def, &bShouldUpdate, Count, LoadedAmmo);

		if (bShouldUpdate)
			Inventory->Update();

		auto WeaponData = FindObject<UFortWeaponItemDefinition>(Def->GetFullName());

		// Pawn->EquipWeaponDefinition(WeaponData, Cast<UFortItem>(Def)->GetItemEntry()->GetItemGuid());
	}

	PhoebeBot(AActor* SpawnLocation)
	{
		auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

		static UClass* PawnClass = nullptr;
		static UClass* ControllerClass = nullptr;

		auto BGAClass = FindObject<UClass>(L"/Script/Engine.BlueprintGeneratedClass");

		PawnClass = LoadObject<UClass>(L"/Game/Athena/AI/Phoebe/BP_PlayerPawn_Athena_Phoebe.BP_PlayerPawn_Athena_Phoebe_C", BGAClass);
		ControllerClass = LoadObject<UClass>(L"/Game/Athena/AI/Phoebe/BP_PhoebePlayerController.BP_PhoebePlayerController_C", BGAClass);

		Pawn = BotMutator->SpawnBot(PawnClass, SpawnLocation, SpawnLocation->GetActorLocation(), SpawnLocation->GetActorRotation(), false);

		if (Fortnite_Version >= 17)
		{
			PlayerController = Cast<AFortAthenaAIBotController>(GetWorld()->SpawnActor<AController>(ControllerClass));
		}
		else
		{
			PlayerController = Cast<AFortAthenaAIBotController>(Pawn->GetController());
		}
		
		PlayerState = Cast<AFortPlayerStateAthena>(PlayerController->GetPlayerState());

		PlayerState->GetTeamIndex() = GameMode->Athena_PickTeamHook(GameMode, 0, PlayerController);

		static auto SquadIdOffset = PlayerState->GetOffset("SquadId", false);

		if (SquadIdOffset != -1)
			PlayerState->GetSquadId() = PlayerState->GetTeamIndex() - NumToSubtractFromSquadId;

		GameState->AddPlayerStateToGameMemberInfo(PlayerState);

		PlayerState->SetIsBot(true);

		if (Fortnite_Version < 17)
			ApplyCosmeticLoadout(PlayerController, Pawn);

		AFortInventory** Inventory = nullptr;

		if (auto FortPlayerController = Cast<AFortPlayerController>(PlayerController))
		{
			Inventory = &FortPlayerController->GetWorldInventory();
		}
		else
		{
			if (PlayerController->IsA(AFortAthenaAIBotController::StaticClass()))
			{
				static auto InventoryOffset = PlayerController->GetOffset("Inventory");
				Inventory = PlayerController->GetPtr<AFortInventory*>(InventoryOffset);
			}
		}

		if (!Inventory)
		{
			LOG_ERROR(LogBots, "No inventory pointer!");

			Pawn->K2_DestroyActor();
			PlayerController->K2_DestroyActor();
			return;
		}

		FTransform InventorySpawnTransform{};

		static auto FortInventoryClass = FindObject<UClass>(L"/Script/FortniteGame.FortInventory"); // AFortInventory::StaticClass()
		*Inventory = GetWorld()->SpawnActor<AFortInventory>(FortInventoryClass, InventorySpawnTransform, CreateSpawnParameters(ESpawnActorCollisionHandlingMethod::AlwaysSpawn, false, PlayerController));

		if (!*Inventory)
		{
			LOG_ERROR(LogBots, "Failed to spawn Inventory!");

			Pawn->K2_DestroyActor();
			PlayerController->K2_DestroyActor();
			return;
		}

		(*Inventory)->GetInventoryType() = EFortInventoryType::World;

		if (auto FortPlayerController = Cast<AFortPlayerController>(PlayerController))
		{
			static auto bHasInitializedWorldInventoryOffset = FortPlayerController->GetOffset("bHasInitializedWorldInventory");
			FortPlayerController->Get<bool>(bHasInitializedWorldInventoryOffset) = true;
		}

		if (Inventory)
		{
			auto& StartingItems = GameMode->GetStartingItems();

			for (int i = 0; i < StartingItems.Num(); ++i)
			{
				auto& StartingItem = StartingItems.at(i);

				(*Inventory)->AddItem(StartingItem.GetItem(), nullptr, StartingItem.GetCount());
			}

			if (auto FortPlayerController = Cast<AFortPlayerController>(PlayerController))
			{
				UFortItem* PickaxeInstance = FortPlayerController->AddPickaxeToInventory();

				if (PickaxeInstance)
				{
					FortPlayerController->ServerExecuteInventoryItemHook(FortPlayerController, PickaxeInstance->GetItemEntry()->GetItemGuid());
				}
			}

			(*Inventory)->Update();
		}

		auto PickDef = Cast<UAthenaPickaxeItemDefinition>(Pickaxes[UKismetMathLibrary::RandomIntegerInRange(0, Pickaxes.size() - 1)]);

		// GiveAndEquipItem(PickDef->GetWeaponDefinition());

		auto PlayerAbilitySet = GetPlayerAbilitySet();
		auto AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();

		if (PlayerAbilitySet)
		{
			PlayerAbilitySet->GiveToAbilitySystem(AbilitySystemComponent);
		}

		for (int i = 0; i < PlayerController->GetDigestedBotSkillSets().Num(); i++)
		{
			if (PlayerController->GetDigestedBotSkillSets()[i]->IsA(UFortAthenaAIBotAimingDigestedSkillSet::StaticClass()))
			{
				PlayerController->GetCacheAimingDigestedSkillSet() = Cast<UFortAthenaAIBotAimingDigestedSkillSet>(PlayerController->GetDigestedBotSkillSets()[i]);
			}

			if (PlayerController->GetDigestedBotSkillSets()[i]->IsA(UFortAthenaAIBotHarvestDigestedSkillSet::StaticClass()))
			{
				PlayerController->GetCacheHarvestDigestedSkillSet() = Cast<UFortAthenaAIBotHarvestDigestedSkillSet>(PlayerController->GetDigestedBotSkillSets()[i]);
			}

			if (PlayerController->GetDigestedBotSkillSets()[i]->IsA(UFortAthenaAIBotInventoryDigestedSkillSet::StaticClass()))
			{
				PlayerController->GetCacheInventoryDigestedSkillSet() = Cast<UFortAthenaAIBotInventoryDigestedSkillSet>(PlayerController->GetDigestedBotSkillSets()[i]);
			}

			if (PlayerController->GetDigestedBotSkillSets()[i]->IsA(UFortAthenaAIBotLootingDigestedSkillSet::StaticClass()))
			{
				PlayerController->GetCacheLootingSkillSet() = Cast<UFortAthenaAIBotLootingDigestedSkillSet>(PlayerController->GetDigestedBotSkillSets()[i]);
			}

			if (PlayerController->GetDigestedBotSkillSets()[i]->IsA(UFortAthenaAIBotMovementDigestedSkillSet::StaticClass()))
			{
				PlayerController->GetCacheMovementSkillSet() = Cast<UFortAthenaAIBotMovementDigestedSkillSet>(PlayerController->GetDigestedBotSkillSets()[i]);
			}

			if (PlayerController->GetDigestedBotSkillSets()[i]->IsA(UFortAthenaAIBotPerceptionDigestedSkillSet::StaticClass()))
			{
				PlayerController->GetCachePerceptionDigestedSkillSet() = Cast<UFortAthenaAIBotPerceptionDigestedSkillSet>(PlayerController->GetDigestedBotSkillSets()[i]);
			}

			if (PlayerController->GetDigestedBotSkillSets()[i]->IsA(UFortAthenaAIBotPlayStyleDigestedSkillSet::StaticClass()))
			{
				PlayerController->GetCachePlayStyleSkillSet() = Cast<UFortAthenaAIBotPlayStyleDigestedSkillSet>(PlayerController->GetDigestedBotSkillSets()[i]);
			}
		}

		if (PlayerController->GetBotSkillSetClasses().Num() > 0)
		{
			for (int i = 0; i < PlayerController->GetBotSkillSetClasses().Num(); i++)
			{
				if (PlayerController->GetBotSkillSetClasses()[i]->GetFullName().contains("warmup"))
				{
					WarmupSkillSet = Cast<UFortAthenaAIBotWarmupSkillSet>(PlayerController->GetBotSkillSetClasses()[i]);
				}
			}
		}
		else
		{
			LOG_WARN(LogBots, "PlayerController->GetBotSkillSetClasses().Num() is 0!");
		}

		PlayerController->GetPathFollowingComponent()->GetMyNavData() = Cast<UAthenaNavSystem>(GetWorld()->GetNavigationSystem())->GetMainNavData();
		PlayerController->GetPathFollowingComponent()->OnNavDataRegistered(Cast<UAthenaNavSystem>(GetWorld()->GetNavigationSystem())->GetMainNavData());

		PlayerState->OnRep_CharacterData();

		auto CapsuleComponent = Pawn->GetCapsuleComponent();

		static auto SetGenerateOverlapEventsFn = FindObject<UFunction>("/Script/Engine.PrimitiveComponent.SetGenerateOverlapEvents");

		bool bInGenerateOverlapEvents = true;

		CapsuleComponent->ProcessEvent(SetGenerateOverlapEventsFn, &bInGenerateOverlapEvents);

		Pawn->GetCharacterMovement()->SetCanWalkOffLedges(true);
		Pawn->GetCharacterMovement()->SetCanWalkOffLedgesWhenCrouching(true);

		TargetActor = FindNearestPlayer();
		PoiToLandAt = ChooseRandomAIHotSpot();

		if (WarmupSkillSet)
		{
			ChooseWarmupAction();
		}
		else
		{
			LOG_WARN(LogBots, "No WarumupSkillSet!")
		}

		TickEnabled = true;
	}
public:
	void StartEmoting()
	{
		if (!PlayerController || !Pawn || Emoting)
			return;

		auto FortPlayerController = Cast<AFortPlayerController>(PlayerController);

		static auto AthenaDanceItemDefinitionClass = FindObject<UClass>("/Script/FortniteGame.AthenaDanceItemDefinition");
		auto RandomDanceID = GetRandomObjectOfClass(AthenaDanceItemDefinitionClass);

		if (!RandomDanceID)
			return;

		auto AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();

		if (!AbilitySystemComponent)
			return;

		UObject* AbilityToUse = nullptr;

		if (!AbilityToUse)
		{
			static auto EmoteGameplayAbilityDefault = FindObject(L"/Game/Abilities/Emotes/GAB_Emote_Generic.Default__GAB_Emote_Generic_C");
			AbilityToUse = EmoteGameplayAbilityDefault;
		}

		if (!AbilityToUse)
			return;

		int outHandle = 0;

		FGameplayAbilitySpec* Spec = MakeNewSpec((UClass*)AbilityToUse, RandomDanceID, true);

		if (!Spec)
			return;

		static unsigned int* (*GiveAbilityAndActivateOnce)(UAbilitySystemComponent * ASC, int* outHandle, __int64 Spec, FGameplayEventData * TriggerEventData) = decltype(GiveAbilityAndActivateOnce)(Addresses::GiveAbilityAndActivateOnce); // EventData is only on ue500?

		if (GiveAbilityAndActivateOnce)
		{
			GiveAbilityAndActivateOnce(AbilitySystemComponent, &outHandle, __int64(Spec), nullptr);
		}

		Emoting = true;
	}

	void EquipPickaxe()
	{
		if (!Pawn || !Pawn->GetCurrentWeapon())
			return;

		if (!Pawn->GetCurrentWeapon()->GetWeaponData()->IsA(UFortWeaponMeleeItemDefinition::StaticClass()))
		{
			for (size_t i = 0; i < PlayerController->GetInventory()->GetItemList().GetReplicatedEntries().Num(); i++)
			{
				if (PlayerController->GetInventory()->GetItemList().GetReplicatedEntries()[i].GetItemDefinition()->IsA(UFortWeaponMeleeItemDefinition::StaticClass()))
				{
					Pawn->EquipWeaponDefinition((UFortWeaponItemDefinition*)PlayerController->GetInventory()->GetItemList().GetReplicatedEntries()[i].GetItemDefinition(), PlayerController->GetInventory()->GetItemList().GetReplicatedEntries()[i].GetItemGuid());
					break;
				}
			}
		}
	}

	void ChooseWarmupAction()
	{
		int WarmupPlayEmoteBehaviorWeight = WarmupSkillSet->GetWarmupPlayEmoteBehaviorWeight(); // 60%
		int WarmupLootAndShootBehaviorWeight = WarmupSkillSet->GetWarmupLootAndShootBehaviorWeight(); // 30%
		int WarmupIdleBehaviorWeight = WarmupSkillSet->GetWarmupIdleBehaviorWeight(); // 10%

		int Total = WarmupPlayEmoteBehaviorWeight + WarmupLootAndShootBehaviorWeight + WarmupIdleBehaviorWeight;

		auto RandomPercent = UKismetMathLibrary::RandomIntegerInRange(1, Total);

		if (1 <= RandomPercent && RandomPercent <= WarmupPlayEmoteBehaviorWeight)
		{
			WarmupBehaviour = EBotWarmupBehaviour::PlayEmote;
		}
		else if (WarmupPlayEmoteBehaviorWeight + 1 <= RandomPercent && RandomPercent <= WarmupPlayEmoteBehaviorWeight + WarmupLootAndShootBehaviorWeight)
		{
			WarmupBehaviour = EBotWarmupBehaviour::LootAndShoot;
		}
		else if (WarmupLootAndShootBehaviorWeight + 1 <= RandomPercent && RandomPercent <= WarmupPlayEmoteBehaviorWeight + WarmupLootAndShootBehaviorWeight + WarmupIdleBehaviorWeight)
		{
			WarmupBehaviour = EBotWarmupBehaviour::Idle;
		}
	}

	void Skydive(bool bFromBus = true)
	{
		Pawn->BeginSkydiving(bFromBus);
	}

	void JumpFromAircraft(AActor* Aircraft)
	{
		if (!TickEnabled || !Pawn || JumpedFromBus)
			return;

		Pawn->TeleportTo(Aircraft->GetActorLocation(), {});
		Skydive();

		TargetPOI = FindNearestChest()->GetActorLocation();

		State = EBotState::SkydivingFromBus;
	}

	void MoveToZone()
	{
		if (!PlayerController && !Pawn)
			return;
	}

	AActor* FindNearestPlayer()
	{
		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

		static auto World_NetDriverOffset = GetWorld()->GetOffset("NetDriver");
		auto WorldNetDriver = GetWorld()->Get<UNetDriver*>(World_NetDriverOffset);
		auto& ClientConnections = WorldNetDriver->GetClientConnections();

		AActor* NearestPawn = nullptr;

		for (int i = 0; i < GameMode->GetAlivePlayers().Num(); i++)
		{
			if (!NearestPawn || (GameMode->GetAlivePlayers()[i]->GetPawn() && GameMode->GetAlivePlayers()[i]->GetPawn()->GetDistanceTo(Pawn) < NearestPawn->GetDistanceTo(Pawn)))
			{
				NearestPawn = GameMode->GetAlivePlayers()[i]->GetPawn();
			}
		}

		for (int i = 0; i < GameMode->GetAliveBots().Num(); i++)
		{
			if (GameMode->GetAliveBots()[i]->GetPawn() != Pawn)
			{
				if (!NearestPawn || (GameMode->GetAliveBots()[i]->GetPawn() && GameMode->GetAliveBots()[i]->GetPawn()->GetDistanceTo(Pawn) < NearestPawn->GetDistanceTo(Pawn)))
				{
					NearestPawn = GameMode->GetAliveBots()[i]->GetPawn();
				}
			}
		}

		return NearestPawn;
	}

	AFortPickup* FindNearestPickup()
	{
		static auto PickupClass = FindObject<UClass>(L"/Script/FortniteGame.FortPickupAthena");
		TArray<AActor*> PickupArray = UGameplayStatics::GetAllActorsOfClass(GetWorld(), PickupClass);
		AActor* NearestPickup = nullptr;

		for (size_t i = 0; i < PickupArray.Num(); i++)
		{
			if (!NearestPickup || PickupArray[i]->GetDistanceTo(Pawn) < NearestPickup->GetDistanceTo(Pawn))
			{
				NearestPickup = PickupArray[i];
			}
		}

		PickupArray.Free();

		return Cast<AFortPickup>(NearestPickup);
	}

	FVector GetAimDirection(AActor* Actor)
	{
		int MaxOffset = 125;
		FVector Loc = Actor->GetActorLocation();

		Loc.X += UKismetMathLibrary::RandomIntegerInRange(-MaxOffset, MaxOffset);
		Loc.Y += UKismetMathLibrary::RandomIntegerInRange(-MaxOffset, MaxOffset);
		Loc.Z += UKismetMathLibrary::RandomIntegerInRange(-MaxOffset, MaxOffset);

		return Loc;
	}

	void LookAt(AActor* Actor)
	{
		auto LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Pawn->GetActorLocation(), Actor->GetActorLocation());
		PlayerController->SetControlRotation(LookAtRotation);
	}

	void SetMovementMode(EFortMovementStyle Style)
	{
		static auto CurrentMovementStyleOffset = Pawn->GetOffset("CurrentMovementStyle");
		Pawn->Get<EFortMovementStyle*>(CurrentMovementStyleOffset) = &Style;
	}

	void Run()
	{
		if (!Running)
		{
			Running = true;

			for (size_t i = 0; i < PlayerState->GetAbilitySystemComponent()->GetActivatableAbilities()->GetItems().Num(); i++)
			{
				if (PlayerState->GetAbilitySystemComponent()->GetActivatableAbilities()->GetItems().at(i).GetAbility()->IsA(UFortGameplayAbility_Sprint::StaticClass()))
				{
					// PlayerState->GetAbilitySystemComponent()->ServerTryActivateAbility(PlayerState->GetAbilitySystemComponent()->GetActivatableAbilities()->GetItems().at(i).GetHandle(), PlayerState->GetAbilitySystemComponent()->GetActivatableAbilities()->GetItems().at(i).GetInputPressed(), PlayerState->GetAbilitySystemComponent()->GetActivatableAbilities()->GetItems().at(i).GetActivationInfo()->GetPredictionKeyWhenActivated());
					break;
				}
			}
		}
	}

	void Jump()
	{
		Pawn->Jump();
	}

	void Crouch(bool bCrouch)
	{
		if (bCrouch)
		{
			Pawn->Crouch(false);
			Crouching = true;
		}
		else
		{
			Pawn->UnCrouch(false);
			Crouching = false;
		}
	}

	void MoveToLocation(FVector Location, float AcceptanceRadius = 0)
	{
		PlayerController->MoveToLocation(Location, AcceptanceRadius, true, false, false, true, nullptr, true);
	}

	void MoveToActor(AActor* Target, float AcceptanceRadius = 0)
	{
		if (TargetActor == Target)
			return;

		TargetActor = Target;
		PlayerController->MoveToActor(Target, AcceptanceRadius, true, false, true, nullptr, true);
		Run();
	}

	void RunInDirection(FVector Direction)
	{
		WalkInDirection(Direction);
		Run();
	}

	void WalkInDirection(FVector Direction)
	{
		static auto AddMovementInputFn = FindObject<UFunction>("/Script/Engine.Pawn.AddMovementInput");

		struct
		{
			FVector WorldDirection;
			float ScaleValue;
			bool bForce;
		}params{ Direction , 1.f, true };

		Pawn->ProcessEvent(AddMovementInputFn, &params);
	}

	void WalkForward()
	{
		static auto AddMovementInputFn = FindObject<UFunction>("/Script/Engine.Pawn.AddMovementInput");

		struct
		{
			FVector WorldDirection;
			float ScaleValue;
			bool bForce;
		}params{ Pawn->GetActorForwardVector() , 1.f, true };

		Pawn->ProcessEvent(AddMovementInputFn, &params);
	}

	ABuildingSMActor* FindNearestBuildingSMActor()
	{
		static TArray<AActor*> Array;
		static bool First = false;
		if (!First)
		{
			First = true;
			Array = UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABuildingSMActor::StaticClass());
		}

		AActor* NearestBuildingSMActor = nullptr;

		for (size_t i = 0; i < Array.Num(); i++)
		{
			if (!NearestBuildingSMActor || ((Cast<ABuildingSMActor>(NearestBuildingSMActor))->GetHealth() < 1500 && (Cast<ABuildingSMActor>(NearestBuildingSMActor))->GetHealth() > 1 && Array[i]->GetDistanceTo(Pawn) < NearestBuildingSMActor->GetDistanceTo(Pawn)))
			{
				NearestBuildingSMActor = Array[i];
			}
		}

		return Cast<ABuildingSMActor>(NearestBuildingSMActor);
	}

	ABuildingActor* FindNearestChest()
	{
		static auto ChestClass = FindObject<UClass>("/Game/Building/ActorBlueprints/Containers/Tiered_Chest_Athena.Tiered_Chest_Athena_C");
		TArray<AActor*> Array = UGameplayStatics::GetAllActorsOfClass(GetWorld(), ChestClass);

		AActor* NearestChest = nullptr;

		for (size_t i = 0; i < Array.Num(); i++)
		{
			AActor* Actor = Array[i];

			if (ChestsForBots.contains(Array[i]) && ChestsForBots[Actor] != PlayerController)
				continue;

			if (!NearestChest || Array[i]->GetDistanceTo(Pawn) < NearestChest->GetDistanceTo(Pawn))
			{
				NearestChest = Array[i];
			}
		}

		Array.Free();
		return Cast<ABuildingActor>(NearestChest);
	}

	bool HasGun()
	{
		for (size_t i = 0; i < PlayerController->GetInventory()->GetItemList().GetReplicatedEntries().Num(); i++)
		{
			if (!PlayerController->GetInventory()->GetItemList().GetReplicatedEntries()[i].GetItemDefinition()->IsA(UFortWeaponMeleeItemDefinition::StaticClass()))
				return true;
		}

		return false;
	}

	void StartLooting()
	{
		TargetActor = FindNearestChest();

		if (TargetActor)
		{
			ChestsForBots[TargetActor] = PlayerController;
			LookAt(TargetActor);
			State = EBotState::Looting;
		}
	}

	AActor* ChooseRandomAIHotSpot()
	{
		if (PoiToLandAt)
			return PoiToLandAt;

		TArray<AActor*> Array = UGameplayStatics::GetAllActorsOfClass(GetWorld(), FindObject<UClass>(L"/Script/FortniteGame.FortPoiVolume"));
		
		LOG_INFO(LogBots, "Array.Num(): {}", Array.Num());

		if (Array.Num() <= 0)
		{
			return nullptr;
		}

		auto RandomIndex = UKismetMathLibrary::RandomIntegerInRange(1, Array.Num());
		AActor* RandomPoiVolume = Array[RandomIndex];

		return RandomPoiVolume;
	}

	virtual void OnDied(AFortPlayerStateAthena* KillerState)
	{
		if (!KillerState)
			return;

		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());
		auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
		auto KillerPawn = KillerState->GetCurrentPawn();

		void* DeathReport = nullptr;

		TickEnabled = false;

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
				*(float*)(__int64(DeathInfo) + MemberOffsets::DeathInfo::Distance) = KillerPawn ? KillerPawn->GetDistanceTo(Pawn) : 0;
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
			if (KillerPawn && KillerPawn != Pawn)
			{
				auto KillerPlayerController = Cast<AFortPlayerController>(KillerPawn->GetController());

				auto WorldInventory = KillerPlayerController->GetWorldInventory();

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

		if (!PlayerController->GetInventory())
			return;

		for (size_t i = 0; i < PlayerController->GetInventory()->GetItemList().GetReplicatedEntries().Num(); i++)
		{
			if (PlayerController->GetInventory()->GetItemList().GetReplicatedEntries()[i].GetItemDefinition()->IsA(UFortWeaponMeleeItemDefinition::StaticClass()))
				continue;

			PickupCreateData CreateData;
			CreateData.bToss = true;
			// CreateData.PawnOwner = Pawn;
			CreateData.ItemEntry = Cast<UFortItem>(PlayerController->GetInventory()->GetItemList().GetReplicatedEntries()[i].GetItemDefinition())->GetItemEntry();
			CreateData.SpawnLocation = Pawn->GetActorLocation();
			CreateData.SourceType = EFortPickupSourceTypeFlag::GetPlayerValue();
			CreateData.bRandomRotation = true;
			CreateData.bShouldFreeItemEntryWhenDeconstructed = true;

			AFortPickup::SpawnPickup(CreateData);
		}
	}
};

inline std::vector<PhoebeBot*> PhoebeBotsToTick{};
inline std::vector<struct PhoebeHenchman*> PhoebeHenchmenToTick{};

struct PhoebeHenchman
{
public:
	AFortAthenaAIBotController* PlayerController = nullptr;
	AFortPlayerPawnAthena* Pawn = nullptr;
	AFortPlayerStateAthena* PlayerState = nullptr;
	bool TickEnabled = false;
	AActor* CurrentTarget = nullptr;
	bool IsCrouched = false;

public:
	PhoebeHenchman(AFortPlayerPawnAthena* InPawn, UClass* PawnClass)
	{
		Pawn = BotMutator->SpawnBot(PawnClass, InPawn, InPawn->GetActorLocation(), InPawn->GetActorRotation(), false);
		PlayerController = Cast<AFortAthenaAIBotController>(Pawn->GetController());
		PhoebeHenchmenToTick.push_back(this);
		InPawn->K2_DestroyActor();
		TickEnabled = true;
	}

public:
	void GiveItem(UFortItemDefinition* Def, int Count = 1)
	{
		auto Inventory = PlayerController->GetInventory();

		Inventory->AddItem(Def, nullptr, 1, Count);
		Inventory->Update();
	}

	void WalkInDirection(FVector Direction)
	{
		static auto AddMovementInputFn = FindObject<UFunction>("/Script/Engine.Pawn.AddMovementInput");

		struct
		{
			FVector WorldDirection;
			float ScaleValue;
			bool bForce;
		}params{ Direction , 1.f, true };

		Pawn->ProcessEvent(AddMovementInputFn, &params);
	}

public:
	virtual void OnDied(AFortPlayerStateAthena* KillerState)
	{
		if (!KillerState)
			return;

		LOG_INFO(LogBots, "Henchman Died.");

		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());
		auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
		auto KillerPawn = KillerState->GetCurrentPawn();

		TickEnabled = false;

		static auto OnRep_DeathInfoFn = FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerStateAthena.OnRep_DeathInfo");

		if (OnRep_DeathInfoFn)
		{
			PlayerState->ProcessEvent(OnRep_DeathInfoFn);
		}

		if (KillerState && KillerState != PlayerState)
		{
			KillerState->ClientReportKill(PlayerState);
		}

		if (!PlayerController->GetInventory())
			return;

		for (size_t i = 0; i < PlayerController->GetInventory()->GetItemList().GetReplicatedEntries().Num(); i++)
		{
			if (PlayerController->GetInventory()->GetItemList().GetReplicatedEntries()[i].GetItemDefinition()->IsA(UFortWeaponMeleeItemDefinition::StaticClass()))
				continue;

			PickupCreateData CreateData;
			CreateData.bToss = true;
			// CreateData.PawnOwner = Pawn;
			CreateData.ItemEntry = Cast<UFortItem>(PlayerController->GetInventory()->GetItemList().GetReplicatedEntries()[i].GetItemDefinition())->GetItemEntry();
			CreateData.SpawnLocation = Pawn->GetActorLocation();
			CreateData.SourceType = EFortPickupSourceTypeFlag::GetPlayerValue();
			CreateData.bRandomRotation = true;
			CreateData.bShouldFreeItemEntryWhenDeconstructed = true;

			AFortPickup::SpawnPickup(CreateData);
		}
	}

	virtual void OnPerceptionSensed(AActor* SourceActor, FAIStimulus& Stimulus)
	{
		if (Stimulus.bSuccessfullySensed == 1 && PlayerController->LineOfSightTo(SourceActor, FVector(), true) && Pawn->GetDistanceTo(SourceActor) < 5000)
		{
			CurrentTarget = SourceActor;

			LOG_INFO(LogBots, "Successfully sensed!");
		}
	}
};

static inline int RandomNumGen() 
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int randomNumber = (std::rand() % 26) + 1;
	return randomNumber;
}

namespace PhoebeBots
{
	static void PhoebePlayerBotTick()
	{
		for (auto PhoebeBot : PhoebeBotsToTick)
		{
			if (!PhoebeBot->TickEnabled || !PhoebeBot->Pawn || PhoebeBotsToTick.size() == 0)
				return;

			auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());

			switch (PhoebeBot->State)
			{
			case Warmup:

				switch (PhoebeBot->WarmupBehaviour)
				{
				case PlayEmote:
					PhoebeBot->StartEmoting();
					break;
				case LootAndShoot:
					// PhoebeBot->EquipPickaxe();

					PhoebeBot->TargetActor = PhoebeBot->FindNearestPlayer();

					if (PhoebeBot->TargetActor)
					{
						PhoebeBot->LookAt(PhoebeBot->TargetActor);

						if (PhoebeBot->Pawn->GetDistanceTo(PhoebeBot->TargetActor) > 300)
						{
							PhoebeBot->WalkInDirection(PhoebeBot->TargetActor->GetActorLocation() - PhoebeBot->Pawn->GetActorLocation());
						}

						if (UKismetMathLibrary::RandomBoolWithWeight(0.01f))
						{
							PhoebeBot->Jump();
						}

						if (UKismetMathLibrary::RandomBoolWithWeight(0.01f))
						{
							PhoebeBot->Crouch(!PhoebeBot->Crouching);
						}

						// PhoebeBot->Run();

						// PhoebeBot->SetMovementMode(EFortMovementStyle::Running);
					}
					break;
				case Idle:
					break;
				case EBotWarmupBehaviour_MAX:
					LOG_INFO(LogBots, "WarmupBehaviour invalid!");
					break;
				default:
					break;
				}

				break;
			case InBus:
				if (PhoebeBot->JumpedFromBus)
					return;

				if (AircraftHasExitedDropZone)
					PhoebeBot->JumpFromAircraft(GameState->GetAircraft(0));

				PhoebeBot->Emoting = false;

				if (!PhoebeBot->ThankedBusDriver && UKismetMathLibrary::RandomBoolWithWeight(0.05f))
				{
					PhoebeBot->ThankedBusDriver = true;
					PhoebeBot->PlayerController->ThankBusDriver();
				}

				if (!AircraftHasEnteredDropZone || !PhoebeBot->ThankedBusDriver/* || PhoebeBot->PoiToLandAt->GetDistanceTo(PhoebeBot->Pawn) > 1300*/)
					return;

				if (UKismetMathLibrary::RandomBoolWithWeight(0.07f))
				{
					PhoebeBot->JumpedFromBus = true;
					PhoebeBot->Pawn->TeleportTo(GameState->GetAircraft(0)->GetActorLocation(), {});
					PhoebeBot->Skydive(true);
					PhoebeBot->State = EBotState::SkydivingFromBus;
				}

				break;
			case SkydivingFromBus:
				if (!PhoebeBot->PoiToLandAt)
				{
					PhoebeBot->PoiToLandAt = PhoebeBot->ChooseRandomAIHotSpot();
					return;
				}

				PhoebeBot->LookAt(PhoebeBot->PoiToLandAt);
				PhoebeBot->WalkInDirection(PhoebeBot->PoiToLandAt->GetActorLocation() - PhoebeBot->Pawn->GetActorLocation());

				
				break;
			case Landed:
				PhoebeBot->StartLooting();
				break;
			case Looting:
				if (PhoebeBot->TargetActor)
				{
					PhoebeBot->LookAt(PhoebeBot->TargetActor);
					PhoebeBot->WalkInDirection(PhoebeBot->TargetActor->GetActorLocation() - PhoebeBot->Pawn->GetActorLocation());

					if (PhoebeBot->Pawn->GetDistanceTo(PhoebeBot->TargetActor) <= 200)
					{
						PhoebeBot->Pawn->PawnStopFire(0);

						if (PhoebeBot->SecondsPassed == 0.f)
						{
							PhoebeBot->SecondsPassed = UGameplayStatics::GetTimeSeconds(GetWorld());
							PhoebeBot->Pawn->SetStartedInteractSearch(true);
							PhoebeBot->Pawn->OnRep_StartedInteractSearch();
						}
						else if (UGameplayStatics::GetTimeSeconds(GetWorld()) - PhoebeBot->SecondsPassed >= 1.5f)
						{
							static auto SearchAnimationCountOffset = FindOffsetStruct("/Script/FortniteGame.FortSearchBounceData", "SearchAnimationCount");

							static auto bAlreadySearchedOffset = PhoebeBot->TargetActor->GetOffset("bAlreadySearched");
							static auto SearchBounceDataOffset = PhoebeBot->TargetActor->GetOffset("SearchBounceData");
							static auto bAlreadySearchedFieldMask = GetFieldMask(PhoebeBot->TargetActor->GetProperty("bAlreadySearched"));

							auto SearchBounceData = PhoebeBot->TargetActor->GetPtr<void>(SearchBounceDataOffset);

							if (PhoebeBot->TargetActor->ReadBitfieldValue(bAlreadySearchedOffset, bAlreadySearchedFieldMask))
								return;

							Cast<ABuildingContainer>(PhoebeBot->TargetActor)->SpawnLoot();

							PhoebeBot->TargetActor->SetBitfieldValue(bAlreadySearchedOffset, bAlreadySearchedFieldMask, true);
							(*(int*)(__int64(SearchBounceData) + SearchAnimationCountOffset))++;
							Cast<ABuildingContainer>(PhoebeBot->TargetActor)->BounceContainer();

							PhoebeBot->TargetActor->ForceNetUpdate();

							auto Pickup = PhoebeBot->FindNearestPickup();

							if (Pickup)
							{
								PhoebeBot->Pawn->ServerHandlePickupHook(PhoebeBot->Pawn, Pickup, 0.4f, FVector(), true);

								if (PhoebeBot->HasGun())
								{
									// PhoebeBot->EquipGun();

									PhoebeBot->State = EBotState::LookingForPlayers;
								}
							}
							else
							{
								PhoebeBot->SecondsPassed = 0.f;
								PhoebeBot->StartLooting();
								LOG_INFO(LogBots, "Pickup invalid!");
							}
						}
					}
					else
					{
						PhoebeBot->Pawn->PawnStartFire(0);
					}
				}
				else
				{
					PhoebeBot->StartLooting();
				}

				break;
			case MovingToZone:
				break;
			case LookingForPlayers:
				break;
			case Stuck:
				// PhoebeBot->Unstuck(); // real
				break;
			case MAX:
				break;
			default:
				break;
			}
		}
	}

	static void PhoebePlayerBotDied(AController* PlayerController, AController* InstigatedBy)
	{
		LOG_INFO(LogBots, "PhoebePlayerBotDied!");

		LOG_INFO(LogBots, "PhoebeBotsToTick.size(): {}", PhoebeBotsToTick.size());

		DeadBotID = PlayerController->GetPlayerState()->GetPlayerID();
		BotDied = true;
		KillerState = Cast<AFortPlayerStateAthena>(InstigatedBy->GetPlayerState());
	}

	static void PhoebeHenchmanTick()
	{
		for (auto Henchman : PhoebeHenchmenToTick)
		{
			if (!Henchman->TickEnabled || !Henchman->Pawn || Henchman->Pawn->IsDBNO() || !Henchman->CurrentTarget)
			{
				Henchman->CurrentTarget = nullptr;
				Henchman->PlayerController->StopMovement();
			}

			auto BotPos = Henchman->Pawn->GetActorLocation();
			auto TargetPos = Henchman->CurrentTarget->GetActorLocation();
			float Distance = Henchman->Pawn->GetDistanceTo(Henchman->CurrentTarget);

			if (Distance > 800)
			{
				Henchman->WalkInDirection(Henchman->CurrentTarget->GetActorLocation() - Henchman->Pawn->GetActorLocation());
			}
			else
			{
				Henchman->PlayerController->StopMovement();
				if (!Henchman->IsCrouched && UKismetMathLibrary::RandomBoolWithWeight(0.05f))
				{
					Henchman->Pawn->Crouch(false);
					Henchman->IsCrouched = true;
				}
				else if (Henchman->IsCrouched)
				{
					Henchman->Pawn->UnCrouch(false);
					Henchman->IsCrouched = false;
				}
			}

			int WillShoot = RandomNumGen();

			if (WillShoot == 1) {
				LOG_INFO(LogBots, "[EON AI]: Can Hit player!");

				float RandomYaw = UKismetMathLibrary::RandomFloatInRange(-20.0f, 20.0f);
				float RandomPitch = UKismetMathLibrary::RandomFloatInRange(-10.0f, 10.0f);

				FVector TargetPosTest{ TargetPos.X + RandomPitch, TargetPos.Y + RandomYaw, TargetPos.Z };

				auto TestRot = UKismetMathLibrary::FindLookAtRotation(BotPos, TargetPosTest);
				Henchman->PlayerController->SetControlRotation(TestRot);
				Henchman->Pawn->PawnStartFire(0);
			}
			else
			{
				float RandomYaw = UKismetMathLibrary::RandomFloatInRange(-180.0f, 180.0f);
				float RandomPitch = UKismetMathLibrary::RandomFloatInRange(-90.0f, 90.0f);

				FVector TargetPosFake{ TargetPos.X + RandomPitch, TargetPos.Y + RandomYaw, TargetPos.Z };
				auto TestRot = UKismetMathLibrary::FindLookAtRotation(BotPos, TargetPosFake);
				Henchman->PlayerController->SetControlRotation(TestRot);
				Henchman->Pawn->PawnStartFire(0);
			}
		}
	}

	static void PhoebeHenchmanDied(AController* PlayerController, AController* InstigatedBy)
	{
		LOG_INFO(LogBots, "PhoebeHenchmanDied!");

		LOG_INFO(LogBots, "PhoebeHenchmenToTick.size(): {}", PhoebeHenchmenToTick.size());

		HenchmanDied = true;
		HenchmanKillerState = Cast<AFortPlayerStateAthena>(InstigatedBy->GetPlayerState());
		DeadHenchmanPawn = PlayerController->GetPawn();
	}
}

namespace AIMutator
{
	static void SetupServerBotManager()
	{

		auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

		static auto FortServerBotManagerClass = FindObject<UClass>(L"/Script/FortniteGame.FortServerBotManagerAthena"); // Is there a BP for this? // GameMode->ServerBotManagerClass

		if (!FortServerBotManagerClass)
			return;

		static auto ServerBotManagerOffset = GameMode->GetOffset("ServerBotManager");
		UObject*& ServerBotManager = GameMode->Get(ServerBotManagerOffset);

		if (!ServerBotManager)
			ServerBotManager = UGameplayStatics::SpawnObject(FortServerBotManagerClass, GetTransientPackage());

		if (ServerBotManager)
		{
			static auto CachedGameModeOffset = ServerBotManager->GetOffset("CachedGameMode");
			ServerBotManager->Get(CachedGameModeOffset) = GameMode;

			static auto CachedGameStateOffset = ServerBotManager->GetOffset("CachedGameState", false);

			if (CachedGameStateOffset != -1)
				ServerBotManager->Get(CachedGameStateOffset) = GameState;

			static auto CachedBotMutatorOffset = ServerBotManager->GetOffset("CachedBotMutator");
			ServerBotManager->Get(CachedBotMutatorOffset) = BotMutator; /*FindFirstMutator(FindObject<UClass>(L"/Script/FortniteGame.FortAthenaMutator_Bots")); //could be this but we need to call BotMutator*/
		}
	}

	static void SetupAIDirector()
	{
		// Playlist->AISettings->bAllowAIDirector

		auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

		static auto AIDirectorClass = FindObject<UClass>(L"/Script/FortniteGame.AthenaAIDirector"); // Probably wrong class

		if (!AIDirectorClass)
			return;

		static auto AIDirectorOffset = GameMode->GetOffset("AIDirector");

		LOG_INFO(LogDev, "AIDirector Before: {}", __int64(GameMode->Get(AIDirectorOffset)));

		if (!GameMode->Get(AIDirectorOffset))
			GameMode->Get(AIDirectorOffset) = GetWorld()->SpawnActor<AActor>(AIDirectorClass);

		if (GameMode->Get(AIDirectorOffset))
		{
			LOG_INFO(LogAI, "Successfully spawned AIDirector!");

			// we have to set so much more from data tables..

			static auto OurEncounterClass = FindObject<UClass>(L"/Script/FortniteGame.FortAIEncounterInfo"); // ???
			static auto BaseEncounterClassOffset = GameMode->Get(AIDirectorOffset)->GetOffset("BaseEncounterClass");

			GameMode->Get(AIDirectorOffset)->Get(BaseEncounterClassOffset) = OurEncounterClass;

			static auto ActivateFn = FindObject<UFunction>(L"/Script/FortniteGame.FortAIDirector.Activate");

			if (ActivateFn) // ?
				GameMode->Get(AIDirectorOffset)->ProcessEvent(ActivateFn); // ?
		}
	}

	static void SpawnMutator() //sets up all the classes for phoebe
	{
		if (Globals::bEnablePhoebeBotTick)
		{
			auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
			auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

			static auto BGAClass = FindObject<UClass>(L"/Script/Engine.BlueprintGeneratedClass");
			static auto PhoebeMutatorClass = LoadObject<UClass>(L"/Game/Athena/AI/Phoebe/BP_Phoebe_Mutator.BP_Phoebe_Mutator_C", BGAClass);

			BotMutator = GetWorld()->SpawnActor<AFortAthenaMutator_Bots>(PhoebeMutatorClass); //maybe instead of spawning actor we can call UGameplayStatics::SpawnObject(PhoebeMutatorClass, GetTransientPackage());

			static auto CachedGameModeOffset = BotMutator->GetOffset("CachedGameMode"); //same as BotMutator->CachedGameMode = GameMode;
			BotMutator->Get(CachedGameModeOffset) = GameMode;

			static auto CachedGameStateOffset = BotMutator->GetOffset("CachedGameState", false); //same as BotMutator->CachedGameState = GameState;

			if (CachedGameStateOffset != -1)
				BotMutator->Get(CachedGameStateOffset) = GameState;
		}
	}
}

class AIPawn
{
public:
	AFortPlayerController* PlayerController = nullptr;
	AController* Controller = nullptr;
	float NextJumpTime = 1.0f;
	AActor* Target = nullptr;
	bool Running = false;
	AActor* MoveToTarget = nullptr;

	void Initialize(const FTransform& SpawnTransform)
	{
		auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

		static UClass* PawnClass = nullptr;
		static UClass* ControllerClass = nullptr;

		bool bUsePhoebeClasses = false;

		if (!PawnClass)
		{
			if (!bUsePhoebeClasses)
				PawnClass = FindObject<UClass>(L"/Game/Athena/PlayerPawn_Athena.PlayerPawn_Athena_C");
			else
				PawnClass = FindObject<UClass>(L"/Game/Athena/AI/Phoebe/BP_PlayerPawn_Athena_Phoebe.BP_PlayerPawn_Athena_Phoebe_C");
		}

		if (!ControllerClass)
		{
			if (!bUsePhoebeClasses)
				ControllerClass = AFortPlayerControllerAthena::StaticClass();
			else
				ControllerClass = FindObject<UClass>(L"/Game/Athena/AI/Phoebe/BP_PhoebePlayerController.BP_PhoebePlayerController_C");
		}

		if (!ControllerClass || !PawnClass)
		{
			LOG_ERROR(LogBots, "Failed to find a class for the bots!");
			return;
		}

		static auto FortAthenaAIBotControllerClass = FindObject<UClass>(L"/Script/FortniteGame.FortAthenaAIBotController");

		Controller = GetWorld()->SpawnActor<AController>(ControllerClass);
		PlayerController = Cast<AFortPlayerController>(Controller);
		AFortPlayerPawnAthena* Pawn = GetWorld()->SpawnActor<AFortPlayerPawnAthena>(PawnClass, SpawnTransform, CreateSpawnParameters(ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn));
		AFortPlayerStateAthena* PlayerState = Cast<AFortPlayerStateAthena>(Controller->GetPlayerState());

		if (!Pawn || !PlayerState)
			return;

		bool bUseOverrideName = false;

		FString NewName;

		if (bUseOverrideName)
		{
			NewName = L"Override";
		}
		else
		{
			static int CurrentBotNum = 200;
			auto BotNumWStr = std::to_wstring(CurrentBotNum++);
			NewName = (L"Anonymous[{}]", BotNumWStr).c_str();
		}

		if (auto PlayerController = Cast<APlayerController>(Controller))
		{
			if (Fortnite_Version < 9)
			{
				PlayerController->ServerChangeName(NewName);
			}
			else
			{
				GameMode->ChangeName(PlayerController, NewName, true);
			}
		}

		PlayerState->OnRep_PlayerName();

		PlayerState->GetTeamIndex() = GameMode->Athena_PickTeamHook(GameMode, 0, Controller);

		static auto SquadIdOffset = PlayerState->GetOffset("SquadId", false);

		if (SquadIdOffset != -1)
			PlayerState->GetSquadId() = PlayerState->GetTeamIndex() - NumToSubtractFromSquadId;

		GameState->AddPlayerStateToGameMemberInfo(PlayerState);

		PlayerState->SetIsBot(true);

		/*

		static auto FortRegisteredPlayerInfoClass = FindObject<UClass>("/Script/FortniteGame.FortRegisteredPlayerInfo");
		static auto MyPlayerInfoOffset = PlayerController->GetOffset("MyPlayerInfo");
		PlayerController->Get(MyPlayerInfoOffset) = UGameplayStatics::SpawnObject(FortRegisteredPlayerInfoClass, PlayerController);

		if (!PlayerController->Get(MyPlayerInfoOffset))
		{
			LOG_ERROR(LogBots, "Failed to spawn PlayerInfo!");

			Pawn->K2_DestroyActor();
			PlayerController->K2_DestroyActor();
			return nullptr;
		}

		auto& PlayerInfo = PlayerController->Get(MyPlayerInfoOffset);

		static auto UniqueIdOffset = PlayerState->GetOffset("UniqueId");
		static auto PlayerInfo_PlayerNameOffset = PlayerInfo->GetOffset("PlayerName");
		static auto PlayerIDOffset = PlayerInfo->GetOffset("PlayerID");
		PlayerInfo->GetPtr<FUniqueNetIdRepl>(PlayerIDOffset)->CopyFromAnotherUniqueId(PlayerState->GetPtr<FUniqueNetIdRepl>(UniqueIdOffset));
		PlayerInfo->Get<FString>(PlayerInfo_PlayerNameOffset) = PlayerState->GetPlayerName();

		*/

		Controller->Possess(Pawn);

		if (bUsePhoebeClasses)
		{
			Pawn->SetMaxHealth(100);
			Pawn->SetHealth(100);
			Pawn->SetMaxShield(100);
			Pawn->SetShield(100);
		}
		else
		{
			Pawn->SetMaxHealth(20);
			Pawn->SetHealth(20);
			Pawn->SetMaxShield(20);
			Pawn->SetShield(20);
		}

		AFortInventory** Inventory = nullptr;

		if (auto FortPlayerController = Cast<AFortPlayerController>(Controller))
		{
			Inventory = &FortPlayerController->GetWorldInventory();
		}
		else
		{
			if (Controller->IsA(FortAthenaAIBotControllerClass))
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

		// if (false)
		{
			if (Inventory)
			{
				auto& StartingItems = GameMode->GetStartingItems();

				for (int i = 0; i < StartingItems.Num(); ++i)
				{
					auto& StartingItem = StartingItems.at(i);

					(*Inventory)->AddItem(StartingItem.GetItem(), nullptr, StartingItem.GetCount());
				}

				if (auto FortPlayerController = Cast<AFortPlayerController>(Controller))
				{
					UFortItem* PickaxeInstance = FortPlayerController->AddPickaxeToInventory();

					if (PickaxeInstance)
					{
						FortPlayerController->ServerExecuteInventoryItemHook(FortPlayerController, PickaxeInstance->GetItemEntry()->GetItemGuid());
					}
				}

				(*Inventory)->Update();
			}
		}

		auto PlayerAbilitySet = GetPlayerAbilitySet();
		auto AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();

		if (PlayerAbilitySet)
		{
			PlayerAbilitySet->GiveToAbilitySystem(AbilitySystemComponent);
		}

		if (!bUsePhoebeClasses)
		{
			PlayerController->GetCosmeticLoadout()->GetCharacter() = FindObject<UAthenaCharacterItemDefinition>("/Game/Athena/Items/Cosmetics/Characters/CID_263_Athena_Commando_F_MadCommander.CID_263_Athena_Commando_F_MadCommander");
			Pawn->GetCosmeticLoadout()->GetCharacter() = PlayerController->GetCosmeticLoadout()->GetCharacter();

			PlayerController->ApplyCosmeticLoadout();

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
				HeroType = AthenaHeroTypes.at(std::rand() % AthenaHeroTypes.size());
			}

			static auto HeroTypeOffset = PlayerState->GetOffset("HeroType");

			if (HeroTypeOffset != -1)
				PlayerState->Get(HeroTypeOffset) = HeroType;

			static auto OwningGameInstanceOffset = GetWorld()->GetOffset("OwningGameInstance");
			auto OwningGameInstance = GetWorld()->Get(OwningGameInstanceOffset);

			static auto RegisteredPlayersOffset = OwningGameInstance->GetOffset("RegisteredPlayers");
			auto& RegisteredPlayers = OwningGameInstance->Get<TArray<UObject*>>(RegisteredPlayersOffset);

			static auto FortRegisteredPlayerInfoClass = FindObject<UClass>("/Script/FortniteGame.FortRegisteredPlayerInfo");

			auto NewPlayerInfo = UGameplayStatics::SpawnObject(FortRegisteredPlayerInfoClass, Controller);
			static auto PlayerIDOffset = NewPlayerInfo->GetOffset("PlayerID");

			static auto UniqueIdOffset = PlayerState->GetOffset("UniqueId");
			auto PlayerStateUniqueId = PlayerState->GetPtr<FUniqueNetIdRepl>(UniqueIdOffset);

			NewPlayerInfo->GetPtr<FUniqueNetIdRepl>(PlayerIDOffset)->CopyFromAnotherUniqueId(PlayerStateUniqueId);

			static auto MyPlayerInfoOffset = Controller->GetOffset("MyPlayerInfo");
			Controller->Get(MyPlayerInfoOffset) = NewPlayerInfo;

			RegisteredPlayers.Add(NewPlayerInfo);

			ApplyHID(Pawn, HeroType, true);
		}

		GameState->GetPlayersLeft()++;
		GameState->OnRep_PlayersLeft();

		if (auto FortPlayerControllerAthena = Cast<AFortPlayerControllerAthena>(Controller))
			GameMode->GetAlivePlayers().Add(FortPlayerControllerAthena);
	}
};

namespace Bots
{
	static AController* SpawnAIPawn(FTransform SpawnTransform)
	{
		auto playerBot = AIPawn();
		playerBot.Initialize(SpawnTransform);
		return playerBot.Controller;
	}
}