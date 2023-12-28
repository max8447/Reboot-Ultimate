#pragma once

#include "FortPlayerState.h"
#include "Frame.h"

struct FFortRespawnData
{
	static UStruct* GetStruct()
	{
		static auto Struct = FindObject<UStruct>(L"/Script/FortniteGame.FortRespawnData");
		return Struct;
	}

	static int GetStructSize() { return GetStruct()->GetPropertiesSize(); }

	bool& IsRespawnDataAvailable()
	{
		static auto bRespawnDataAvailableOffset = FindOffsetStruct("/Script/FortniteGame.FortRespawnData", "bRespawnDataAvailable");
		return *(bool*)(__int64(this) + bRespawnDataAvailableOffset);
	}

	bool& IsClientReady()
	{
		static auto bClientIsReadyOffset = FindOffsetStruct("/Script/FortniteGame.FortRespawnData", "bClientIsReady");
		return *(bool*)(__int64(this) + bClientIsReadyOffset);
	}

	bool& IsServerReady()
	{
		static auto bServerIsReadyOffset = FindOffsetStruct("/Script/FortniteGame.FortRespawnData", "bServerIsReady");
		return *(bool*)(__int64(this) + bServerIsReadyOffset);
	}
};

struct FDeathInfo
{
	static UStruct* GetStruct()
	{
		static auto Struct = FindObject<UStruct>("/Script/FortniteGame.DeathInfo");
		return Struct;
	}

	static int GetStructSize() { return GetStruct()->GetPropertiesSize(); }

	bool& IsDBNO()
	{
		static auto bDBNOOffset = FindOffsetStruct("/Script/FortniteGame.DeathInfo", "bDBNO");
		return *(bool*)(__int64(this) + bDBNOOffset);
	}
};

static FVector BusLocation;

struct FVector_NetQuantize100 : public FVector
{
public:
};

class AFortPlayerStateAthena : public AFortPlayerState
{
public:
	static inline void (*ServerSetInAircraftOriginal)(UObject* Context, FFrame& Stack, void* Ret);

	int32& GetSeasonLevelUIDisplay()
	{
		static auto SeasonLevelUIDisplayOffset = GetOffset("SeasonLevelUIDisplay");
		return Get<int32>(SeasonLevelUIDisplayOffset);
	}

	void OnRep_SeasonLevelUIDisplay()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerStateAthena.OnRep_SeasonLevelUIDisplay");
		this->ProcessEvent(fn);
	}

	uint8& GetSquadId()
	{
		static auto SquadIdOffset = GetOffset("SquadId");
		return Get<uint8>(SquadIdOffset);
	}

	uint8& GetTeamIndex()
	{
		static auto TeamIndexOffset = GetOffset("TeamIndex");
		return Get<uint8>(TeamIndexOffset);
	}

	int& GetPlace()
	{
		static auto PlaceOffset = GetOffset("Place");
		return Get<int>(PlaceOffset);
	}

	FFortRespawnData* GetRespawnData()
	{
		static auto RespawnDataOffset = GetOffset("RespawnData");
		return GetPtr<FFortRespawnData>(RespawnDataOffset);
	}

	bool IsInAircraft()
	{
		static auto bInAircraftOffset = GetOffset("bInAircraft");
		static auto bInAircraftFieldMask = GetFieldMask(GetProperty("bInAircraft"));
		return ReadBitfieldValue(bInAircraftOffset, bInAircraftFieldMask);
	}

	bool HasThankedBusDriver()
	{
		static auto bThankedBusDriverOffset = GetOffset("bThankedBusDriver");
		static auto bThankedBusDriverFieldMask = GetFieldMask(GetProperty("bThankedBusDriver"));
		return ReadBitfieldValue(bThankedBusDriverOffset, bThankedBusDriverFieldMask);
	}

	bool& IsResurrectingNow()
	{
		static auto bResurrectingNowOffset = GetOffset("bResurrectingNow", false);

		// if (bResurrectingNowOffset == -1)
			// return false;

		return Get<bool>(bResurrectingNowOffset);
	}

	void ClientReportKill(AFortPlayerStateAthena* Player)
	{
		static auto ClientReportKillFn = FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerStateAthena.ClientReportKill");
		this->ProcessEvent(ClientReportKillFn, &Player);
	}
	
	void OnRep_DeathInfo()
	{
		static auto OnRep_DeathInfoFn = FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerStateAthena.OnRep_DeathInfo");

		if (OnRep_DeathInfoFn) // needed?
		{
			this->ProcessEvent(OnRep_DeathInfoFn);
		}
	}

	void OnRep_TeamScore()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerStateAthena.OnRep_TeamScore");
		this->ProcessEvent(fn);
	}

	void OnRep_TeamScorePlacement()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerStateAthena.OnRep_TeamScorePlacement");
		this->ProcessEvent(fn);
	}

	void OnRep_TotalPlayerScore()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerStateAthena.OnRep_TotalPlayerScore");
		this->ProcessEvent(fn);
	}

	void OnRep_Place()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerStateAthena.OnRep_Place");
		this->ProcessEvent(fn);
	}

	FDeathInfo* GetDeathInfo()
	{
		return GetPtr<FDeathInfo>(MemberOffsets::FortPlayerStateAthena::DeathInfo);
	}

	void ClearDeathInfo()
	{
		RtlSecureZeroMemory(GetDeathInfo(), FDeathInfo::GetStructSize()); // TODO FREE THE DEATHTAGS
	}

	static void ServerSetInAircraftHook(UObject* Context, FFrame& Stack, void* Ret);

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortPlayerStateAthena");
		return Class;
	}
};