#include "FortAthenaAIBotController.h"

#include "bots.h"

void AFortAthenaAIBotController::SwitchTeam(uint8 TeamIndex)
{
	static auto SwitchTeamFn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaAIBotController.SwitchTeam");
	this->ProcessEvent(SwitchTeamFn, &TeamIndex);
}

void AFortAthenaAIBotController::OnPossesedPawnDiedHook(AController* PlayerController, AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UObject* FHitComponent, FName BoneName, FVector Momentum)
{
	LOG_INFO(LogDev, "OnPossesedPawnDiedHook!");

	// if (!InstigatedBy)
		// return OnPossesedPawnDiedOriginal(PlayerController, DamagedActor, Damage, InstigatedBy, DamageCauser, HitLocation, FHitComponent, BoneName, Momentum);

	for (auto& PlayerBot : AllPlayerBotsToTick)
	{
		if (Cast<AController>(PlayerBot.AIBotController) == PlayerController)
			PlayerBot.OnDied(Cast<AFortPlayerStateAthena>(InstigatedBy ? InstigatedBy->GetPlayerState() : nullptr));
	}

	for (auto& Boss : AllBossesToTick)
	{
		if (Cast<AController>(Boss.Controller) == PlayerController)
			Boss.OnDied(Cast<AFortPlayerStateAthena>(InstigatedBy ? InstigatedBy->GetPlayerState() : nullptr));
	}
}

UClass* AFortAthenaAIBotController::StaticClass()
{
	static auto Class = FindObject<UClass>("/Script/FortniteGame.FortAthenaAIBotController");
	return Class;
}