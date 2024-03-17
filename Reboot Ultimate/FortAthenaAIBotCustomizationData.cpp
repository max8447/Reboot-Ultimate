#include "FortAthenaAIBotCustomizationData.h"

#include "bots.h"

void UFortAthenaAIBotCustomizationData::ApplyOverrideCharacterCustomizationHook(UFortAthenaAIBotCustomizationData* InBotData, AFortPlayerPawn* NewBot, __int64 idk)
{
	LOG_INFO(LogDev, "ApplyOverrideCharacterCustomizationHook!");

	Bosses::SpawnBoss(NewBot, NewBot->GetTransform(), InBotData);
	NewBot->K2_DestroyActor();
}