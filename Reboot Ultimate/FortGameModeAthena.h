#pragma once

#include "FortGameModePvPBase.h"
#include "FortGameStateAthena.h"
#include "KismetStringLibrary.h"
#include "reboot.h"
#include "BuildingSMActor.h"
#include "FortSafeZoneIndicator.h"
#include "GameplayStatics.h"
#include "FortAbilitySet.h"
#include "FortPlayerControllerAthena.h"
#include "FortItemDefinition.h"
#include "BuildingFoundation.h"

enum class EDynamicFoundationType : uint8
{
	Static = 0,
	StartEnabled_Stationary = 1,
	StartEnabled_Dynamic = 2,
	StartDisabled = 3,
	EDynamicFoundationType_MAX = 4,
};

enum class EDynamicFoundationEnabledState : uint8
{
	Unknown = 0,
	Enabled = 1,
	Disabled = 2,
	EDynamicFoundationEnabledState_MAX = 3,
};

static void SetFoundationTransform(AActor* BuildingFoundation, const FTransform& Transform)
{
	static auto DynamicFoundationRepDataOffset = BuildingFoundation->GetOffset("DynamicFoundationRepData", false);

	static auto DynamicFoundationTransformOffset = BuildingFoundation->GetOffset("DynamicFoundationTransform", false);

	if (DynamicFoundationTransformOffset != -1) // needed check?
	{
		*BuildingFoundation->GetPtr<FTransform>(DynamicFoundationTransformOffset) = Transform;
	}

	if (DynamicFoundationRepDataOffset != -1)
	{
		auto DynamicFoundationRepData = BuildingFoundation->GetPtr<void>(DynamicFoundationRepDataOffset);

		static auto RotationOffset = FindOffsetStruct("/Script/FortniteGame.DynamicBuildingFoundationRepData", "Rotation");
		static auto TranslationOffset = FindOffsetStruct("/Script/FortniteGame.DynamicBuildingFoundationRepData", "Translation");

		if (DynamicFoundationTransformOffset != -1) // needed check?
		{
			auto DynamicFoundationTransform = BuildingFoundation->GetPtr<FTransform>(DynamicFoundationTransformOffset);

			if (Fortnite_Version >= 13)
				*(FRotator*)(__int64(DynamicFoundationRepData) + RotationOffset) = DynamicFoundationTransform->Rotation.Rotator();
			else
				*(FQuat*)(__int64(DynamicFoundationRepData) + RotationOffset) = DynamicFoundationTransform->Rotation;

			*(FVector*)(__int64(DynamicFoundationRepData) + TranslationOffset) = DynamicFoundationTransform->Translation;
		}

		static auto OnRep_DynamicFoundationRepDataFn = FindObject<UFunction>(L"/Script/FortniteGame.BuildingFoundation.OnRep_DynamicFoundationRepData");
		BuildingFoundation->ProcessEvent(OnRep_DynamicFoundationRepDataFn);
	}
}

static inline UFortAbilitySet* GetPlayerAbilitySet()
{
	// There are some variables that contain this but it changes through versions soo..

	static auto GameplayAbilitySet = (UFortAbilitySet*)(Fortnite_Version >= 8.30
		? LoadObject(L"/Game/Abilities/Player/Generic/Traits/DefaultPlayer/GAS_AthenaPlayer.GAS_AthenaPlayer", UFortAbilitySet::StaticClass()) 
		: LoadObject(L"/Game/Abilities/Player/Generic/Traits/DefaultPlayer/GAS_DefaultPlayer.GAS_DefaultPlayer", UFortAbilitySet::StaticClass()));

	return GameplayAbilitySet;
}

