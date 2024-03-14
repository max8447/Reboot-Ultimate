#pragma once

#include "FortGameModeAthena.h"
#include "FortAthenaAIBotController.h"
#include "FortAIPawn.h"
#include "FortAthenaAIBotCustomizationData.h"
#include "FortServerBotManagerAthena.h"
#include "FortAthenaAISpawnerData.h"

class PlayerBot
{
public:
	AController* Controller = nullptr;

public:
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
			static int CurrentBotNum = 1;
			auto BotNumWStr = Fortnite_Version < 9 ? std::to_wstring(CurrentBotNum++) : std::to_wstring(CurrentBotNum++ + 200);
			NewName = Fortnite_Version < 9 ? (L"RebootBot" + BotNumWStr).c_str() : (std::format(L"Anonymous[{}]", BotNumWStr)).c_str();
		}

		if (auto PlayerController = Cast<APlayerController>(Controller))
		{
			if (Fortnite_Version < 9)
				PlayerController->ServerChangeName(NewName);
			else
				GameMode->ChangeName(Controller, NewName, true);
		}

		PlayerState->OnRep_PlayerName();

		PlayerState->GetTeamIndex() = GameMode->Athena_PickTeamHook(GameMode, 0, Controller);

		static auto SquadIdOffset = PlayerState->GetOffset("SquadId", false);

		if (SquadIdOffset != -1)
			PlayerState->GetSquadId() = PlayerState->GetTeamIndex() - NumToSubtractFromSquadId;

		GameState->AddPlayerStateToGameMemberInfo(PlayerState);

		PlayerState->SetIsBot(true);

		Controller->Possess(Pawn);

		Pawn->SetHealth(21);
		Pawn->SetMaxHealth(21);
		Pawn->SetShield(21);

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

		auto PlayerAbilitySet = GetPlayerAbilitySet();
		auto AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();

		if (PlayerAbilitySet)
		{
			PlayerAbilitySet->GiveToAbilitySystem(AbilitySystemComponent);
		}

		auto AllHeroTypes = GetAllObjectsOfClass(FindObject<UClass>(L"/Script/FortniteGame.FortHeroType"));
		std::vector<UFortItemDefinition*> AthenaHeroTypes;

		UFortItemDefinition* HeroType = FindObject<UFortItemDefinition>(L"/Game/Athena/Heroes/HID_030_Athena_Commando_M_Halloween.HID_030_Athena_Commando_M_Halloween");

		int Fortnite_Season = std::floor(Fortnite_Version);

		if (Fortnite_Season != 14) {

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

		GameState->GetPlayersLeft()++;
		GameState->OnRep_PlayersLeft();

		if (auto FortPlayerControllerAthena = Cast<AFortPlayerControllerAthena>(Controller))
			GameMode->GetAlivePlayers().Add(FortPlayerControllerAthena);
	}
};

inline std::vector<PlayerBot> AllPlayerBotsToTick;

namespace Bots
{
	static AController* SpawnBot(FTransform SpawnTransform)
	{
		auto playerBot = PlayerBot();
		playerBot.Initialize(SpawnTransform);
		AllPlayerBotsToTick.push_back(playerBot);
		return playerBot.Controller;
	}
}

inline UFortServerBotManagerAthena* BotManager = nullptr;

class Boss
{
public:
	AFortAthenaAIBotController* Controller = nullptr;
	AFortPlayerPawnAthena* Pawn = nullptr;

public:
	void Initialize(AActor* SpawnLocator, const FTransform& SpawnTransform, UFortAthenaAIBotCustomizationData* CustomizationData)
	{
		auto PawnClass = CustomizationData->GetPawnClass();

		FVector SpawnLocation = SpawnTransform.Translation;
		FRotator SpawnRotation = SpawnTransform.Rotation.Rotator();

		Pawn = BotManager->GetCachedBotMutator()->SpawnBot(PawnClass, SpawnLocator, SpawnLocation, SpawnRotation, false);
		Controller = GetWorld()->SpawnActor<AFortAthenaAIBotController>(Pawn->GetAIControllerClass(), SpawnTransform);
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