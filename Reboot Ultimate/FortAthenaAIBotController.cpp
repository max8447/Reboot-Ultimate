#include "FortAthenaAIBotController.h"

#include "bots.h"

void AFortAthenaAIBotController::OnPossesedPawnDiedHook(AController* PlayerController, AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
	LOG_INFO(LogDev, "OnPossesedPawnDiedHook!");

	if (!InstigatedBy)
		return OnPossesedPawnDiedOriginal(PlayerController, DamagedActor, Damage, InstigatedBy, DamageCauser, HitLocation, FHitComponent, BoneName, Momentum);

	for (auto PhoebeBot : PhoebeBotsToTick)
	{
		if (PhoebeBot && PhoebeBot->PlayerController && PhoebeBot->TickEnabled && PhoebeBot->PlayerController == PlayerController)
		{
			PhoebeBot->OnDied(Cast<AFortPlayerStateAthena>(InstigatedBy->GetPlayerState()));
			break;
		}
	}

	return OnPossesedPawnDiedOriginal(PlayerController, DamagedActor, Damage, InstigatedBy, DamageCauser, HitLocation, FHitComponent, BoneName, Momentum);
}