static void ShowFoundation(AActor* BuildingFoundation, bool bShow = true)
{
	if (!BuildingFoundation)
	{
		LOG_WARN(LogGame, "Attempting to show invalid building foundation.");
		return;
	}

	LOG_INFO(LogDev, "{} {}", bShow ? "Showing" : "Hiding", BuildingFoundation->GetName());

	bool bServerStreamedInLevelValue = bShow; // ??

	static auto bServerStreamedInLevelFieldMask = GetFieldMask(BuildingFoundation->GetProperty("bServerStreamedInLevel"));
	static auto bServerStreamedInLevelOffset = BuildingFoundation->GetOffset("bServerStreamedInLevel");
	BuildingFoundation->SetBitfieldValue(bServerStreamedInLevelOffset, bServerStreamedInLevelFieldMask, bServerStreamedInLevelValue);

	static auto bFoundationEnabledOffset = BuildingFoundation->GetOffset("bFoundationEnabled", false);

	if (bFoundationEnabledOffset != -1)
	{
		static auto bFoundationEnabledFieldMask = GetFieldMask(BuildingFoundation->GetProperty("bFoundationEnabled"));
		BuildingFoundation->SetBitfieldValue(bFoundationEnabledOffset, bFoundationEnabledFieldMask, bShow);

		// theres a onrep too
	}

	static auto DynamicFoundationTypeOffset = BuildingFoundation->GetOffset("DynamicFoundationType", false);

	bool bChangeDynamicFoundationType = Fortnite_Version < 13;

	if (DynamicFoundationTypeOffset != -1 && bChangeDynamicFoundationType)
	{
		BuildingFoundation->Get<EDynamicFoundationType>(DynamicFoundationTypeOffset) = bShow ? EDynamicFoundationType::Static : EDynamicFoundationType::StartDisabled;
	}

	/* static auto bShowHLODWhenDisabledOffset = BuildingFoundation->GetOffset("bShowHLODWhenDisabled", false);

	if (bShowHLODWhenDisabledOffset != -1)
	{
		static auto bShowHLODWhenDisabledFieldMask = GetFieldMask(BuildingFoundation->GetProperty("bShowHLODWhenDisabled"));
		BuildingFoundation->SetBitfieldValue(bShowHLODWhenDisabledOffset, bShowHLODWhenDisabledFieldMask, true);
	} */

	static auto OnRep_ServerStreamedInLevelFn = FindObject<UFunction>(L"/Script/FortniteGame.BuildingFoundation.OnRep_ServerStreamedInLevel");
	BuildingFoundation->ProcessEvent(OnRep_ServerStreamedInLevelFn);

	static auto FoundationEnabledStateOffset = BuildingFoundation->GetOffset("FoundationEnabledState", false);

	LOG_INFO(LogDev, "BuildingFoundation->Get<uint8_t>(FoundationEnabledStateOffset) Prev: {}", (int)BuildingFoundation->Get<uint8_t>(FoundationEnabledStateOffset));

	if (FoundationEnabledStateOffset != -1)
		BuildingFoundation->Get<EDynamicFoundationEnabledState>(FoundationEnabledStateOffset) = bShow ? EDynamicFoundationEnabledState::Enabled : EDynamicFoundationEnabledState::Disabled;

	static auto LevelToStreamOffset = BuildingFoundation->GetOffset("LevelToStream");
	auto& LevelToStream = BuildingFoundation->Get<FName>(LevelToStreamOffset);

	/* if (bShow)
	{
		UGameplayStatics::LoadStreamLevel(GetWorld(), LevelToStream, true, false, FLatentActionInfo());
	}
	else
	{
		UGameplayStatics::UnloadStreamLevel(GetWorld(), LevelToStream, FLatentActionInfo(), false);
	} */

	static auto OnRep_LevelToStreamFn = FindObject<UFunction>(L"/Script/FortniteGame.BuildingFoundation.OnRep_LevelToStream");
	BuildingFoundation->ProcessEvent(OnRep_LevelToStreamFn);

	static auto DynamicFoundationRepDataOffset = BuildingFoundation->GetOffset("DynamicFoundationRepData", false);

	if (DynamicFoundationRepDataOffset != -1)
	{
		auto DynamicFoundationRepData = BuildingFoundation->GetPtr<void>(DynamicFoundationRepDataOffset);

		static auto EnabledStateOffset = FindOffsetStruct("/Script/FortniteGame.DynamicBuildingFoundationRepData", "EnabledState");
		*(EDynamicFoundationEnabledState*)(__int64(DynamicFoundationRepData) + EnabledStateOffset) = bShow ? EDynamicFoundationEnabledState::Enabled : EDynamicFoundationEnabledState::Disabled;

		if (false)
		{
			static auto TranslationOffset = FindOffsetStruct("/Script/FortniteGame.DynamicBuildingFoundationRepData", "Translation");
			static auto RotationOffset = FindOffsetStruct("/Script/FortniteGame.DynamicBuildingFoundationRepData", "Rotation");

			*(FVector*)(__int64(DynamicFoundationRepData) + TranslationOffset) = BuildingFoundation->GetActorLocation();

			const FRotator BuildingRotation = BuildingFoundation->GetActorRotation();

			if (Fortnite_Version >= 13)
				*(FRotator*)(__int64(DynamicFoundationRepData) + RotationOffset) = BuildingRotation;
			else
				*(FQuat*)(__int64(DynamicFoundationRepData) + RotationOffset) = BuildingRotation.Quaternion();

			static auto OnRep_DynamicFoundationRepDataFn = FindObject<UFunction>(L"/Script/FortniteGame.BuildingFoundation.OnRep_DynamicFoundationRepData");
			BuildingFoundation->ProcessEvent(OnRep_DynamicFoundationRepDataFn);
		}
		else
		{
			SetFoundationTransform(BuildingFoundation, BuildingFoundation->GetTransform());
		}
	}

	BuildingFoundation->FlushNetDormancy();
	BuildingFoundation->ForceNetUpdate();
}

