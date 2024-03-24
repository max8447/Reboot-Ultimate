#pragma once

#include "Actor.h"
#include "FortAthenaPatrolPoint.h"

class AFortAthenaPatrolPath : public AActor
{
public:
	TArray<AFortAthenaPatrolPoint*> GetPatrolPoints()
	{
		static auto PatrolPointsOffset = GetOffset("PatrolPoints");
		return Get<TArray<AFortAthenaPatrolPoint*>>(PatrolPointsOffset);
	}
};