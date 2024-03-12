#pragma once

#include "FortPlayerController.h"
#include "FortPlayerStateAthena.h"
#include "FortPlayerPawn.h"
#include "SoftObjectPtr.h"
#include "FortKismetLibrary.h"
#include "AthenaMarkerComponent.h"
#include "FortVolume.h"
#include "AthenaPlayerMatchReport.h"
#include "SoftClassPtr.h"
#include "FortScriptedAction.h"

static void ApplyHID(AFortPlayerPawn* Pawn, UObject* HeroDefinition, bool bUseServerChoosePart = false)
{
	using UFortHeroSpecialization = UObject;

	static auto SpecializationsOffset = HeroDefinition->GetOffset("Specializations");
	auto& Specializations = HeroDefinition->Get<TArray<TSoftObjectPtr<UFortHeroSpecialization>>>(SpecializationsOffset);

	auto PlayerState = Pawn->GetPlayerState();

	for (int i = 0; i < Specializations.Num(); i++)
	{
		auto& SpecializationSoft = Specializations.at(i);

		static auto FortHeroSpecializationClass = FindObject<UClass>(L"/Script/FortniteGame.FortHeroSpecialization");
		auto Specialization = SpecializationSoft.Get(FortHeroSpecializationClass, true);

		if (Specialization)
		{
			static auto Specialization_CharacterPartsOffset = Specialization->GetOffset("CharacterParts");
			auto& CharacterParts = Specialization->Get<TArray<TSoftObjectPtr<UObject>>>(Specialization_CharacterPartsOffset);

			static auto CustomCharacterPartClass = FindObject<UClass>(L"/Script/FortniteGame.CustomCharacterPart");

			if (bUseServerChoosePart)
			{
				for (int z = 0; z < CharacterParts.Num(); z++)
				{
					Pawn->ServerChoosePart((EFortCustomPartType)z, CharacterParts.at(z).Get(CustomCharacterPartClass, true));
				}

				continue; // hm?
			}

			bool aa;

			TArray<UObject*> CharacterPartsaa;

			for (int z = 0; z < CharacterParts.Num(); z++)
			{
				auto& CharacterPartSoft = CharacterParts.at(z, GetSoftObjectSize());
				auto CharacterPart = CharacterPartSoft.Get(CustomCharacterPartClass, true);

				CharacterPartsaa.Add(CharacterPart);

				continue;
			}

			UFortKismetLibrary::ApplyCharacterCosmetics(GetWorld(), CharacterPartsaa, PlayerState, &aa);
			CharacterPartsaa.Free();
		}
	}
}

static bool ApplyCID(AFortPlayerPawn* Pawn, UObject* CID, bool bUseServerChoosePart = false)
{
	if (!CID)
		return false;

	auto PlayerController = Cast<AFortPlayerController>(Pawn->GetController());

	if (!PlayerController)
		return false;

	if (bUseServerChoosePart)
	{
		if (Pawn)
		{

		}
	}

	/* auto PCCosmeticLoadout = PlayerController->GetCosmeticLoadout();

	if (!PCCosmeticLoadout)
	{
		LOG_INFO(LogCosmetics, "PCCosmeticLoadout is not set! Will not be able to apply skin.");
		return false;
	}

	auto PawnCosmeticLoadout = PlayerController->GetCosmeticLoadout();

	if (!PawnCosmeticLoadout)
	{
		LOG_INFO(LogCosmetics, "PawnCosmeticLoadout is not set! Will not be able to apply skin.");
		return false;
	}

	PCCosmeticLoadout->GetCharacter() = CID;
	PawnCosmeticLoadout->GetCharacter() = CID;
	PlayerController->ApplyCosmeticLoadout(); // would cause recursive

	return true; */

	if (Fortnite_Version == 1.72)
		return false;

	static auto HeroDefinitionOffset = CID->GetOffset("HeroDefinition");
	auto HeroDefinition = CID->Get(HeroDefinitionOffset);

	ApplyHID(Pawn, HeroDefinition, bUseServerChoosePart);

	// static auto HeroTypeOffset = PlayerState->GetOffset("HeroType");
	// PlayerState->Get(HeroTypeOffset) = HeroDefinition;

	return true;
}

struct FGhostModeRepData
{
	bool& IsInGhostMode()
	{
		static auto bInGhostModeOffset = FindOffsetStruct("/Script/FortniteGame.GhostModeRepData", "bInGhostMode");
		return *(bool*)(__int64(this) + bInGhostModeOffset);
	}

	UFortWorldItemDefinition*& GetGhostModeItemDef()
	{
		static auto GhostModeItemDefOffset = FindOffsetStruct("/Script/FortniteGame.GhostModeRepData", "GhostModeItemDef");
		return *(UFortWorldItemDefinition**)(__int64(this) + GhostModeItemDefOffset);
	}
};