struct FDynamicBuildingFoundationRepData
{
public:
	static UStruct* GetStruct()
	{
		static auto Struct = FindObject<UStruct>("/Script/FortniteGame.DynamicBuildingFoundationRepData");
		return Struct;
	}

	static int GetStructSize() { return GetStruct()->GetPropertiesSize(); }

	EDynamicFoundationEnabledState& GetEnabledState()
	{
		static auto EnabledStateOffset = FindOffsetStruct("/Script/FortniteGame.DynamicBuildingFoundationRepData", "EnabledState");
		return *(EDynamicFoundationEnabledState*)(__int64(this) + EnabledStateOffset);
	}
};

static void ShowFoundationTwoPointO(ABuildingFoundation* Foundation)
{
	if (!Foundation)
	{
		LOG_WARN(LogGame, "Attempting to show invalid foundation!");
		return;
	}

	static auto DynamicFoundationTypeOffset = FindOffsetStruct("/Script/FortniteGame.BuildingFoundation", "DynamicFoundationType");
	*(EDynamicFoundationType*)(__int64(Foundation) + DynamicFoundationTypeOffset) = EDynamicFoundationType::Static;

	static auto IsServerStreamedInLevelOffset = FindOffsetStruct("/Script/FortniteGame.BuildingFoundation", "bServerStreamedInLevel");
	*(bool*)(__int64(Foundation) + IsServerStreamedInLevelOffset) = true;

	static auto OnRep_ServerStreamedInLevelFn = FindObject<UFunction>("/Script/FortniteGame.BuildingFoundation.OnRep_ServerStreamedInLevel");
	Foundation->ProcessEvent(OnRep_ServerStreamedInLevelFn);

	static auto DynamicFoundationRepDataOffset = FindOffsetStruct("/Script/FortniteGame.BuildingFoundation", "DynamicFoundationRepData");
	// (*(FDynamicBuildingFoundationRepData**)(__int64(Foundation) + DynamicFoundationRepDataOffset))->GetEnabledState() = EDynamicFoundationEnabledState::Enabled;

	static auto FoundationEnabledStateOffset = FindOffsetStruct("/Script/FortniteGame.BuildingFoundation", "FoundationEnabledState");
	*(EDynamicFoundationEnabledState*)(__int64(Foundation) + FoundationEnabledStateOffset) = EDynamicFoundationEnabledState::Enabled;

	static auto OnRep_DynamicFoundationRepDataFn = FindObject<UFunction>("/Script/FortniteGame.BuildingFoundation.OnRep_DynamicFoundationRepData");
	Foundation->ProcessEvent(OnRep_DynamicFoundationRepDataFn);

	static auto SetDynamicFoundationEnabledFn = FindObject<UFunction>("/Script/FortniteGame.BuildingFoundation.SetDynamicFoundationEnabled");
	bool bEnabled = true;
	Foundation->ProcessEvent(SetDynamicFoundationEnabledFn, &bEnabled);
}

