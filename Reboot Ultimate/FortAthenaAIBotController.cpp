#include "FortAthenaAIBotController.h"

#include "bots.h"

void AFortAthenaAIBotController::SwitchTeam(uint8 TeamIndex)
{
	static auto SwitchTeamFn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaAIBotController.SwitchTeam");
	this->ProcessEvent(SwitchTeamFn, &TeamIndex);
}

void AFortAthenaAIBotController::AddDigestedSkillSets()
{
	for (int i = 0; i < this->GetDigestedBotSkillSets().Num(); i++)
	{
		auto CurrentDigestedBotSkillSet = this->GetDigestedBotSkillSets().at(i);

		UClass* AimingDigestedSkillSetClass = FindObject<UClass>("/Script/FortniteGame.FortAthenaAIBotAimingDigestedSkillSet");
		UClass* HarvestDigestedSkillSetClass = FindObject<UClass>("/Script/FortniteGame.FortAthenaAIBotHarvestDigestedSkillSet");
		UClass* InventoryDigestedSkillSetClass = FindObject<UClass>("/Script/FortniteGame.FortAthenaAIBotInventoryDigestedSkillSet");
		UClass* LootingDigestedSkillSetClass = FindObject<UClass>("/Script/FortniteGame.FortAthenaAIBotLootingDigestedSkillSet");
		UClass* MovementDigestedSkillSetClass = FindObject<UClass>("/Script/FortniteGame.FortAthenaAIBotMovementDigestedSkillSet");
		UClass* PerceptionDigestedSkillSetClass = FindObject<UClass>("/Script/FortniteGame.FortAthenaAIBotPerceptionDigestedSkillSet");
		UClass* PlayStyleDigestedSkillSetClass = FindObject<UClass>("/Script/FortniteGame.FortAthenaAIBotPlayStyleDigestedSkillSet");

		if (CurrentDigestedBotSkillSet->IsA(AimingDigestedSkillSetClass))
			this->Get("CacheAimingDigestedSkillSet") = CurrentDigestedBotSkillSet;
		if (CurrentDigestedBotSkillSet->IsA(HarvestDigestedSkillSetClass))
			this->Get("CacheHarvestDigestedSkillSet") = CurrentDigestedBotSkillSet;
		if (CurrentDigestedBotSkillSet->IsA(InventoryDigestedSkillSetClass))
			this->Get("CacheInventoryDigestedSkillSet") = CurrentDigestedBotSkillSet;
		if (CurrentDigestedBotSkillSet->IsA(LootingDigestedSkillSetClass))
			this->Get("CacheLootingSkillSet") = CurrentDigestedBotSkillSet;
		if (CurrentDigestedBotSkillSet->IsA(MovementDigestedSkillSetClass))
			this->Get("CacheMovementSkillSet") = CurrentDigestedBotSkillSet;
		if (CurrentDigestedBotSkillSet->IsA(PerceptionDigestedSkillSetClass))
			this->Get("CachePerceptionDigestedSkillSet") = CurrentDigestedBotSkillSet;
		if (CurrentDigestedBotSkillSet->IsA(PlayStyleDigestedSkillSetClass))
			this->Get("CachePlayStyleSkillSet") = CurrentDigestedBotSkillSet;
	}
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