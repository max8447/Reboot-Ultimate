#pragma once

#include "ScalableFloat.h"

struct FFortPieSliceSpawnData
{
	FScalableFloat                              SpawnDirection;                                           // 0x0000(0x0020) (Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)
	FScalableFloat                              SpawnDirectionDeviation;                                  // 0x0020(0x0020) (Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)
	FScalableFloat                              MinSpawnDistanceFromCenter;                               // 0x0040(0x0020) (Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)
	FScalableFloat                              MaxSpawnDistanceFromCenter;                               // 0x0060(0x0020) (Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)
};