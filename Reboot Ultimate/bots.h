#pragma once

#include "FortGameModeAthena.h"
#include "FortAthenaAIBotController.h"
#include "FortAIPawn.h"
#include "FortAthenaAIBotCustomizationData.h"
#include "FortServerBotManagerAthena.h"
#include "FortAthenaAISpawnerData.h"
#include "KismetTextLibrary.h"

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
	void Initialize(const FTransform& SpawnTransform, AActor* SpawnActor = nullptr)
	{
		auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

		static UClass* PawnClass = nullptr;
		static UClass* ControllerClass = nullptr;

		bool bUseAIBotController = Fortnite_Version >= 11 && Engine_Version < 500;

		if (!bUseAIBotController)
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
			PlayerState->SetIsBot(true);
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
						std::shuffle(PlayerBotNames.begin(), PlayerBotNames.end(), std::default_random_engine((unsigned int)time(0)));

						int RandomIndex = std::rand() % PlayerBotNames.size();
						std::string RandomBotName = PlayerBotNames[RandomIndex];
						RandomBotName.erase(std::remove_if(RandomBotName.begin(), RandomBotName.end(), [](char c) { return std::isspace(static_cast<unsigned char>(c)); }), RandomBotName.end());
						NewName = std::wstring(RandomBotName.begin(), RandomBotName.end()).c_str();
						PlayerBotNames.erase(PlayerBotNames.begin() + RandomIndex);
					}
				}
			}
		}

		if (Fortnite_Version < 9)
		{
			if (auto PlayerController = Cast<AFortPlayerController>(Controller))
				PlayerController->ServerChangeName(NewName);
		}
		else
		{
			GameMode->ChangeName(Controller ? Controller : AIBotController, NewName, true);
		}

		LOG_INFO(LogBots, "NewName: {}", NewName.ToString());

		PlayerState->GetTeamIndex() = GameMode->Athena_PickTeamHook(GameMode, 0, Controller ? Controller : AIBotController);

		static auto SquadIdOffset = PlayerState->GetOffset("SquadId", false);

		if (SquadIdOffset != -1)
			PlayerState->GetSquadId() = PlayerState->GetTeamIndex() - NumToSubtractFromSquadId;

		GameState->AddPlayerStateToGameMemberInfo(PlayerState);

		Pawn->SetHealth(21);
		Pawn->SetMaxHealth(21);
		Pawn->SetShield(21);

		auto PlayerAbilitySet = GetPlayerAbilitySet();
		auto AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();

		if (PlayerAbilitySet)
		{
			PlayerAbilitySet->GiveToAbilitySystem(AbilitySystemComponent);
		}

		if (!bUseAIBotController)
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

			GameState->GetPlayersLeft()++;
			GameState->OnRep_PlayersLeft();
		}

		if (auto FortPlayerControllerAthena = Cast<AFortPlayerControllerAthena>(Controller))
			GameMode->GetAlivePlayers().Add(FortPlayerControllerAthena);
		// if (AIBotController)
			// GameMode->GetAliveBots().Add(AIBotController);
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

		if (bDidSomeoneWin && !GameState->IsRespawningAllowed(PlayerState))
		{
			LOG_INFO(LogDev, "Won!");

			TArray<AFortPlayerControllerAthena*> PlayerControllersArray;

			if (KillerController)
				PlayerControllersArray.Add(KillerController);

			for (int i = 0; i < KillerState->GetPlayerTeam()->GetTeamMembers().Num(); ++i)
				PlayerControllersArray.Add(Cast<AFortPlayerControllerAthena>(KillerState->GetPlayerTeam()->GetTeamMembers().at(i)));

			for (int i = 0; i < PlayerControllersArray.Num(); ++i)
			{
				auto ArrayController = PlayerControllersArray.at(i);
				auto ArrayPlayerState = ArrayController->GetPlayerStateAthena();
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

				ArrayPlayerState->GetPlace() = 1;
				ArrayPlayerState->OnRep_Place();
			}

			GameState->GetWinningPlayerState() = KillerState ? KillerState : PlayerState;
			GameState->GetWinningTeam() = KillerState ? KillerState->GetTeamIndex() : PlayerState->GetTeamIndex();
			GameState->OnRep_WinningPlayerState();
			GameState->OnRep_WinningTeam();
			GameMode->EndMatch();
		}

		if (AIBotController)
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

public:
	void Initialize(AActor* SpawnLocator, const FTransform& SpawnTransform, UFortAthenaAIBotCustomizationData* CustomizationData)
	{
		auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
		auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

		auto PawnClass = CustomizationData->GetPawnClass();
		auto BehaviorTree = CustomizationData->GetBehaviorTree();
		auto BotNameSettings = CustomizationData->GetBotNameSettings();

		FVector SpawnLocation = SpawnTransform.Translation;
		FRotator SpawnRotation = SpawnTransform.Rotation.Rotator();

		Pawn = BotManager->GetCachedBotMutator()->SpawnBot(PawnClass, SpawnLocator, SpawnLocation, SpawnRotation, false);

		if (Fortnite_Version >= 17)
			Controller = GetWorld()->SpawnActor<AFortAthenaAIBotController>(Pawn->GetAIControllerClass(), SpawnTransform);
		else
			Controller = Cast<AFortAthenaAIBotController>(Pawn->GetController());

		PlayerState = Cast<AFortPlayerStateAthena>(Controller->GetPlayerState());

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

		static auto HeroDefinitionOffset = CharacterToApply->GetOffset("HeroDefiniton");

		if (HeroDefinitionOffset != 1)
		{
			auto HeroDefinition = CharacterToApply->Get(HeroDefinitionOffset);

			if (HeroDefinition)
				ApplyHID(Pawn, HeroDefinition, true);
		}

		FString OverrideName = UKismetTextLibrary::Conv_TextToString(BotNameSettings->GetOverrideName());

		GameMode->ChangeName(Controller, OverrideName, false);
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