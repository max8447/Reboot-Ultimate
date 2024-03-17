#pragma once

#include "AIController.h"
#include "FortInventory.h"
#include "FortAthenaMutator_Bots.h"
#include "FortGameModeAthena.h"

class AFortAthenaAIBotController : public AAIController
{
public:
	static inline void (*OnPossesedPawnDiedOriginal)(AController* PlayerController, AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UObject* FHitComponent, FName BoneName, FVector Momentum);

	AFortInventory* GetInventory()
	{
		static auto InventoryOffset = GetOffset("Inventory");
		return Get<AFortInventory*>(InventoryOffset);
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

	static void OnPossesedPawnDiedHook(AController* PlayerController, AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UObject* FHitComponent, FName BoneName, FVector Momentum);

	static UClass* StaticClass();
};