enum class ESubGame : uint8
{
	Campaign = 0,
	Athena = 1,
	Invalid = 2,
	Count = 2,
	ESubGame_MAX = 3,
};

class UFortQuestItem : public UFortItem // UFortAccountItem
{
public:
	bool HasCompletedObjectiveWithName(FName BackendName)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortQuestItem.HasCompletedObjectiveWithName");

		struct
		{
			FName BackendName;
			bool ReturnValue;
		}params{ BackendName };

		this->ProcessEvent(fn, &params);

		return params.ReturnValue;
	}

	int32 GetNumObjectivesComplete()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortQuestItem.GetNumObjectivesComplete");

		struct
		{
			int32 ReturnValue;
		}params;

		this->ProcessEvent(fn, &params);

		return params.ReturnValue;
	}

	float GetPercentageComplete()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortQuestItem.GetPercentageComplete");

		struct
		{
			float ReturnValue;
		}params;

		this->ProcessEvent(fn, &params);

		return params.ReturnValue;
	}
};

enum class EFortQuestObjectiveItemEvent : uint8
{
	Craft = 0,
	Collect = 1,
	Acquire = 2,
	Consume = 3,
	OpenCardPack = 4,
	PurchaseCardPack = 5,
	Convert = 6,
	Upgrade = 7,
	UpgradeRarity = 8,
	QuestComplete = 9,
	AssignWorker = 10,
	LevelUpCollectionBook = 11,
	LevelUpAthenaSeason = 12,
	LevelUpBattlePass = 13,
	GainAthenaSeasonXp = 14,
	HasItem = 15,
	HasAccumulatedItem = 16,
	SlotInCollection = 17,
	AlterationRespec = 18,
	AlterationUpgrade = 19,
	HasCompletedQuest = 20,
	HasAssignedWorker = 21,
	HasUpgraded = 22,
	HasConverted = 23,
	HasUpgradedRarity = 24,
	HasLeveledUpCollectionBook = 25,
	SlotHeroInLoadout = 26,
	HasLeveledUpAthenaSeason = 27,
	HasLeveledUpBattlePass = 28,
	HasGainedAthenaSeasonXp = 29,
	MinigameTime = 30,
	Max_None = 31,
	EFortQuestObjectiveItemEvent_MAX = 32,
};

struct FFortMcpQuestObjectiveInfo
{
public:
	static std::string GetStructName()
	{
		return "/Script/FortniteGame.FortMcpQuestObjectiveInfo";
	}

	FName GetBackendName()
	{
		return *GetStructOffset<FName>(this, "BackendName");
	}

	FDataTableRowHandle& GetObjectiveStatHandle()
	{
		return *GetStructOffset<FDataTableRowHandle>(this, "ObjectiveStatHandle");
	}

	TArray<FDataTableRowHandle>& GetAlternativeStatHandles()
	{
		return *GetStructOffset<TArray<FDataTableRowHandle>>(this, "AlternativeStatHandles");
	}

	EFortQuestObjectiveItemEvent& GetItemEvent()
	{
		return *GetStructOffset<EFortQuestObjectiveItemEvent>(this, "ItemEvent");
	}

	TSoftObjectPtr<UFortItemDefinition>& GetItemReference()
	{
		return *GetStructOffset<TSoftObjectPtr<UFortItemDefinition>>(this, "ItemReference");
	}

	FString& GetItemTemplateIdOverride()
	{
		return *GetStructOffset<FString>(this, "ItemTemplateIdOverride");
	}

	FText& GetDescription()
	{
		return *GetStructOffset<FText>(this, "Description");
	}

	int& GetCount()
	{
		return *GetStructOffset<int>(this, "Count");
	}

	TSoftClassPtr<AFortScriptedAction>& GetScriptedAction()
	{
		return *GetStructOffset<TSoftClassPtr<AFortScriptedAction>>(this, "ScriptedAction");
	}
};

class UFortQuestItemDefinition : public UFortItemDefinition // UFortAccountItemDefinition
{
public:
	TArray<FFortMcpQuestObjectiveInfo> GetObjectives()
	{
		return Get<TArray<FFortMcpQuestObjectiveInfo>>("Objectives");
	}

	FText GetCompletionText()
	{
		static auto GetCompletionTextFn = FindObject<UFunction>("/Script/FortniteGame.FortQuestItemDefinition.GetCompletionText");
		FText ReturnValue;
		this->ProcessEvent(GetCompletionTextFn, &ReturnValue);
		return ReturnValue;
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>("/Script/FortniteGame.FortQuestItemDefinition");
		return Class;
	}
};

class UFortQuestManager : public UObject
{
public:
	UFortQuestItem* GetQuestWithDefinition(UFortQuestItemDefinition* Definition)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortQuestManager.GetQuestWithDefinition");

