#pragma once

#include "reboot.h"

struct FAthenaMatchTeamStats
{
	static UStruct* GetStruct()
	{
		static auto Struct = FindObject<UStruct>(L"/Script/FortniteGame.AthenaMatchTeamStats");
		return Struct;
	}

	static auto GetStructSize() { return GetStruct()->GetPropertiesSize(); }

	int                                                Place;
	int                                                TotalPlayers;

	int& GetPlace()
	{
		return Place;
	}

	int& GetTotalPlayers()
	{
		return TotalPlayers;
	}
};

struct FAthenaMatchStats
{
	static UStruct* GetStruct()
	{
		static auto Struct = FindObject<UStruct>(L"/Script/FortniteGame.AthenaMatchStats");
		return Struct;
	}

	static auto GetStructSize() { return GetStruct()->GetPropertiesSize(); }

	class FString                                StatBucket;                                        // 0x0(0x10)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class FString                                MatchID;                                           // 0x10(0x10)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class FString                                MatchEndTime;                                      // 0x20(0x10)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class FString                                MatchPlatform;                                     // 0x30(0x10)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	int32                                        Stats[0x14];                                       // 0x40(0x50)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	TArray<struct FAthenaWeaponStats>            WeaponStats;                                       // 0x90(0x10)(ZeroConstructor, NativeAccessSpecifierPrivate)
	TArray<struct FAthenaXPStats>                XPStats;                                           // 0xA0(0x10)(ZeroConstructor, NativeAccessSpecifierPrivate)
};

class UAthenaPlayerMatchReport : public UObject
{
public:
	bool& HasTeamStats()
	{
		static auto bHasTeamStatsOffset = GetOffset("bHasTeamStats");
		return Get<bool>(bHasTeamStatsOffset);
	}

	bool& HasMatchStats()
	{
		static auto bHasMatchStatsOffset = GetOffset("bHasMatchStats");
		return Get<bool>(bHasMatchStatsOffset);
	}

	FAthenaMatchTeamStats* GetTeamStats()
	{
		static auto TeamStatsOffset = GetOffset("TeamStats");
		return GetPtr<FAthenaMatchTeamStats>(TeamStatsOffset);
	}

	FAthenaMatchStats* GetStats()
	{
		static auto StatsOffset = GetOffset("Stats");
		return GetPtr<FAthenaMatchStats>(StatsOffset);
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.AthenaPlayerMatchReport");
		return Class;
	}
};