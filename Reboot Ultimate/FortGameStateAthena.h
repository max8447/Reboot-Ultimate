#pragma once

#include "GameState.h"
#include "FortPlayerStateAthena.h"
#include "FortPlaylistAthena.h"
#include "BuildingStructuralSupportSystem.h"
#include "ScriptInterface.h"
#include "Interface.h"
#include "FortAthenaMapInfo.h"
#include "FortGameplayMutator.h"
// #include "FortGameModeAthena.h"
#include "Actor.h"

enum class EAthenaGamePhaseStep : uint8_t // idk if this changes
{
	None = 0,
	Setup = 1,
	Warmup = 2,
	GetReady = 3,
	BusLocked = 4,
	BusFlying = 5,
	StormForming = 6,
	StormHolding = 7,
	StormShrinking = 8,
	Countdown = 9,
	FinalCountdown = 10,
	EndGame = 11,
	Count = 12,
	EAthenaGamePhaseStep_MAX = 13
};

enum class EAthenaGamePhase : uint8_t
{
	None = 0,
	Setup = 1,
	Warmup = 2,
	Aircraft = 3,
	SafeZones = 4,
	EndGame = 5,
	Count = 6,
	EAthenaGamePhase_MAX = 7
};

struct FAircraftFlightInfo
{
	float& GetTimeTillDropStart()
	{
		static auto TimeTillDropStartOffset = FindOffsetStruct("/Script/FortniteGame.AircraftFlightInfo", "TimeTillDropStart");
		return *(float*)(__int64(this) + TimeTillDropStartOffset);
	}

	FVector& GetFlightStartLocation()
	{
		static auto FlightStartLocationOffset = FindOffsetStruct("/Script/FortniteGame.AircraftFlightInfo", "FlightStartLocation");
		return *(FVector*)(__int64(this) + FlightStartLocationOffset);
	}

	float& GetFlightSpeed()
	{
		static auto FlightSpeedOffset = FindOffsetStruct("/Script/FortniteGame.AircraftFlightInfo", "FlightSpeed");
		return *(float*)(__int64(this) + FlightSpeedOffset);
	}

	static UStruct* GetStruct()
	{
		static auto Struct = FindObject<UStruct>("/Script/FortniteGame.AircraftFlightInfo");
		return Struct;
	}

	static int GetStructSize()
	{
		return GetStruct()->GetPropertiesSize();
	}
};

class UFortSafeZoneInterface : public UInterface
{
public:
	static UClass* StaticClass()
	{
		static auto Struct = FindObject<UClass>(L"/Script/FortniteGame.FortSafeZoneInterface");
		return Struct;
	}
};

struct TeamsArrayContainer // THANK ANDROIDDD!!!!
{
	TArray<TArray<TWeakObjectPtr<AFortPlayerStateAthena>>> TeamsArray; // 13D0
	TArray<int> TeamIdk1; // 13E0
	TArray<int> TeamIndexesArray; // 13F0

	uintptr_t idfk; //(or 2 ints) // 1400

	TArray<TArray<TWeakObjectPtr<AFortPlayerStateAthena>>> SquadsArray; // Index = SquadId // 1408
	TArray<int> SquadIdk1; // 1418
	TArray<int> SquadIdsArray; // 0x1428
};

struct FPlayerBuildableClassContainer
{
	TArray<UClass*>                              BuildingClasses;                                          // 0x0000(0x0010) (ZeroConstructor, Transient, UObjectWrapper, NativeAccessSpecifierPublic)
};

struct FAdditionalLevelStreamed
{
public:
	static UStruct* GetStruct()
	{
		static auto Struct = FindObject<UStruct>(L"/Script/FortniteGame.AdditionalLevelStreamed");
		return Struct;
	}

	static int GetStructSize() { return GetStruct()->GetPropertiesSize(); }

	FName& GetLevelName()
	{
		static auto LevelNameOffset = FindOffsetStruct("/Script/FortniteGame.AdditionalLevelStreamed", "LevelName");
		return *(FName*)(__int64(this) + LevelNameOffset);
	}
	
