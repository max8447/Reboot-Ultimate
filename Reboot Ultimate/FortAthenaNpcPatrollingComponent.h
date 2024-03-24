#pragma once

#include "ActorComponent.h"

#include "FortAthenaPatrolPath.h"

#include "reboot.h"

class UFortAthenaNpcPatrollingComponent : public UActorComponent
{
public:
	AFortAthenaPatrolPath* GetPatrolPath()
	{
		static auto PatrolPathOffset = GetOffset("PatrolPath");
		return Get<AFortAthenaPatrolPath*>(PatrolPathOffset);
	}

	void SetPatrolPath(AFortAthenaPatrolPath* NewPatrolPath)
	{
		static auto SetPatrolPathFn = FindObject<UFunction>(L"/Script/FortniteGame.FortAthenaNpcPatrollingComponent.SetPatrolPath");
		this->ProcessEvent(SetPatrolPathFn, &NewPatrolPath);
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortAthenaNpcPatrollingComponent");
		return Class;
	}
};