		struct
		{
			UFortQuestItemDefinition* Definition;
			UFortQuestItem* ReturnValue;
		}params{ Definition };

		this->ProcessEvent(fn, &params);

		return params.ReturnValue;
	}

	void SelfCompletedUpdatedQuest(AFortPlayerController* QuestOwner, UFortQuestItemDefinition* QuestDef, FName BackendName, int32 CompletionCount, int32 DeltaChange, AFortPlayerState* AssistingPlayer, bool ObjectiveCompleted, bool QuestCompleted)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortQuestManager.SelfCompletedUpdatedQuest");

		struct
		{
			AFortPlayerController* QuestOwner;
			UFortQuestItemDefinition* QuestDef;
			FName							   BackendName;
			int32                              CompletionCount;
			int32                              DeltaChange;
			AFortPlayerState* AssistingPlayer;
			bool                               ObjectiveCompleted;
			bool                               QuestCompleted;
		}params{ QuestOwner , QuestDef , BackendName , CompletionCount , DeltaChange , AssistingPlayer , ObjectiveCompleted , QuestCompleted };

		this->ProcessEvent(fn, &params);
	}

	void ClaimQuestReward(UFortQuestItem* Quest)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortQuestManager.ClaimQuestReward");
		this->ProcessEvent(fn, nullptr);
	}

	void SendComplexCustomStatEvent(UObject* TargetObject, const FGameplayTagContainer& AdditionalSourceTags, const FGameplayTagContainer& TargetTags, bool* QuestActive, bool* QuestCompleted, int32 Count)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortQuestManager.SendComplexCustomStatEvent");

		struct
		{
			UObject* TargetObject;
			FGameplayTagContainer AdditionalSourceTags;
			FGameplayTagContainer TargetTags;
			bool QuestActive;
			bool QuestCompleted;
			int32 Count;
		}params{ TargetObject , AdditionalSourceTags , TargetTags , Count };

		this->ProcessEvent(fn, &params);

		*QuestActive = params.QuestActive;
		*QuestCompleted = params.QuestCompleted;
	}
};

class AFortPlayerControllerAthena : public AFortPlayerController
{
public:
	static inline void (*GetPlayerViewPointOriginal)(AFortPlayerControllerAthena* PlayerController, FVector& Location, FRotator& Rotation);
	static inline void (*ServerReadyToStartMatchOriginal)(AFortPlayerControllerAthena* PlayerController);
	static inline void (*ServerRequestSeatChangeOriginal)(AFortPlayerControllerAthena* PlayerController, int TargetSeatIndex);
	static inline void (*EnterAircraftOriginal)(UObject* PC, AActor* Aircraft);
	static inline void (*StartGhostModeOriginal)(UObject* Context, FFrame* Stack, void* Ret);
	static inline void (*EndGhostModeOriginal)(AFortPlayerControllerAthena* PlayerController);

	UFortQuestManager* GetQuestManager(ESubGame SubGame)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerController.GetQuestManager");

		struct
		{
			ESubGame SubGame;
			UFortQuestManager* ReturnValue;
		}params{ SubGame };

		this->ProcessEvent(fn, &params);

