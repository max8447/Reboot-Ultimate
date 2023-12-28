// Food Fight

#pragma once

#include "FortAthenaMutator.h"
#include "AthenaBigBaseWall.h"
#include "AthenaBarrierObjective.h"
#include "AthenaBarrierFlag.h"
#include "BarrierTeamState.h"

/* 

EVENT IDS (got on 10.40):

WallComingDown - 1
WallDown - 2
// IDK REST COMPILER WAS TOO SMART
Intro - 9
NoMoreRespawns - 10

*/

class AFortAthenaMutator_Barrier : public AFortAthenaMutator
{
public:
	static inline void (*OnGamePhaseStepChangedOriginal)(UObject* Context, FFrame& Stack, void* Ret);

	UClass* GetBigBaseWallClass()
	{
		static auto BigBaseWallClassOffset = GetOffset("BigBaseWallClass");
		return Get<UClass*>(BigBaseWallClassOffset);
	}

	UClass* GetObjectiveFlagClass()
	{
		static auto ObjectiveFlagOffset = GetOffset("ObjectiveFlag");
		return Get<UClass*>(ObjectiveFlagOffset);
	}

	AAthenaBigBaseWall*& GetBigBaseWall()
	{
		static auto BigBaseWallOffset = GetOffset("BigBaseWall");
		return Get<AAthenaBigBaseWall*>(BigBaseWallOffset);
	}

	FBarrierTeamState* GetTeam_0_State()
	{
		static auto Team_0_StateOffset = GetOffset("Team_0_State");
		return GetPtr<FBarrierTeamState>(Team_0_StateOffset);
	}

	FBarrierTeamState* GetTeam_1_State()
	{
		static auto Team_1_StateOffset = GetOffset("Team_1_State");
		return GetPtr<FBarrierTeamState>(Team_1_StateOffset);
	}

	static void OnGamePhaseStepChangedHook(UObject* Context, FFrame& Stack, void* Ret);
};