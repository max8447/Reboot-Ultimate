#pragma once

#include "FortPieSliceSpawnData.h"
#include "ScalableFloat.h"

struct FHeistExitCraftSpawnData : public FFortPieSliceSpawnData
{
	FScalableFloat                              SpawnDelayTime;                                           // 0x0080(0x0020) (Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)
	FScalableFloat                              SafeZonePhaseWhenToSpawn;                                 // 0x00A0(0x0020) (Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)
	FScalableFloat                              SafeZonePhaseWhereToSpawn;                                // 0x00C0(0x0020) (Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)
};