		return params.ReturnValue;
	}

	void SpectateOnDeath() // actually in zone
	{
		static auto SpectateOnDeathFn = FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerControllerZone.SpectateOnDeath") ?
			FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerControllerZone.SpectateOnDeath") :
			FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerControllerAthena.SpectateOnDeath");

		this->ProcessEvent(SpectateOnDeathFn);
	}

	UFortWorldItemDefinition*& GetSwappingItemDefinition()
	{
		static auto SwappingItemDefinitionOffset = GetOffset("SwappingItemDefinition");
		return Get<UFortWorldItemDefinition*>(SwappingItemDefinitionOffset);
	}

	class UAthenaResurrectionComponent*& GetResurrectionComponent()
	{
		static auto ResurrectionComponentOffset = GetOffset("ResurrectionComponent");
		return Get<class UAthenaResurrectionComponent*>(ResurrectionComponentOffset);
	}

	AFortPlayerStateAthena* GetPlayerStateAthena()
	{
		return (AFortPlayerStateAthena*)GetPlayerState();
	}

	FGhostModeRepData* GetGhostModeRepData()
	{
		static auto GhostModeRepDataOffset = GetOffset("GhostModeRepData", false);

		if (GhostModeRepDataOffset == -1)
			return nullptr;

		return GetPtr<FGhostModeRepData>(GhostModeRepDataOffset);
	}

	bool IsInGhostMode()
	{
		auto GhostModeRepData = GetGhostModeRepData();

		if (!GhostModeRepData)
			return false;

		return GhostModeRepData->IsInGhostMode();
	}

	UAthenaMarkerComponent* GetMarkerComponent()
	{
		static auto MarkerComponentOffset = GetOffset("MarkerComponent");
		return Get<UAthenaMarkerComponent*>(MarkerComponentOffset);
	}

	AFortVolume*& GetCreativePlotLinkedVolume()
	{
		static auto CreativePlotLinkedVolumeOffset = GetOffset("CreativePlotLinkedVolume");
		return Get<AFortVolume*>(CreativePlotLinkedVolumeOffset);
	}

	void ClientClearDeathNotification() // actually in zone
	{
		auto ClientClearDeathNotificationFn = FindFunction("ClientClearDeathNotification");

		if (ClientClearDeathNotificationFn)
			this->ProcessEvent(ClientClearDeathNotificationFn);
	}

	UAthenaPlayerMatchReport*& GetMatchReport()
	{
		static auto MatchReportOffset = GetOffset("MatchReport");
		return Get<UAthenaPlayerMatchReport*>(MatchReportOffset);
	}

	void ClientSendTeamStatsForPlayer(FAthenaMatchTeamStats* TeamStats)
	{
		static auto ClientSendTeamStatsForPlayerFn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerControllerAthena.ClientSendTeamStatsForPlayer");
		static auto ParamSize = ClientSendTeamStatsForPlayerFn->GetPropertiesSize();
		auto Params = malloc(ParamSize);

		memcpy_s(Params, ParamSize, TeamStats, TeamStats->GetStructSize());

		this->ProcessEvent(ClientSendTeamStatsForPlayerFn, Params);

		free(Params);
	}

	void ClientSendMatchStatsForPlayer(FAthenaMatchStats* Stats)
	{
		static auto ClientSendMatchStatsForPlayerFn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerControllerAthena.ClientSendMatchStatsForPlayer");
		static auto ParamSize = ClientSendMatchStatsForPlayerFn->GetPropertiesSize();
		auto Params = malloc(ParamSize);

		memcpy_s(Params, ParamSize, Stats, Stats->GetStructSize());

		this->ProcessEvent(ClientSendMatchStatsForPlayerFn, Params/*Stats*/);

		return;

		// free(Params);
	}

	void RespawnPlayerAfterDeath(bool bEnterSkydiving)
	{
		static auto RespawnPlayerAfterDeathFn = FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerControllerAthena.RespawnPlayerAfterDeath");

		if (RespawnPlayerAfterDeathFn)
		{
			this->ProcessEvent(RespawnPlayerAfterDeathFn, &bEnterSkydiving);
		}
		else
		{
			// techinally we can remake this as all it really does on older versions is clear deathinfo (I think?)
		}
	}

	void ClientOnPawnRevived(AController* EventInstigator) // actually zone // idk what this actually does but i call it
	{
		static auto ClientOnPawnRevivedFn = FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerControllerZone.ClientOnPawnRevived");
		this->ProcessEvent(ClientOnPawnRevivedFn, &EventInstigator);
	}

	bool IsMarkedAlive()
	{
		static auto bMarkedAliveOffset = GetOffset("bMarkedAlive", false);

		if (bMarkedAliveOffset == -1) // nots ure if this is possible
			return true;

		static auto bMarkedAliveFieldMask = GetFieldMask(GetProperty("bMarkedAlive"));
		return ReadBitfieldValue(bMarkedAliveOffset, bMarkedAliveFieldMask);
	}

	static void StartGhostModeHook(UObject* Context, FFrame* Stack, void* Ret); // we could native hook this but eh
	static void EndGhostModeHook(AFortPlayerControllerAthena* PlayerController);
	static void ServerCreativeSetFlightSpeedIndexHook(UObject* Context, FFrame* Stack);
	static void EnterAircraftHook(UObject* PC, AActor* Aircraft);
	static void ServerRequestSeatChangeHook(AFortPlayerControllerAthena* PlayerController, int TargetSeatIndex); // actually in zone
	static void ServerRestartPlayerHook(AFortPlayerControllerAthena* Controller);
	static void ServerGiveCreativeItemHook(AFortPlayerControllerAthena* Controller, FFortItemEntry CreativeItem);
	static void ServerTeleportToPlaygroundLobbyIslandHook(AFortPlayerControllerAthena* Controller);
	static void ServerAcknowledgePossessionHook(APlayerController* Controller, APawn* Pawn);
	static void ServerPlaySquadQuickChatMessageHook(AFortPlayerControllerAthena* PlayerController, __int64 ChatEntry, __int64 SenderID);
	static void GetPlayerViewPointHook(AFortPlayerControllerAthena* PlayerController, FVector& Location, FRotator& Rotation);
	static void ServerReadyToStartMatchHook(AFortPlayerControllerAthena* PlayerController);
	static void UpdateTrackedAttributesHook(AFortPlayerControllerAthena* PlayerController);

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortPlayerControllerAthena");
		return Class;
	}
};