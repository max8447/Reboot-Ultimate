#pragma once

#include "FortGameModeAthena.h"
#include "OnlineReplStructs.h"
#include "BuildingContainer.h"
#include "FortAthenaMutator_Bots.h"

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


struct PhoebeBot
{
public:
	AController* PlayerController = nullptr;
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

	EBotState State = EBotState::Warmup;
	EBotState PreviousState = EBotState::MAX;

public:
	void ApplyCosmeticLoadout(AFortPlayerController* PlayerController, AFortPlayerPawnAthena* Pawn)
	{
		//skin
		//todo: move to cids in the future
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

		auto DefaultPawn = GetWorld()->SpawnActor<AActor>(PawnClass, NewTransform);

		Pawn = BotMutator->SpawnBot(PawnClass, DefaultPawn, SpawnLocation->GetActorLocation(), SpawnLocation->GetActorRotation(), true);
		PlayerController = Cast<AController>(Pawn->GetController());
		//PlayerState = Cast<AFortPlayerStateAthena>(Pawn->GetPlayerState()); //player state skun ked!!

		auto FortPlayerController = Cast<AFortPlayerController>(PlayerController);
		auto APlayerController = Cast<AController>(PlayerController);

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

		ApplyHID(Pawn, HeroType, true);

		TickEnabled = true;
	}
public:
	void StartEmoting()
	{
		//if (UKismetMathLibrary::GetDefaultObj()->RandomBoolWithWeight(0.17f))
		{
			if (!PlayerController && !Pawn)
				return;

			auto AFortPC = Cast<AFortPlayerController>(PlayerController);

			//if (!AFortPC->IsPlayingEmote()) //FUCKING KILL YOURSELF
			{
				static auto AthenaDanceItemDefinitionClass = FindObject<UClass>("/Script/FortniteGame.AthenaDanceItemDefinition");
				auto RandomDanceID = GetRandomObjectOfClass(AthenaDanceItemDefinitionClass);

				AFortPC->ServerPlayEmoteItemHook(AFortPC, RandomDanceID);
			}
		}
	}

	void JumpFromAircraft()
	{
		if (!ThankedBusDriver)
			return;

		auto Controller = Cast<AFortPlayerControllerAthena>(PlayerController);

		static auto ServerAttemptAircraftJumpFn = FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerControllerAthena.ServerAttemptAircraftJump") ? FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerControllerAthena.ServerAttemptAircraftJump")
			: FindObject<UFunction>(L"/Script/FortniteGame.FortControllerComponent_Aircraft.ServerAttemptAircraftJump");

		Controller->ProcessEvent(ServerAttemptAircraftJumpFn);
		State = EBotState::Landed;
	}

	void ThankBusDriver()
	{
		if (ThankedBusDriver || !PlayerController) //if they already thanked the bus driver or playercontroller doesnt exist
			return;

		auto idkPC = Cast<AFortPlayerControllerAthena>(PlayerController);

		static auto ServerThankBusDriver = FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerControllerAthena.ServerThankBusDriver");

		PlayerController->ProcessEvent(ServerThankBusDriver);
		ThankedBusDriver = true;
	}

	void MoveToZone()
	{
		if (!PlayerController && !Pawn)
			return;
	}

	virtual void PhoebeBotTick()
	{
		if (!TickEnabled || !Pawn)
			return;

		auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());

		switch (State)
		{
		case Warmup:
			//StartEmoting();
			break;
		case InBus:
			ThankBusDriver();
			break;
		case SkydivingFromBus://kinda useless
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
		{
			break;
		}
		case MAX:
			break;
		default:
			break;
		}
	}
};

inline std::vector<PhoebeBot*> PhoebeBotsToTick{};

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

class BotPOI
{
	FVector CenterLocation;
	FVector Range; // this just has to be FVector2D
};

class BotPOIEncounter
{
public:
	int NumChestsSearched;
	int NumAmmoBoxesSearched;
	int NumPlayersEncountered;
};

