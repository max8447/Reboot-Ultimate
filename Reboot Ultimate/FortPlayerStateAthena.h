#pragma once

#include "FortPlayerState.h"
#include "Stack.h"
#include "GameplayTagContainer.h"
#include "FortPawn.h"

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

class AFortPlayerStateAthena : public AFortPlayerState
{
public:
	static inline void (*ServerSetInAircraftOriginal)(UObject* Context, FFrame& Stack, void* Ret);
	
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

	int& GetTeamScore()
	{
		static auto TeamScoreOffset = GetOffset("TeamScore");
		return Get<int>(TeamScoreOffset);
	}

	int& GetTeamScorePlacement()
	{
		static auto TeamScorePlacementOffset = GetOffset("TeamScorePlacement");
		return Get<int>(TeamScorePlacementOffset);
	}

	int& GetOldTotalScoreStat()
	{
		static auto OldTotalScoreStatOffset = GetOffset("OldTotalScoreStat");
		return Get<int>(OldTotalScoreStatOffset);
	}

	int& GetTotalPlayerScore()
	{
		static auto TotalPlayerScoreOffset = GetOffset("TotalPlayerScore");
		return Get<int>(TotalPlayerScoreOffset);
	}

	uint8 ToDeathCause(const FGameplayTagContainer& TagContainer, bool bWasDBNO = false, AFortPawn* Pawn = nullptr)
	{
		static auto ToDeathCauseFn = FindObject<UFunction>(L"/Script/FortniteGame.FortPlayerStateAthena.ToDeathCause");

		if (ToDeathCauseFn)
		{
			struct
			{
				FGameplayTagContainer                       InTags;                                                   // (ConstParm, Parm, OutParm, ReferenceParm, NativeAccessSpecifierPublic)
				bool                                               bWasDBNO;                                                 // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
				uint8_t                                        ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			} AFortPlayerStateAthena_ToDeathCause_Params{ TagContainer, bWasDBNO };

			this->ProcessEvent(ToDeathCauseFn, &AFortPlayerStateAthena_ToDeathCause_Params);

			return AFortPlayerStateAthena_ToDeathCause_Params.ReturnValue;
		}

		static bool bHaveFoundAddress = false;

		static uint64 Addr = 0;

		if (!bHaveFoundAddress)
		{
			bHaveFoundAddress = true;

			if (Engine_Version == 419)
				Addr = Memcury::Scanner::FindPattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC 20 41 0F B6 F8 48 8B DA 48 8B F1 E8 ? ? ? ? 33 ED").Get();
			if (Engine_Version == 420)
				Addr = Memcury::Scanner::FindPattern("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 0F B6 FA 48 8B D9 E8 ? ? ? ? 33 F6 48 89 74 24").Get();
			if (Engine_Version == 421) // 5.1
				Addr = Memcury::Scanner::FindPattern("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 0F B6 FA 48 8B D9 E8 ? ? ? ? 33").Get();

			if (!Addr)
			{
				LOG_WARN(LogPlayer, "Failed to find ToDeathCause address!");
				return 0;
			}
		}

		if (!Addr)
		{
			return 0;
		}

		if (Engine_Version == 419)
		{
			static uint8(*sub_7FF7AB499410)(AFortPawn * Pawn, FGameplayTagContainer TagContainer, char bWasDBNOIg) = decltype(sub_7FF7AB499410)(Addr);
			return sub_7FF7AB499410(Pawn, TagContainer, bWasDBNO);
		}

		static uint8(*sub_7FF7AB499410)(FGameplayTagContainer TagContainer, char bWasDBNOIg) = decltype(sub_7FF7AB499410)(Addr);
		return sub_7FF7AB499410(TagContainer, bWasDBNO);
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