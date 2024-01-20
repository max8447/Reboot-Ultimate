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

inline AFortAthenaMutator_Bots* BotMutator = nullptr;

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
	bool CanJumpFromBus = false;
	ABuildingActor* StuckActor = nullptr;
	bool Running = false;
	AActor* TargetGoTo = nullptr;
	bool Emoting = false;

	EBotState State = EBotState::Warmup;
	EBotState PreviousState = EBotState::MAX;

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

	void GiveItem(UFortItemDefinition* Def, int Count = 1, int LoadedAmmo = 0)
	{
		UFortItem* Item = Def->CreateTemporaryItemInstanceBP(Count, 0);

		auto Inventory = PlayerController->GetInventory();

		Item->Get<AFortInventory*>(Item->GetOffset("OwnerInventory")) = Inventory;
		Item->GetItemEntry()->GetLoadedAmmo() = LoadedAmmo;

		Inventory->GetItemList().GetReplicatedEntries().Add(*Item->GetItemEntry());
		Inventory->GetItemList().GetItemInstances().Add(Item);
		Inventory->GetItemList().MarkItemDirty(Item->GetItemEntry());
		Inventory->HandleInventoryLocalUpdate();
	}

	PhoebeBot(AActor* SpawnLocation)
	{
		auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

		static UClass* PawnClass = nullptr;
		static UClass* ControllerClass = nullptr;

		auto BGAClass = FindObject<UClass>(L"/Script/Engine.BlueprintGeneratedClass");

		PawnClass = LoadObject<UClass>(L"/Game/Athena/AI/Phoebe/BP_PlayerPawn_Athena_Phoebe.BP_PlayerPawn_Athena_Phoebe_C", BGAClass);

		FTransform NewTransform;
		NewTransform.Translation = SpawnLocation->GetActorLocation();
		NewTransform.Rotation = SpawnLocation->GetActorRotation().Quaternion();

		Pawn = BotMutator->SpawnBot(PawnClass, SpawnLocation, SpawnLocation->GetActorLocation(), SpawnLocation->GetActorRotation(), true);
		PlayerController = Cast<AFortAthenaAIBotController>(Pawn->GetController());
		PlayerState = Cast<AFortPlayerStateAthena>(PlayerController->GetPlayerState());
		
		PlayerState->GetTeamIndex() = GameMode->Athena_PickTeamHook(GameMode, 0, PlayerController);

		static auto SquadIdOffset = PlayerState->GetOffset("SquadId", false);

		if (SquadIdOffset != -1)
			PlayerState->GetSquadId() = PlayerState->GetTeamIndex() - NumToSubtractFromSquadId;

		GameState->AddPlayerStateToGameMemberInfo(PlayerState);

		PlayerState->SetIsBot(true);

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

		// GiveItem(PickDef->GetWeaponDefinition());

		auto PlayerAbilitySet = GetPlayerAbilitySet();
		auto AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();

		if (PlayerAbilitySet)
		{
			PlayerAbilitySet->GiveToAbilitySystem(AbilitySystemComponent);
		}

		TargetActor = FindNearestBuildingSMActor();

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

		State = EBotState::Landed;
	}

	void MoveToZone()
	{
		if (!PlayerController && !Pawn)
			return;
	}

	AActor* GetNewTargetPlayer()
	{
		static auto World_NetDriverOffset = GetWorld()->GetOffset("NetDriver");
		auto WorldNetDriver = GetWorld()->Get<UNetDriver*>(World_NetDriverOffset);
		auto& ClientConnections = WorldNetDriver->GetClientConnections();

		TArray<AActor*> PawnArray;

		for (int i = 0; i < ClientConnections.Num(); i++)
		{
			auto PlayerController = ClientConnections.at(i)->GetPlayerController();
			auto Pawn = PlayerController->GetPawn();

			PawnArray.Add(Pawn);
		}

		if (PawnArray.Num() < 1)
			return nullptr;

		int RandomIndex = (std::rand() % PawnArray.Num());

		return PawnArray.at(RandomIndex);
	}

	void LookAt(AActor* Actor)
	{
		if (!Actor || !Pawn || PlayerController->GetFocusActor() == Actor)
			return;

		if (!Actor)
		{
			PlayerController->ClearFocus();
			return;
		}

		PlayerController->SetFocus(Actor);
	}

	void Run()
	{
		if (!Running)
		{
			Running = true;
			for (size_t i = 0; i < PlayerState->GetAbilitySystemComponent()->GetActivatableAbilities()->GetItems().Num(); i++)
			{
				static auto FortGameplayAbility_SprintClass = FindObject<UClass>("/Script/FortniteGame.FortGameplayAbility_Sprint");

				if (PlayerState->GetAbilitySystemComponent()->GetActivatableAbilities()->GetItems()[i].GetAbility()->IsA(FortGameplayAbility_SprintClass))
				{
					PlayerState->GetAbilitySystemComponent()->ServerTryActivateAbility(PlayerState->GetAbilitySystemComponent()->GetActivatableAbilities()->GetItems()[i].GetHandle(), PlayerState->GetAbilitySystemComponent()->GetActivatableAbilities()->GetItems()[i].GetInputPressed(), PlayerState->GetAbilitySystemComponent()->GetActivatableAbilities()->GetItems()[i].GetActivationInfo()->GetPredictionKeyWhenActivated());
					break;
				}
			}
		}
	}

	void MoveToLocation(FVector& Location, float AcceptanceRadius = 0)
	{
		static auto MoveToLocationFn = FindObject<UFunction>("/Script/AIModule.AIController.MoveToLocation");

		struct
		{
			FVector Dest;
			float AcceptanceRadius;
			bool bStopOnOverlap;
			bool bUsePathfinding;
			bool bCanStrafe;
			TSubclassOf<UObject> FilterClass;
			bool bAllowPartialPath;
			EPathFollowingRequestResult ReturnValue;
		}AAIController_MoveToLocation_Params{ Location , AcceptanceRadius, true, false, true, nullptr, true };

		PlayerController->ProcessEvent(MoveToLocationFn, &AAIController_MoveToLocation_Params);
	}

	void MoveToActor(AActor* Target, float AcceptanceRadius = 0)
	{
		if (TargetActor == Target)
			return;

		TargetActor = Target;

		static auto MoveToActorFn = FindObject<UFunction>("/Script/AIModule.AIController.MoveToActor");

		struct
		{
			AActor* Goal;
			float AcceptanceRadius;
			bool bStopOnOverlap;
			bool bUsePathfinding;
			bool bCanStrafe;
			TSubclassOf<UObject> FilterClass;
			bool bAllowPartialPath;
			EPathFollowingRequestResult ReturnValue;
		}AAIController_MoveToActor_Params{ Target , AcceptanceRadius, true, false, true, nullptr, true };

		PlayerController->ProcessEvent(MoveToActorFn, &AAIController_MoveToActor_Params);

		// Run();
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
		// return nullptr;
		static TArray<AActor*> Array;
		static bool First = false;
		if (!First)
		{
			First = true;
			Array = UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABuildingSMActor::StaticClass());
		}

		AActor* NearestPoi = nullptr;

		for (size_t i = 0; i < Array.Num(); i++)
		{
			if (!NearestPoi || ((Cast<ABuildingSMActor>(NearestPoi))->GetHealth() < 1500 && (Cast<ABuildingSMActor>(NearestPoi))->GetHealth() > 1 && Array[i]->GetDistanceTo(Pawn) < NearestPoi->GetDistanceTo(Pawn)))
			{
				NearestPoi = Array[i];
			}
		}

		return Cast<ABuildingSMActor>(NearestPoi);
	}

	ABuildingActor* FindNearestChest()
	{
		static auto ChestClass = FindObject<UClass>("/Game/Building/ActorBlueprints/Containers/Tiered_Chest_Athena.Tiered_Chest_Athena_C");
		TArray<AActor*> Array = UGameplayStatics::GetAllActorsOfClass(GetWorld(), ChestClass);

		AActor* NearestPoi = nullptr;

		for (size_t i = 0; i < Array.Num(); i++)
		{
			AActor* Actor = Array[i];

			if (ChestsForBots.contains(Array[i]) && ChestsForBots[Actor] != PlayerController)
				continue;

			if (!NearestPoi || Array[i]->GetDistanceTo(Pawn) < NearestPoi->GetDistanceTo(Pawn))
			{
				NearestPoi = Array[i];
			}
		}

		Array.Free();
		return Cast<ABuildingActor>(NearestPoi);
	}

	virtual void OnDied(AFortPlayerStateAthena* KillerState)
	{
		if (!KillerState)
			return;

		TickEnabled = false;
		FDeathInfo *DeathInfo = PlayerState->GetDeathInfo();

		*(bool*)(__int64(DeathInfo) + MemberOffsets::DeathInfo::bDBNO) = Pawn->IsDBNO();
		*(bool*)(__int64(DeathInfo) + MemberOffsets::DeathInfo::bInitialized) = true;
		*(FVector*)(__int64(DeathInfo) + MemberOffsets::DeathInfo::DeathLocation) = Pawn->GetActorLocation();
		*(float*)(__int64(DeathInfo) + MemberOffsets::DeathInfo::Distance) = (KillerState->GetCurrentPawn() ? KillerState->GetCurrentPawn()->GetDistanceTo(Pawn) : 0);
		*(AActor**)(__int64(DeathInfo) + MemberOffsets::DeathInfo::FinisherOrDowner) = KillerState;
		*(uint8*)(__int64(DeathInfo) + MemberOffsets::DeathInfo::DeathCause) = KillerState->ToDeathCause(*(FGameplayTagContainer*)(__int64(DeathInfo) + MemberOffsets::DeathInfo::DeathTags), *(bool*)(__int64(DeathInfo) + MemberOffsets::DeathInfo::bDBNO));
		PlayerState->OnRep_DeathInfo();

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
			CreateData.SourceType = EFortPickupSourceTypeFlag::GetAIValue();
			CreateData.bRandomRotation = true;
			CreateData.bShouldFreeItemEntryWhenDeconstructed = true;

			AFortPickup::SpawnPickup(CreateData);
		}

		auto KillerPlayerController = Cast<AFortPlayerControllerAthena>(KillerState->GetOwner());
		if (KillerPlayerController && KillerPlayerController->IsA(AFortPlayerControllerAthena::StaticClass()))
		{
			KillerState->Get<int>(MemberOffsets::FortPlayerStateAthena::KillScore)++;
			KillerPlayerController->GiveAccolade(KillerPlayerController, GetDefFromEvent(EAccoladeEvent::Kill, KillerState->Get<int>(MemberOffsets::FortPlayerStateAthena::KillScore)));

			for (size_t i = 0; i < KillerState->GetPlayerTeam()->GetTeamMembers().Num(); i++)
			{
				(Cast<AFortPlayerStateAthena>(KillerState->GetPlayerTeam()->GetTeamMembers()[i]->GetPlayerState()))->Get<int>(MemberOffsets::FortPlayerStateAthena::TeamKillScore)++;
				(Cast<AFortPlayerStateAthena>(KillerState->GetPlayerTeam()->GetTeamMembers()[i]->GetPlayerState()))->OnRep_TeamKillScore();
			}

			KillerState->ClientReportKill(PlayerState);
			KillerState->OnRep_Kills();
		}

		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

		if (GameMode->GetAlivePlayers().Num() + GameMode->GetAliveBots().Num() == 50)
		{
			for (size_t i = 0; i < GameMode->GetAlivePlayers().Num(); i++)
			{
				GameMode->GetAlivePlayers()[i]->GiveAccolade(GameMode->GetAlivePlayers()[i], FindObject<UFortAccoladeItemDefinition>("/Game/Athena/Items/Accolades/AccoladeId_026_Survival_Default_Bronze.AccoladeId_026_Survival_Default_Bronze"));
			}
		}
		if (GameMode->GetAlivePlayers().Num() + GameMode->GetAliveBots().Num() == 25)
		{
			for (size_t i = 0; i < GameMode->GetAlivePlayers().Num(); i++)
			{
				GameMode->GetAlivePlayers()[i]->GiveAccolade(GameMode->GetAlivePlayers()[i], FindObject<UFortAccoladeItemDefinition>("/Game/Athena/Items/Accolades/AccoladeId_027_Survival_Default_Silver.AccoladeId_027_Survival_Default_Silver"));
			}
		}
		if (GameMode->GetAlivePlayers().Num() + GameMode->GetAliveBots().Num() == 10)
		{
			for (size_t i = 0; i < GameMode->GetAlivePlayers().Num(); i++)
			{
				GameMode->GetAlivePlayers()[i]->GiveAccolade(GameMode->GetAlivePlayers()[i], FindObject<UFortAccoladeItemDefinition>("/Game/Athena/Items/Accolades/AccoladeId_028_Survival_Default_Gold.AccoladeId_028_Survival_Default_Gold"));
			}
		}
	}
};