	bool& IsServerOnly()
	{
		static auto bIsServerOnlyOffset = FindOffsetStruct("/Script/FortniteGame.AdditionalLevelStreamed", "bIsServerOnly");
		return *(bool*)(__int64(this) + bIsServerOnlyOffset);
	}
};

class AFortAthenaAircraft : public AActor // AFortAircraft
{
public:
	FAircraftFlightInfo GetFlightInfo()
	{
		static auto FlightInfoOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaAircraft", "FlightInfo");
		return *(FAircraftFlightInfo*)(__int64(this) + FlightInfoOffset);
	}

	float& GetDropStartTime()
	{
		static auto DropStartTimeOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaAircraft", "DropStartTime");
		return *(float*)(__int64(this) + DropStartTimeOffset);
	}
};

class AFortPoiVolume : public AActor // AVolume
{
public:
};

class AFortPoiManager : public AActor
{
public:
	TArray<AFortPoiVolume*> GetAllPoiVolumes()
	{
		static auto AllPoiVolumesOffset = FindOffsetStruct("/Script/FortniteGame.FortPoiManager", "AllPoiVolumes");
		return *(TArray<AFortPoiVolume*>*)(__int64(this) + AllPoiVolumesOffset);
	}
};

class AFortGameStateAthena : public AGameState
{
public:
	bool IsTeleportToCreativeHubAllowed()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortGameStateAthena.IsTeleportToCreativeHubAllowed");

		struct
		{
			bool                               ReturnValue;
		}params;

		this->ProcessEvent(fn, &params);