static void StreamLevel(const std::string& LevelName, FVector Location = {})
{
	static auto BuildingFoundation3x3Class = FindObject<UClass>(L"/Script/FortniteGame.BuildingFoundation3x3");
	FTransform Transform{};
	Transform.Scale3D = { 1, 1, 1 };
	Transform.Translation = Location;
	auto BuildingFoundation = GetWorld()->SpawnActor<ABuildingSMActor>(BuildingFoundation3x3Class, Transform);

	if (!BuildingFoundation)
	{
		LOG_ERROR(LogGame, "Failed to spawn BuildingFoundation for streaming!");
		return;
	}

	static auto FoundationNameOffset = FindOffsetStruct("/Script/FortniteGame.BuildingFoundationStreamingData", "FoundationName");
	static auto FoundationLocationOffset = FindOffsetStruct("/Script/FortniteGame.BuildingFoundationStreamingData", "FoundationLocation");
	static auto StreamingDataOffset = BuildingFoundation->GetOffset("StreamingData");
	static auto LevelToStreamOffset = BuildingFoundation->GetOffset("LevelToStream");

	auto StreamingData = BuildingFoundation->GetPtr<__int64>(StreamingDataOffset);

	*(FName*)(__int64(StreamingData) + FoundationNameOffset) = UKismetStringLibrary::Conv_StringToName(std::wstring(LevelName.begin(), LevelName.end()).c_str());
	*(FVector*)(__int64(StreamingData) + FoundationLocationOffset) = Location;

	*(FName*)(__int64(BuildingFoundation) + LevelToStreamOffset) = UKismetStringLibrary::Conv_StringToName(std::wstring(LevelName.begin(), LevelName.end()).c_str());

	static auto OnRep_LevelToStreamFn = FindObject<UFunction>(L"/Script/FortniteGame.BuildingFoundation.OnRep_LevelToStream");
	BuildingFoundation->ProcessEvent(OnRep_LevelToStreamFn);

	ShowFoundation(BuildingFoundation);
}

class UFortSupplyDropInfo : public UObject // UDataAsset
{
public:
};

class AFortGameModeAthena : public AFortGameModePvPBase
{
public:
	static inline bool (*Athena_ReadyToStartMatchOriginal)(AFortGameModeAthena* GameMode);
	static inline void (*Athena_HandleStartingNewPlayerOriginal)(AFortGameModeAthena* GameMode, AActor* NewPlayer);
	static inline void (*SetZoneToIndexOriginal)(AFortGameModeAthena* GameModeAthena, int OverridePhaseMaybeIDFK);
	static inline void (*OnAircraftEnteredDropZoneOriginal)(AFortGameModeAthena* GameModeAthena, AActor* Aircraft);

	AFortSafeZoneIndicator*& GetSafeZoneIndicator()
	{
		static auto SafeZoneIndicatorOffset = GetOffset("SafeZoneIndicator");
		return Get<AFortSafeZoneIndicator*>(SafeZoneIndicatorOffset);
	}

	AFortGameStateAthena* GetGameStateAthena()
	{
		return (AFortGameStateAthena*)GetGameState();
	}

	TArray<FItemAndCount>& GetStartingItems() // really in zone
	{
		static auto StartingItemsOffset = GetOffset("StartingItems");
		return Get<TArray<FItemAndCount>>(StartingItemsOffset);
	}

	TArray<AFortPlayerControllerAthena*>& GetAlivePlayers()
	{
		static auto AlivePlayersOffset = GetOffset("AlivePlayers");
		return Get<TArray<AFortPlayerControllerAthena*>>(AlivePlayersOffset);
	}

	FName RedirectLootTier(const FName& LootTier);
	UClass* GetVehicleClassOverride(UClass* DefaultClass);
	void SkipAircraft();
	void PauseSafeZone(bool bPaused = true);
	void StartAircraftPhase();

	static void OverrideBattleBus(AFortGameStateAthena* GameState, UObject* OverrideBattleBusSkin);
	static void OverrideSupplyDrop(AFortGameStateAthena* GameState, UClass* OverrideSupplyDropBusClass);
	static void HandleSpawnRateForActorClass(UClass* ActorClass, float SpawnPercentage); // idk where to put

	static void OnAircraftEnteredDropZoneHook(AFortGameModeAthena* GameModeAthena, AActor* Aircraft);
	static bool Athena_ReadyToStartMatchHook(AFortGameModeAthena* GameMode);
	static int Athena_PickTeamHook(AFortGameModeAthena* GameMode, uint8 preferredTeam, AActor* Controller);
	static void Athena_HandleStartingNewPlayerHook(AFortGameModeAthena* GameMode, AActor* NewPlayerActor);
	static void SetZoneToIndexHook(AFortGameModeAthena* GameModeAthena, int OverridePhaseMaybeIDFK);
};