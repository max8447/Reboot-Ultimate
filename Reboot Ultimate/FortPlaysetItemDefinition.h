#pragma once

#include "FortItemDefinition.h"
#include "FortVolume.h"
#include "SoftObjectPtr.h"
#include "SoftClassPtr.h"

extern inline __int64 (*LoadPlaysetOriginal)(class UPlaysetLevelStreamComponent* a1) = nullptr;

class UFortPlaysetItemDefinition : public UFortItemDefinition // UFortAccountItemDefinition
{
public:
	TSoftObjectPtr<UWorld> GetPlaysetToSpawn()
	{
		static auto PlaysetToSpawnOffset = GetOffset("PlaysetToSpawn");
		return Get<TSoftObjectPtr<UWorld>>(PlaysetToSpawnOffset);
	}

	FName GetPlaysetName()
	{
		static auto PlaysetNameOffset = GetOffset("PlaysetName");
		return Get<FName>(PlaysetNameOffset);
	}

	TMap<TSoftClassPtr<UClass>, int32> GetActorClassCount()
	{
		static auto ActorClassCountOffset = GetOffset("ActorClassCount");
		return Get<TMap<TSoftClassPtr<UClass>, int32>>(ActorClassCountOffset);
	}

	static void ShowPlayset(UFortPlaysetItemDefinition* PlaysetItemDef, AFortVolume* Volume);

	static UClass* StaticClass();
};