#pragma once

#include "FortPlayerController.h"
#include "FortPlayerStateAthena.h"
#include "FortPlayerPawn.h"
#include "SoftObjectPtr.h"
#include "FortKismetLibrary.h"
#include "AthenaMarkerComponent.h"
#include "FortVolume.h"
#include "AthenaPlayerMatchReport.h"
#include "FortItem.h"
#include <map>
#include "FortGameStateAthena.h"
#include "FortPlaylist.h"
#include "GameplayTagContainer.h"
#include "FortWeaponMeleeItemDefinition.h"

enum class EQuitPreference : uint8
{
	Quit = 0,
	Background = 1,
	EQuitPreference_MAX = 2,
};

enum class EAthenaWinCondition : uint8
{
	LastManStanding = 0,
	LastManStandingIncludingAllies = 1,
	TimedTeamFinalFight = 2,
	FirstToGoalScore = 3,
	TimedLastMenStanding = 4,
	MutatorControlled = 5,
	MutatorControlledGoalScore = 6,
	MutatorControlledChinaSupported = 7,
	EAthenaWinCondition_MAX = 8,
};

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

enum class EDeathCause : uint8
{
	OutsideSafeZone = 0,
	FallDamage = 1,
	Pistol = 2,
	Shotgun = 3,
	Rifle = 4,
	SMG = 5,
	Sniper = 6,
	SniperNoScope = 7,
	Melee = 8,
	InfinityBlade = 9,
	Grenade = 10,
	C4 = 11,
	GrenadeLauncher = 12,
	RocketLauncher = 13,
	Minigun = 14,
	Bow = 15,
	Trap = 16,
	DBNOTimeout = 17,
	Banhammer = 18,
	RemovedFromGame = 19,
	MassiveMelee = 20,
	MassiveDiveBomb = 21,
	MassiveRanged = 22,
	Vehicle = 23,
	ShoppingCart = 24,
	ATK = 25,
	QuadCrasher = 26,
	Biplane = 27,
	BiplaneGun = 28,
	LMG = 29,
	GasGrenade = 30,
	InstantEnvironmental = 31,
	InstantEnvironmentalFellOutOfWorld = 32,
	InstantEnvironmentalUnderLandscape = 33,
	Turret = 34,
	ShipCannon = 35,
	Cube = 36,
	Balloon = 37,
	StormSurge = 38,
	Lava = 39,
	BasicFiend = 40,
	EliteFiend = 41,
	RangedFiend = 42,
	BasicBrute = 43,
	EliteBrute = 44,
	MegaBrute = 45,
	SilentSwitchingToSpectate = 46,
	LoggedOut = 47,
	TeamSwitchSuicide = 48,
	WonMatch = 49,
	Unspecified = 50,
	EDeathCause_MAX = 51,
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
	bool HasCompletedObjectiveWithName(class FName BackendName)
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

class UFortQuestItemDefinition : public UFortItemDefinition // UFortAccountItemDefinition
{
public:
};

class UQuestInteractableComponent : public UActorComponent // USceneComponent
{
public:
	bool& IsReady()
	{
		static auto bReadyOffset = FindOffsetStruct("/Script/FortniteGame.QuestInteractableComponent", "bReady");
		return *(bool*)(__int64(this) + bReadyOffset);
	}

	UFortQuestItemDefinition* GetQuestItemDefinition()
	{
		static auto QuestItemDefinitionOffset = FindOffsetStruct("/Script/FortniteGame.QuestInteractableComponent", "QuestItemDefinition");
		return *(UFortQuestItemDefinition**)(__int64(this) + QuestItemDefinitionOffset);
	}

	FName GetObjectiveBackendName()
	{
		static auto ObjectiveBackendNameOffset = FindOffsetStruct("/Script/FortniteGame.QuestInteractableComponent", "ObjectiveBackendName");
		return *(FName*)(__int64(this) + ObjectiveBackendNameOffset);
	}

	void OnPlaylistDataReady(AFortGameStateAthena* GameState, UFortPlaylist* Playlist, FGameplayTagContainer& PlaylistContextTags)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.QuestInteractableComponent.OnPlaylistDataReady");

		struct
		{
			AFortGameStateAthena* GameState;
			UFortPlaylist* Playlist;
			FGameplayTagContainer       PlaylistContextTags;
		}params{ GameState , Playlist , PlaylistContextTags };

		this->ProcessEvent(fn, &params);
	}

