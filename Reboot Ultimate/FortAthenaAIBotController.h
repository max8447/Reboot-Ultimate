#pragma once

#include "AIController.h"
#include "FortInventory.h"

class AFortAthenaAIBotController : public AAIController
{
public:
	static inline void (*OnPossesedPawnDiedOriginal)(AController* PlayerController, AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UObject* FHitComponent, FName BoneName, FVector Momentum);

	AFortInventory* GetInventory()
	{
		static auto InventoryOffset = GetOffset("Inventory");
		return Get<AFortInventory*>(InventoryOffset);
	}

	static void OnPossesedPawnDiedHook(AController* PlayerController, AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UObject* FHitComponent, FName BoneName, FVector Momentum);

	static UClass* StaticClass();
};