inline std::vector<PhoebeBot*> PhoebeBotsToTick{};

namespace PhoebeBots
{
	static void PhoebeBotTick()
	{
		for (auto PhoebeBot : PhoebeBotsToTick)
		{
			if (!PhoebeBot->TickEnabled || !PhoebeBot->Pawn || PhoebeBotsToTick.size() == 0)
				return;

			auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());

			switch (PhoebeBot->State)
			{
			case Warmup:
				PhoebeBot->StartEmoting();
				// PhoebeBot->TargetActor = PhoebeBot->GetNewTargetPlayer();

				if (PhoebeBot->TargetActor)
				{
					auto Target = Cast<ABuildingSMActor>(PhoebeBot->TargetActor);
					PhoebeBot->LookAt(PhoebeBot->TargetActor);
					PhoebeBot->MoveToActor(PhoebeBot->TargetActor);

					// PhoebeBot->WalkForward();
					// PhoebeBot->Run();
				}

				break;
			case InBus:
				if (PhoebeBot->JumpedFromBus)
					return;

				PhoebeBot->Emoting = false;

				if (!PhoebeBot->ThankedBusDriver && UKismetMathLibrary::RandomBoolWithWeight(0.05f))
				{
					PhoebeBot->ThankedBusDriver = true;
					PhoebeBot->PlayerController->ThankBusDriver();
				}

				if (!PhoebeBot->CanJumpFromBus || !PhoebeBot->ThankedBusDriver)
					return;

				if (UKismetMathLibrary::RandomBoolWithWeight(0.07f))
				{
					PhoebeBot->JumpedFromBus = true;
					PhoebeBot->Pawn->TeleportTo(GameState->GetAircraft(0)->GetActorLocation(), {});
					PhoebeBot->Skydive(true);
					PhoebeBot->State = EBotState::Landed;
				}

				break;
			case SkydivingFromBus:
				PhoebeBot->State = EBotState::Landed;
				break;
			case Landed:
				break;
			case Looting:
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
}

namespace AIMutator {
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
			PlayerController->ServerChangeName(NewName);

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