	void OnCalendarUpdated()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.QuestInteractableComponent.OnCalendarUpdated");
		this->ProcessEvent(fn);
	}

	void OnRep_Ready()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.QuestInteractableComponent.OnRep_Ready");
		this->ProcessEvent(fn);
	}
};

class UFortQuestManager : public UObject
{
public:
	void InitializeQuestAbilities(APawn* PlayerPawn)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortQuestManager.InitializeQuestAbilities");

		struct
		{
			APawn* PlayerPawn;
		}params{ PlayerPawn };

		this->ProcessEvent(fn, &params);
	}

	UFortQuestItem* GetQuestWithDefinition(class UFortQuestItemDefinition* Definition)
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

	void SelfCompletedUpdatedQuest(class AFortPlayerController* QuestOwner, class UFortQuestItemDefinition* QuestDef, class FName BackendName, int32 CompletionCount, int32 DeltaChange, class AFortPlayerState* AssistingPlayer, bool ObjectiveCompleted, bool QuestCompleted)
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

	void ClaimQuestReward(class UFortQuestItem* Quest)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortQuestManager.ClaimQuestReward");
		this->ProcessEvent(fn, nullptr);
	}
};

struct FAthenaRewardResult
{
public:
	int32                                        LevelsGained;                                      // 0x0(0x4)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        BookLevelsGained;                                  // 0x4(0x4)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        TotalSeasonXpGained;                               // 0x8(0x4)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        TotalBookXpGained;                                 // 0xC(0x4)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        PrePenaltySeasonXpGained;                          // 0x10(0x4)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_423A[0x4];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FAthenaMatchXpMultiplierGroup> XpMultipliers;                                     // 0x18(0x10)(ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<struct FAthenaAwardGroup>             Rewards;                                           // 0x28(0x10)(ZeroConstructor, NativeAccessSpecifierPublic)
	float                                        AntiAddictionMultiplier;                           // 0x38(0x4)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_423B[0x4];                                     // Fixing Size Of Struct [ Dumper-7 ]
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
	static inline void (*ServerCreativeSetFlightSpeedIndexOriginal)(UObject* Context, FFrame& Stack, void* Ret);

	static void GiveXP(AFortPlayerControllerAthena* PC, int CombatXP, int SurvivalXP, int BonusMedalXP, int ChallengeXP, int MatchXP);
	static void ProgressQuest(AFortPlayerControllerAthena* PC, UFortQuestItemDefinition* QuestDef, FName Primary_BackendName);
	static void GiveAccolade(AFortPlayerControllerAthena* PC, UFortAccoladeItemDefinition* Def);

	void ClientSendEndBattleRoyaleMatchForPlayer(bool bSuccess, struct FAthenaRewardResult& Result)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerControllerAthena.ClientSendEndBattleRoyaleMatchForPlayer");

		struct
		{
			bool                               bSuccess;
			FAthenaRewardResult         Result;
		}params{ bSuccess , Result };

		this->ProcessEvent(fn, &params);
	}

	UFortQuestManager* GetQuestManager(enum class ESubGame SubGame)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerController.GetQuestManager");

		struct
		{
			enum class ESubGame                SubGame;
			class UFortQuestManager* ReturnValue;
		}params{ SubGame };

		this->ProcessEvent(fn, &params);

		return params.ReturnValue;
	}

	void PlayWinEffects(class APawn* FinisherPawn, class UFortWeaponItemDefinition* FinishingWeapon, enum class EDeathCause DeathCause, bool bAudioOnly)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerControllerAthena.PlayWinEffects");

		struct
		{
			APawn* FinisherPawn;
			UFortWeaponItemDefinition* FinishingWeapon;
			EDeathCause DeathCause;
			bool bAudioOnly;
		}params{FinisherPawn,FinishingWeapon,DeathCause,bAudioOnly};

		this->ProcessEvent(fn, &params);
	}

	void ClientNotifyWon(class APawn* FinisherPawn, class UFortWeaponItemDefinition* FinishingWeapon, enum class EDeathCause DeathCause)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerControllerAthena.ClientNotifyWon");

		struct
		{
			APawn* FinisherPawn;
			UFortWeaponItemDefinition* FinishingWeapon;
			EDeathCause DeathCause;
		}params{ FinisherPawn,FinishingWeapon,DeathCause};

		this->ProcessEvent(fn, &params);
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

		this->ProcessEvent(ClientSendMatchStatsForPlayerFn, Params);

		free(Params);
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

	void QuitGame(class UObject* WorldContextObject, class APlayerController* SpecificPlayer, enum class EQuitPreference QuitPreference, bool bIgnorePlatformRestrictions)
	{
		auto QuitGameFn = FindObject<UFunction>("/Script/Engine.KismetSystemLibrary.QuitGame");

		struct
		{
			class UObject* WorldContextObject;                                               //(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			class APlayerController* SpecificPlayer;                                                   //(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			enum class EQuitPreference         QuitPreference;                                                   //(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			bool                               bIgnorePlatformRestrictions;                                      //(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
		}UKismetSystemLibrary_QuitGame_Params{ WorldContextObject , SpecificPlayer , QuitPreference , bIgnorePlatformRestrictions };

		this->ProcessEvent(QuitGameFn, &UKismetSystemLibrary_QuitGame_Params);
	}

	static void StartGhostModeHook(UObject* Context, FFrame* Stack, void* Ret); // we could native hook this but eh
	static void EndGhostModeHook(AFortPlayerControllerAthena* PlayerController);
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
	static void ServerCreativeSetFlightSpeedIndexHook(UObject* Context, FFrame& Stack, void* Ret); // this just does not get called idk

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortPlayerControllerAthena");
		return Class;
	}
};

