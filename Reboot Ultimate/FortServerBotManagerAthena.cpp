#include "FortServerBotManagerAthena.h"

APawn* UFortServerBotManagerAthena::SpawnAI(FVector InSpawnLocation, FRotator InSpawnRotation, UFortAthenaAISpawnerDataComponentList* AISpawnerComponentList)
{
	static auto SpawnAIFn = FindObject<UFunction>("/Script/FortniteGame.FortServerBotManagerAthena.SpawnAI");

	struct
	{
		FVector InSpawnLocation;
		FRotator InSpawnRotation;
		UFortAthenaAISpawnerDataComponentList* AISpawnerComponentList;
		APawn* ReturnValue;
	}FortServerBotManagerAthena_SpawnAI_Params{ InSpawnLocation , InSpawnRotation , AISpawnerComponentList };

	this->ProcessEvent(SpawnAIFn, &FortServerBotManagerAthena_SpawnAI_Params);

	return FortServerBotManagerAthena_SpawnAI_Params.ReturnValue;
}

AFortPlayerPawnAthena* UFortServerBotManagerAthena::SpawnBot(FVector InSpawnLocation, FRotator InSpawnRotation, UFortAthenaAIBotCustomizationData* InBotData, FFortAthenaAIBotRunTimeCustomizationData InRuntimeBotData)
{
	static auto SpawnBotFn = FindObject<UFunction>("/Script/FortniteGame.FortServerBotManagerAthena.SpawnBot");

	struct
	{
		FVector InSpawnLocation;
		FRotator InSpawnRotation;
		UFortAthenaAIBotCustomizationData* InBotData;
		FFortAthenaAIBotRunTimeCustomizationData InRuntimeBotData;
		AFortPlayerPawnAthena* ReturnValue;
	}FortServerBotManagerAthena_SpawnBot_Params{ InSpawnLocation , InSpawnRotation , InBotData , InRuntimeBotData };

	this->ProcessEvent(SpawnBotFn, &FortServerBotManagerAthena_SpawnBot_Params);

	return FortServerBotManagerAthena_SpawnBot_Params.ReturnValue;
}