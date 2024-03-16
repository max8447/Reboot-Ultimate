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

AFortPlayerPawnAthena* UFortServerBotManagerAthena::SpawnBotHook(UFortServerBotManagerAthena* BotManager, FVector InSpawnLocation, FRotator InSpawnRotation, UFortAthenaAIBotCustomizationData* InBotData, FFortAthenaAIBotRunTimeCustomizationData InRuntimeBotData)
{
	LOG_INFO(LogBots, "UFortServerBotManagerAthena::SpawnBotHook!");

	LOG_INFO(LogBots, "InSpawnLocation: {}", InSpawnLocation.ToString().ToString());

	// return SpawnBotOriginal(BotManager, InSpawnLocation, InSpawnRotation, InBotData, InRuntimeBotData);

	return nullptr;
}