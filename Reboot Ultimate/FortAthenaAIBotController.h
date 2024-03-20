#pragma once

#include "AIController.h"
#include "FortInventory.h"
#include "FortAthenaMutator_Bots.h"
#include "FortGameModeAthena.h"
#include "FortAthenaAIBotCustomizationData.h"
#include "AIStimulus.h"

enum class EAlertLevel : uint8
{
	Unaware = 0,
	Alerted = 1,
	LKP = 2,
	Threatened = 3,
	Count = 4,
	EAlertLevel_MAX = 5,
};

class AFortAthenaAIBotController : public AAIController
{
public:
	static inline void (*OnPossesedPawnDiedOriginal)(AController* PlayerController, AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UObject* FHitComponent, FName BoneName, FVector Momentum);
	static inline void (*OnPerceptionSensedOriginal)(AFortAthenaAIBotController* PlayerController, AActor* SourceActor, FAIStimulus& Stim);

	AFortInventory*& GetInventory()
	{
		static auto InventoryOffset = GetOffset("Inventory");

		AFortInventory* Inventory = nullptr;

		if (InventoryOffset != -1)
			Inventory = Get<AFortInventory*>(InventoryOffset);

		return Inventory;
	}

	AFortPlayerPawnAthena*& GetPlayerBotPawn()
	{
		static auto PlayerBotPawnOffset = GetOffset("PlayerBotPawn");
		return Get<AFortPlayerPawnAthena*>(PlayerBotPawnOffset);
	}

	AFortGameModeAthena*& GetCachedGameMode()
	{
		static auto CachedGameModeOffset = GetOffset("CachedGameMode");
		return Get<AFortGameModeAthena*>(CachedGameModeOffset);
	}

	AFortAthenaMutator_Bots*& GetCachedBotMutator()
	{
		static auto CachedBotMutatorOffset = GetOffset("CachedBotMutator");
		return Get<AFortAthenaMutator_Bots*>(CachedBotMutatorOffset);
	}

	UFortAthenaAIBotCustomizationData*& GetBotData()
	{
		static auto BotDataOffset = GetOffset("BotData");
		return Get<UFortAthenaAIBotCustomizationData*>(BotDataOffset);
	}

	TArray<UObject*> GetDigestedBotSkillSets()
	{
		static auto DigestedBotSkillSetsOffset = GetOffset("DigestedBotSkillSets");
		return Get<TArray<UObject*>>(DigestedBotSkillSetsOffset);
	}

	EAlertLevel GetCurrentAlertLevel()
	{
		static auto CurrentAlertLevelOffset = GetOffset("CurrentAlertLevel");
		return Get<EAlertLevel>(CurrentAlertLevelOffset);
	}

	void SwitchTeam(uint8 TeamIndex);
	void AddDigestedSkillSets();
	void GiveItem(UFortItemDefinition* ItemDefinition, int Count);

	static void OnPossesedPawnDiedHook(AController* PlayerController, AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UObject* FHitComponent, FName BoneName, FVector Momentum);
	static void OnPerceptionSensedHook(AFortAthenaAIBotController* PlayerController, AActor* SourceActor, FAIStimulus& Stim);

	static UClass* StaticClass();
};