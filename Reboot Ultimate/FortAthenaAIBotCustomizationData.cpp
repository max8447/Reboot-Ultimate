#include "FortAthenaAIBotCustomizationData.h"

#include "bots.h"

void UFortAthenaAIBotCustomizationData::ApplyOverrideCharacterCustomizationHook(UFortAthenaAIBotCustomizationData* InBotData, AFortPlayerPawn* NewBot, __int64 idk)
{
	LOG_INFO(LogDev, "ApplyOverrideCharacterCustomizationHook with {} at {}!", InBotData->GetFullName(), NewBot->GetActorLocation().ToString().ToString());

	auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());
	auto OldController = NewBot->GetController();

	auto NewController = Bosses::SpawnBoss(NewBot, NewBot->GetTransform(), InBotData);
	auto NewPawn = NewController->GetPlayerBotPawn();

	if (NewBot->IsValidLowLevel())
		NewBot->K2_DestroyActor();
}