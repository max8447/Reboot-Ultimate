#pragma once

#include "reboot.h"
#include "TSubClassOf.h"
#include "FortAthenaAISpawnerDataComponentList.h"
#include "Pawn.h"

class UFortAthenaAISpawnerData : public UObject
{
public:
	class UFortAthenaAISpawnerDataComponent_SpawnParamsBase* GetSpawnParamsComponent();

	static UFortAthenaAISpawnerDataComponentList* CreateComponentListFromClass(TSubclassOf<UFortAthenaAISpawnerData> AISpawnerDataClass, UObject* OuterObject);

	static UClass* StaticClass();
};

class UFortAthenaAISpawnerDataComponent_SpawnParamsBase : public UFortAthenaAISpawnerDataComponent
{
public:
	TSubclassOf<APawn> GetPawnClass();
};