#include "FortAthenaAISpawnerDataComponentList.h"

TArray<UFortAthenaAISpawnerDataComponent*> UFortAthenaAISpawnerDataComponentList::GetList()
{
	static auto GetListFn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaAISpawnerDataComponentList.GetList");
	TArray<UFortAthenaAISpawnerDataComponent*> ReturnValue;
	this->ProcessEvent(GetListFn, &ReturnValue);
	return ReturnValue;
}