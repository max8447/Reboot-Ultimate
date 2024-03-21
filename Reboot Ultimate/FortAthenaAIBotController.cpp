#include "FortAthenaAIBotController.h"

#include "bots.h"
#include "FortInventory.h"

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

void AFortAthenaAIBotController::GiveItem(UFortItemDefinition* ItemDefinition, int Count)
{
	auto Inventory = this->GetInventory();

	if (!Inventory)
		return;

	UFortItem* Item = CreateItemInstance(this, ItemDefinition, Count);

	if (auto WeaponDefinition = Cast<UFortWeaponItemDefinition>(ItemDefinition))
		Item->GetItemEntry()->GetLoadedAmmo() = WeaponDefinition->GetClipSize();

	Inventory->GetItemList().GetReplicatedEntries().Add(*Item->GetItemEntry(), FFortItemEntry::GetStructSize());
	Inventory->GetItemList().MarkItemDirty(Item->GetItemEntry());
	Inventory->HandleInventoryLocalUpdate();

	// if (auto WeaponDefinition = Cast<UFortWeaponItemDefinition>(ItemDefinition))
		// this->GetPlayerBotPawn()->EquipWeaponDefinition(WeaponDefinition, Item->GetItemEntry()->GetItemGuid());
}

void AFortAthenaAIBotController::OnPossesedPawnDiedHook(AFortAthenaAIBotController* PlayerController, AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UObject* FHitComponent, FName BoneName, FVector Momentum)
{
	LOG_INFO(LogDev, "OnPossesedPawnDiedHook!");

	// if (!InstigatedBy)
		// return OnPossesedPawnDiedOriginal(PlayerController, DamagedActor, Damage, InstigatedBy, DamageCauser, HitLocation, FHitComponent, BoneName, Momentum);

	for (int i = 0; i < AllPlayerBotsToTick.size(); i++)
	{
		auto PlayerBot = AllPlayerBotsToTick[i];

		if (Cast<AController>(PlayerBot.AIBotController) == PlayerController)
		{
			PlayerBot.OnDied(Cast<AFortPlayerStateAthena>(InstigatedBy ? InstigatedBy->GetPlayerState() : nullptr));
			AllPlayerBotsToTick.erase(AllPlayerBotsToTick.begin() + i);
		}
	}

	for (int i = 0; i < AllBossesToTick.size(); i++)
	{
		auto Boss = AllBossesToTick[i];

		if (Cast<AController>(Boss.Controller) == PlayerController)
		{
			Boss.OnDied(Cast<AFortPlayerStateAthena>(InstigatedBy ? InstigatedBy->GetPlayerState() : nullptr));
			AllBossesToTick.erase(AllBossesToTick.begin() + i);
		}
	}
}

void AFortAthenaAIBotController::OnPerceptionSensedHook(AFortAthenaAIBotController* PlayerController, AActor* SourceActor, FAIStimulus& Stim)
{
	if (SourceActor->IsA(AFortPlayerPawnAthena::StaticClass()) && Cast<AFortPlayerPawnAthena>(SourceActor)->GetController() && !Cast<AFortPlayerPawnAthena>(SourceActor)->GetController()->IsA(AFortAthenaAIBotController::StaticClass()))
	{
		for (auto& Boss : AllBossesToTick)
		{
			if (Boss.Controller == PlayerController)
			{
				Boss.OnPerceptionSensed(SourceActor, Stim);
			}
		}
	}

	return OnPerceptionSensedOriginal(PlayerController, SourceActor, Stim);
}

void AFortAthenaAIBotController::OnAlertLevelChangedHook(AFortAthenaAIBotController* PlayerController, EAlertLevel OldAlertLevel, EAlertLevel NewAlertLevel)
{
	return OnAlertLevelChangedOriginal(PlayerController, OldAlertLevel, NewAlertLevel);
}

UClass* AFortAthenaAIBotController::StaticClass()
{
	static auto Class = FindObject<UClass>("/Script/FortniteGame.FortAthenaAIBotController");
	return Class;
}