#pragma once

#include "FortAthenaAISpawnerDataComponent.h"
#include "reboot.h"

class UFortAthenaAISpawnerDataComponentList : public UObject
{
public:
	TArray<UFortAthenaAISpawnerDataComponent*> GetList();
};