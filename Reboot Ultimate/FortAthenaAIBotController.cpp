#include "FortAthenaAIBotController.h"

#include "bots.h"

void AFortAthenaAIBotController::OnPossesedPawnDiedHook(AController* PlayerController, AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
	LOG_INFO(LogDev, "OnPossesedPawnDiedHook!");

	if (!InstigatedBy)
		return OnPossesedPawnDiedOriginal(PlayerController, DamagedActor, Damage, InstigatedBy, DamageCauser, HitLocation, FHitComponent, BoneName, Momentum);

	PhoebeBots::PhoebePlayerBotDied(PlayerController, InstigatedBy);
	PhoebeBots::PhoebeHenchmanDied(PlayerController, InstigatedBy);

	return OnPossesedPawnDiedOriginal(PlayerController, DamagedActor, Damage, InstigatedBy, DamageCauser, HitLocation, FHitComponent, BoneName, Momentum);
}

void AFortAthenaAIBotController::OnPerceptionSensedHook(AFortAthenaAIBotController* PlayerController, AActor* SourceActor, FAIStimulus& Stim)
{
	if (SourceActor->IsA(AFortPlayerPawnAthena::StaticClass()) && Cast<AFortPlayerPawnAthena>(SourceActor)->GetController() && !Cast<AFortPlayerPawnAthena>(SourceActor)->GetController()->IsA(AFortAthenaAIBotController::StaticClass()))
	{
		LOG_INFO(LogBots, "OnPerceptionSensedHook!");

		for (auto Henchman : PhoebeHenchmenToTick)
		{
			if (Henchman->PlayerController == PlayerController)
			{
				Henchman->OnPerceptionSensed(SourceActor, Stim);
			}
		}
	}

	return OnPerceptionSensedOriginal(PlayerController, SourceActor , Stim);
}