#include "FortSafeZoneIndicator.h"

#include "FortGameModeAthena.h"
#include "reboot.h"
#include "KismetSystemLibrary.h"

void AFortSafeZoneIndicator::SkipShrinkSafeZone()
{
	auto GameState = Cast<AFortGameStateAthena>(((AFortGameMode*)GetWorld()->GetGameMode())->GetGameState());

	GetSafeZoneStartShrinkTime() = GameState->GetServerWorldTimeSeconds();
	GetSafeZoneFinishShrinkTime() = GameState->GetServerWorldTimeSeconds() + 0.2;
}

void AFortSafeZoneIndicator::OnSafeZoneStateChangeHook(AFortSafeZoneIndicator* SafeZoneIndicator, EFortSafeZoneState NewState, bool bInitial)
{
	auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());
	auto GameMode = Cast<AFortGameModeAthena>(GetWorld()->GetGameMode());

	LOG_INFO(LogDev, "OnSafeZoneStateChangeHook!");

	for (int i = 0; i < GameMode->GetAlivePlayers().Num(); i++)
	{
		auto PlayerController = GameMode->GetAlivePlayers().at(i);

		PlayerController->GiveAccolade(PlayerController, FindObject<UFortAccoladeItemDefinition>("/Game/Athena/Items/Accolades/AccoladeID_SurviveStormCircle.AccoladeID_SurviveStormCircle"));
	}

	return OnSafeZoneStateChangeOriginal(SafeZoneIndicator, NewState, bInitial);
}