		return params.ReturnValue;
	}

	AFortPoiManager* GetPoiManager()
	{
		static auto PoiManagerOffset = FindOffsetStruct("/Script/FortniteGame.FortGameState", "PoiManager");
		return *(AFortPoiManager**)(__int64(this) + PoiManagerOffset);
	}

	uint8& AircraftIsLocked()
	{
		static auto bAircraftIsLockedOffset = FindOffsetStruct("/Script/FortniteGame.FortGameStateAthena", "bAircraftIsLocked");
		return *(uint8*)(__int64(this) + bAircraftIsLockedOffset);
	}

	int32& GetCurrentHighScoreTeam()
	{
		static auto CurrentHighScoreTeamOffset = FindOffsetStruct("/Script/FortniteGame.FortGameStateAthena", "CurrentHighScoreTeam");
		return *(int32*)(__int64(this) + CurrentHighScoreTeamOffset);
	}

	int32& GetCurrentHighScore()
	{
		static auto CurrentHighScoreOffset = FindOffsetStruct("/Script/FortniteGame.FortGameStateAthena", "CurrentHighScore");
		return *(int32*)(__int64(this) + CurrentHighScoreOffset);
	}

	APlayerState*& GetWinningPlayerState()
	{
		static auto WinningPlayerStateOffset = FindOffsetStruct("/Script/FortniteGame.FortGameStateAthena", "WinningPlayerState");
		return *(APlayerState**)(__int64(this) + WinningPlayerStateOffset);
	}

	int32& GetWinningScore()
	{
		static auto WinningScoreOffset = FindOffsetStruct("/Script/FortniteGame.FortGameStateAthena", "WinningScore");
		return *(int32*)(__int64(this) + WinningScoreOffset);
	}

	int32& GetWinningTeam()
	{
		static auto WinningTeamOffset = FindOffsetStruct("/Script/FortniteGame.FortGameStateAthena", "WinningTeam");
		return *(int32*)(__int64(this) + WinningTeamOffset);
	}

	void OnRep_CurrentHighScore()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortGameStateAthena.OnRep_CurrentHighScore");
		if (fn)
			this->ProcessEvent(fn, nullptr);
	}

	void OnRep_WinningTeam()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortGameStateAthena.OnRep_WinningTeam");
		if (fn)
			this->ProcessEvent(fn, nullptr);
	}

	void OnRep_WinningScore()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortGameStateAthena.OnRep_WinningScore");
		if (fn)
			this->ProcessEvent(fn, nullptr);
	}

	int& GetPlayersLeft()
	{
		static auto PlayersLeftOffset = GetOffset("PlayersLeft");
		return Get<int>(PlayersLeftOffset);
	}

	bool& IsSafeZonePaused()
	{
		static auto bSafeZonePausedOffset = this->GetOffset("bSafeZonePaused");
		return this->Get<bool>(bSafeZonePausedOffset);
	}

	int& GetWorldLevel() // Actually in AFortGameState
	{
		static auto WorldLevelOffset = GetOffset("WorldLevel");
		return Get<int>(WorldLevelOffset);
	}

	AFortAthenaAircraft* GetAircraft(int32 AircraftIndex)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortGameStateAthena.GetAircraft");

		struct
		{
			int32                              AircraftIndex;
			AFortAthenaAircraft* ReturnValue;
		}params{ AircraftIndex };

		this->ProcessEvent(fn, &params);

		return params.ReturnValue;
	}

	EAthenaGamePhase& GetGamePhase()
	{
		static auto GamePhaseOffset = GetOffset("GamePhase");
		return Get<EAthenaGamePhase>(GamePhaseOffset);
	}

	UBuildingStructuralSupportSystem* GetStructuralSupportSystem() // actually in FortGameModeZone
	{
		static auto StructuralSupportSystemOffset = GetOffset("StructuralSupportSystem");
		return Get<UBuildingStructuralSupportSystem*>(StructuralSupportSystemOffset);
	}

	FPlayerBuildableClassContainer*& GetPlayerBuildableClasses()
	{
		static auto PlayerBuildableClassesOffset = GetOffset("PlayerBuildableClasses");
		return Get<FPlayerBuildableClassContainer*>(PlayerBuildableClassesOffset);
	}

	AFortAthenaMapInfo*& GetMapInfo()
	{
		static auto MapInfoOffset = GetOffset("MapInfo");
		return Get<AFortAthenaMapInfo*>(MapInfoOffset);
	}

	bool IsResurrectionEnabled(AFortPlayerPawn* PlayerPawn)
	{
		static auto IsResurrectionEnabledFn = FindObject<UFunction>(L"/Script/FortniteGame.FortGameStateAthena.IsResurrectionEnabled");
		struct { AFortPlayerPawn* PlayerPawn; bool Ret; } Params{PlayerPawn};
		this->ProcessEvent(IsResurrectionEnabledFn, &Params);
		return Params.Ret;
	}

	void OnRep_WinningPlayerState()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortGameStateAthena.OnRep_WinningPlayerState");
		this->ProcessEvent(fn);
	}

	AFortGameplayMutator* GetMutatorByClass(AActor* ContextActor, TSubclassOf<AFortGameplayMutator> MutatorClass)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortGameStateAthena.GetMutatorByClass");

		struct
		{
			AActor* ContextActor;
			TSubclassOf<AFortGameplayMutator> MutatorClass;
			AFortGameplayMutator* ReturnValue;
		}params{ ContextActor , MutatorClass };

		this->ProcessEvent(fn, &params);

		return params.ReturnValue;
	}

	EAthenaGamePhaseStep& GetGamePhaseStep()
	{
		static auto GamePhaseStepOffset = GetOffset("GamePhaseStep");
		return Get<EAthenaGamePhaseStep>(GamePhaseStepOffset);
	}

	UFortPlaylistAthena*& GetCurrentPlaylist();
	TScriptInterface<UFortSafeZoneInterface> GetSafeZoneInterface();

	void AddPlayerStateToGameMemberInfo(class AFortPlayerStateAthena* PlayerState);
	void SkipAircraft();

	int GetAircraftIndex(AFortPlayerState* PlayerState);
	bool IsRespawningAllowed(AFortPlayerState* PlayerState); // actually in zone
	bool IsPlayerBuildableClass(UClass* Class);
	void OnRep_GamePhase();
	void OnRep_CurrentPlaylistInfo();
	void OnRep_PlayersLeft();
	TeamsArrayContainer* GetTeamsArrayContainer();
	void AddToAdditionalPlaylistLevelsStreamed(const FName& Name, bool bServerOnly = false);

	static UClass* StaticClass();
};