class AIPawn
{
public:
	AFortPlayerController* PlayerController = nullptr;
	AController* Controller = nullptr;
	BotPOIEncounter currentBotEncounter;
	int TotalPlayersEncountered;
	std::vector<BotPOI> POIsTraveled;
	float NextJumpTime = 1.0f;
	AActor* Target = nullptr;
	bool Running = false;
	AActor* MoveToTarget = nullptr;

	void OnPlayerEncountered()
	{
		currentBotEncounter.NumPlayersEncountered++;
		TotalPlayersEncountered++;
	}

	void MoveToNewPOI()
	{

	}

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

		bUsePhoebeClasses ? Pawn->SetHealth(21) : Pawn->SetHealth(21);
		Pawn->SetMaxHealth(21);
		bUsePhoebeClasses ? Pawn->SetShield(21) : Pawn->SetShield(21);
		Pawn->SetMaxShield(21);

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
			PlayerController->GetCosmeticLoadout()->GetCharacter() = FindObject("/Game/Athena/Items/Cosmetics/Characters/CID_263_Athena_Commando_F_MadCommander.CID_263_Athena_Commando_F_MadCommander");
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

	AFortPlayerPawnAthena* FindNearestPlayer()
	{
		auto GameMode = (AFortGameModeAthena*)GetWorld()->GetGameMode();

		AActor* NearestPoi = nullptr;

		for (size_t i = 0; i < GameMode->GetAlivePlayers().Num(); i++)
		{
			if (!NearestPoi || (GameMode->GetAlivePlayers()[i]->GetPawn() && GameMode->GetAlivePlayers()[i]->GetPawn()->GetDistanceTo(PlayerController->GetPawn()) < NearestPoi->GetDistanceTo(PlayerController->GetPawn())))
			{
				NearestPoi = GameMode->GetAlivePlayers()[i]->GetPawn();
			}
		}

		return (AFortPlayerPawnAthena*)NearestPoi;
	}

	void Run()
	{
		if (!Running)
		{
			Running = true;
			for (size_t i = 0; i < Cast<AFortPlayerStateAthena>(PlayerController->GetPlayerState())->GetAbilitySystemComponent()->GetActivatableAbilities()->GetItems().Num(); i++)
			{
				if (Cast<AFortPlayerStateAthena>(PlayerController->GetPlayerState())->GetAbilitySystemComponent()->GetActivatableAbilities()->GetItems()[i].GetAbility()->IsA(FindObject<UClass>("/Script/FortniteGame.FortGameplayAbility_Sprint")))
				{
					Cast<AFortPlayerStateAthena>(PlayerController->GetPlayerState())->GetAbilitySystemComponent()->ServerTryActivateAbility(Cast<AFortPlayerStateAthena>(PlayerController->GetPlayerState())->GetAbilitySystemComponent()->GetActivatableAbilities()->GetItems()[i].GetHandle(), Cast<AFortPlayerStateAthena>(PlayerController->GetPlayerState())->GetAbilitySystemComponent()->GetActivatableAbilities()->GetItems()[i].GetInputPressed(), Cast<AFortPlayerStateAthena>(PlayerController->GetPlayerState())->GetAbilitySystemComponent()->GetActivatableAbilities()->GetItems()[i].GetActivationInfo()->GetPredictionKeyWhenActivated());
					break;
				}
			}
		}
	}

	void MoveTo(AActor* Loc, float Radius = 0)
	{
		if (MoveToTarget == Loc)
			return;

		MoveToTarget = Loc;

		static auto fn = FindObject<UFunction>("/Script/AIModule.AIController.MoveToActor");

		struct
		{
			AActor*							   Goal;
			float                              AcceptanceRadius;
			bool                               bStopOnOverlap;
			bool                               bUsePathfinding;
			bool                               bCanStrafe;
			TSubclassOf<UObject>			   FilterClass;
			bool                               bAllowPartialPath;
		}params{ Loc , 0 , true , false , true , nullptr , true };

		Controller->ProcessEvent(fn, &params);

		Run();
	}
};

static inline std::vector<AIPawn> AllAIPawnsToTick;

