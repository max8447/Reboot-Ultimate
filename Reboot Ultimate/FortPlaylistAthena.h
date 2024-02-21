#pragma once

#include "FortPlaylist.h"

enum class EAthenaRespawnType : uint8_t
{
	None = 0,
	InfiniteRespawn = 1,
	InfiniteRespawnExceptStorm = 2,
	EAthenaRespawnType_MAX = 3
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

class UFortPlaylistAthena : public UFortPlaylist
{
public:
	EAthenaRespawnType& GetRespawnType()
	{
		static auto RespawnTypeOffset = GetOffset("RespawnType");
		return Get<EAthenaRespawnType>(RespawnTypeOffset);
	}

	EAthenaWinCondition& GetWinConditionType()
	{
		static auto WinConditionTypeOffset = GetOffset("WinConditionType");
		return Get<EAthenaWinCondition>(WinConditionTypeOffset);
	}

	TArray<UFortItemDefinition*> GetItemsToFullyLoad()
	{
		static auto ItemsToFullyLoadOffset = GetOffset("ItemsToFullyLoad");
		return Get<TArray<UFortItemDefinition*>>(ItemsToFullyLoadOffset);
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortPlaylistAthena");
		return Class;
	}
};