static std::map<AFortPlayerControllerAthena*, int> ReviveCounts{};

class UFortSpyTechItemDefinition : public UFortItemDefinition // UFortAccountItemDefinition
{
public:
};

class UFortAccoladeItemDefinition : public UFortItemDefinition // UFortPersistableItemDefinition
{
public:
	EXPEventPriorityType GetPriority()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortAccoladeItemDefinition.GetPriority");

		EXPEventPriorityType    ReturnValue;

		this->ProcessEvent(fn, &ReturnValue);

		return ReturnValue;
	}

	int32 GetAccoladeXpValue()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortAccoladeItemDefinition.GetAccoladeXpValue");

		int32 ReturnValue;

		this->ProcessEvent(fn, &ReturnValue);

		return ReturnValue;
	}
};

enum class EAccoladeEvent : uint8
{
	Kill,
	Search,
	MAX
};

static inline UFortAccoladeItemDefinition* GetDefFromEvent(EAccoladeEvent Event, int Count, UObject* Object = nullptr)
{
	UFortAccoladeItemDefinition* Def = nullptr;

	switch (Event)
	{
	case EAccoladeEvent::Kill:
		if (Count == 1)
		{
			Def = FindObject<UFortAccoladeItemDefinition>("/Game/Athena/Items/Accolades/AccoladeId_014_Elimination_Bronze.AccoladeId_014_Elimination_Bronze");
		}
		else if (Count == 4)
		{
			Def = FindObject<UFortAccoladeItemDefinition>("/Game/Athena/Items/Accolades/AccoladeId_015_Elimination_Silver.AccoladeId_015_Elimination_Silver");
		}
		else if (Count == 8)
		{
			Def = FindObject<UFortAccoladeItemDefinition>("/Game/Athena/Items/Accolades/AccoladeId_016_Elimination_Gold.AccoladeId_016_Elimination_Gold");
		}
		else
		{
			Def = FindObject<UFortAccoladeItemDefinition>("/Game/Athena/Items/Accolades/AccoladeId_012_Elimination.AccoladeId_012_Elimination");
		}
		break;
	case EAccoladeEvent::Search:
		if (!Object || !Object->ClassPrivate->GetName().contains("Ammo"))
		{
			if (Count == 3)
			{
				Def = FindObject<UFortAccoladeItemDefinition>("/Game/Athena/Items/Accolades/AccoladeId_008_SearchChests_Bronze.AccoladeId_008_SearchChests_Bronze");
			}
			else if (Count == 7)
			{
				Def = FindObject<UFortAccoladeItemDefinition>("/Game/Athena/Items/Accolades/AccoladeId_009_SearchChests_Silver.AccoladeId_009_SearchChests_Silver");
			}
			else if (Count == 12)
			{
				Def = FindObject<UFortAccoladeItemDefinition>("/Game/Athena/Items/Accolades/AccoladeId_010_SearchChests_Gold.AccoladeId_010_SearchChests_Gold");
			}
			else
			{
				Def = FindObject<UFortAccoladeItemDefinition>("/Game/Athena/Items/Accolades/AccoladeId_007_SearchChests.AccoladeId_007_SearchChests");
			}
		}
		else
		{
			Def = FindObject<UFortAccoladeItemDefinition>("/Game/Athena/Items/Accolades/AccoladeId_011_SearchAmmoBox.AccoladeId_011_SearchAmmoBox");
		}
		break;
	case EAccoladeEvent::MAX:
		break;
	default:
		break;
	}

	return Def;
}