namespace Bots
{
	static AController* SpawnAIPawn(FTransform SpawnTransform)
	{
		auto playerBot = AIPawn();
		playerBot.Initialize(SpawnTransform);
		AllAIPawnsToTick.push_back(playerBot);
		return playerBot.Controller;
	}

	static void SpawnBotsAtPlayerStarts(int AmountOfBots)
	{
		// return;

		auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

		for (int i = 0; i < AmountOfBots; ++i)
		{
			FTransform SpawnTransform{};
			SpawnTransform.Translation = FVector(1, 1, 10000);
			SpawnTransform.Rotation = FQuat();
			SpawnTransform.Scale3D = FVector(1, 1, 1);

			auto NewBot = SpawnAIPawn(SpawnTransform);
			auto PlayerStart = GameMode->K2_FindPlayerStart(NewBot, NewBot->GetPlayerState()->GetPlayerName()); // i dont think this works

			if (!PlayerStart)
			{
				LOG_ERROR(LogBots, "Failed to find PlayerStart for bot!");
				NewBot->GetPawn()->K2_DestroyActor();
				NewBot->K2_DestroyActor();
				continue;
			}

			NewBot->TeleportTo(PlayerStart->GetActorLocation(), FRotator());
			NewBot->SetCanBeDamaged(Fortnite_Version < 7); // idk lol for spawn island
		}
	}

	static void Tick()
	{
		if (AllAIPawnsToTick.size() == 0)
			return;

		auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

		// auto AllBuildingContainers = UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABuildingContainer::StaticClass());

		// for (int i = 0; i < GameMode->GetAlivePlayers().Num(); ++i)
		for (auto& PlayerBot : AllAIPawnsToTick)
		{
			auto CurrentPlayer = PlayerBot.Controller;
			auto CurrentController = PlayerBot.PlayerController;

			if (CurrentPlayer->IsActorBeingDestroyed())
				continue;

			auto CurrentPawn = CurrentPlayer->GetPawn();

			auto CurrentPlayerState = Cast<AFortPlayerStateAthena>(CurrentPlayer->GetPlayerState());

			if (!CurrentPlayerState || !CurrentPlayerState->IsBot())
				continue;

			if (GameState->GetGamePhase() == EAthenaGamePhase::Warmup)
			{
				/* if (!CurrentPlayer->IsPlayingEmote())
				{
					static auto AthenaDanceItemDefinitionClass = FindObject<UClass>("/Script/FortniteGame.AthenaDanceItemDefinition");
					auto RandomDanceID = GetRandomObjectOfClass(AthenaDanceItemDefinitionClass);

					CurrentPlayer->ServerPlayEmoteItemHook(CurrentPlayer, RandomDanceID);
				} */
			}

			if (CurrentPlayerState->IsInAircraft() && !CurrentPlayerState->HasThankedBusDriver())
			{
				static auto ServerThankBusDriverFn = FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerControllerAthena.ServerThankBusDriver");
				CurrentPlayer->ProcessEvent(ServerThankBusDriverFn);
			}

			if (CurrentPawn)
			{
				if (PlayerBot.NextJumpTime <= UGameplayStatics::GetTimeSeconds(GetWorld()))
				{
					static auto JumpFn = FindObject<UFunction>(L"/Script/Engine.Character.Jump");

					CurrentPawn->ProcessEvent(JumpFn);
					PlayerBot.NextJumpTime = UGameplayStatics::GetTimeSeconds(GetWorld()) + (rand() % 4 + 3);
				}
			}

			bool bShouldJumpFromBus = CurrentPlayerState->IsInAircraft(); // TODO (Milxnor) add a random percent thing

			if (bShouldJumpFromBus)
			{
				CurrentController->ServerAttemptAircraftJumpHook(CurrentController, FRotator());
			}

			if (Engine_Version > 423)
			{
				PlayerBot.Target = PlayerBot.FindNearestPlayer();

				if (PlayerBot.Target && PlayerBot.PlayerController->GetPawn()->GetDistanceTo(PlayerBot.Target) < 4000)
				{
					PlayerBot.MoveTo(PlayerBot.Target);
				}
			}
		}

		// AllBuildingContainers.Free();
	}
}

namespace Bosses
{

}
