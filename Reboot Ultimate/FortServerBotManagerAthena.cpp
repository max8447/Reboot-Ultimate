#include "FortServerBotManagerAthena.h"
#include "bots.h"

#include "FortAthenaAIBotCustomizationData.h"

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

	LOG_INFO(LogBots, "SpawnBotHook!");

	LOG_INFO(LogBots, "InSpawnLocation: {}", InSpawnLocation.ToString().ToString());

	auto SpawnActor = GetWorld()->SpawnActor<AFortPlayerPawn>(AFortPlayerPawn::StaticClass(), InSpawnLocation, InSpawnRotation.Quaternion());
	auto ReturnPawn = BotManager->GetCachedBotMutator()->SpawnBot(InBotData->GetPawnClass(), SpawnActor, InSpawnLocation, InSpawnRotation, false);

	DWORD CustomSquadId = InBotData->GetCustomSquadId();
	BYTE TrueByte = TRUE;
	BYTE FalseByte = FALSE;

	static auto S12Offset = 0x19D93F0;
	static auto S13Offset = 0x1FB6070;

	void (*BotManagerSetup)(__int64 BotManager, __int64 Pawn, __int64 BehaviorTree, __int64 a4, DWORD* SkillLevel, __int64 idk, __int64 StartupInventory, __int64 BotNameSettings, __int64 idk_1, BYTE * CanRespawnOnDeath, unsigned __int8 BitFieldDataThing, BYTE * CustomSquadId, FFortAthenaAIBotRunTimeCustomizationData InRuntimeBotData) = decltype(BotManagerSetup)(__int64(GetModuleHandleW(0)) + Fortnite_Version < 13 ? S12Offset : S13Offset);

	BotManagerSetup(__int64(BotManager), __int64(ReturnPawn), __int64(InBotData->GetBehaviorTree()), 0, &CustomSquadId, 0, __int64(InBotData->GetStartupInventory()), __int64(InBotData->GetBotNameSettings()), 0, &TrueByte, 0, &FalseByte, InRuntimeBotData);

	return ReturnPawn;;
}