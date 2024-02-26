#include "FortAthenaAISpawnerData.h"

UFortAthenaAISpawnerDataComponent_SpawnParamsBase* UFortAthenaAISpawnerData::GetSpawnParamsComponent()
{
	static auto GetSpawnParamsComponentFn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaAISpawnerData.GetSpawnParamsComponent");
	UFortAthenaAISpawnerDataComponent_SpawnParamsBase* ReturnValue;
	this->ProcessEvent(GetSpawnParamsComponentFn, &ReturnValue);
	return ReturnValue;
}

UFortAthenaAISpawnerDataComponentList* UFortAthenaAISpawnerData::CreateComponentListFromClass(TSubclassOf<UFortAthenaAISpawnerData> AISpawnerDataClass, UObject* OuterObject)
{
	static auto CreateComponentListFromClassFn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaAISpawnerData.CreateComponentListFromClass");

	struct
	{
		TSubclassOf<UFortAthenaAISpawnerData> AISpawnerDataClass;
		UObject* OuterObject;
		UFortAthenaAISpawnerDataComponentList* ReturnValue;
	}FortAthenaAISpawnerData_CreateComponentListFromClass_Params{ AISpawnerDataClass , OuterObject };

	StaticClass()->ProcessEvent(CreateComponentListFromClassFn, &FortAthenaAISpawnerData_CreateComponentListFromClass_Params);

	return FortAthenaAISpawnerData_CreateComponentListFromClass_Params.ReturnValue;
}

UClass* UFortAthenaAISpawnerData::StaticClass()
{
	static auto Class = FindObject<UClass>("/Script/FortniteGame.FortAthenaAISpawnerData");
	return Class;
}

TSubclassOf<APawn> UFortAthenaAISpawnerDataComponent_SpawnParamsBase::GetPawnClass()
{
	static auto GetPawnClassFn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaAISpawnerDataComponent_SpawnParamsBase.GetPawnClass");
	TSubclassOf<APawn> ReturnValue;
	this->ProcessEvent(GetPawnClassFn, &ReturnValue);
	return ReturnValue;
}