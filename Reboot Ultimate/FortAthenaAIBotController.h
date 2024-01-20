#pragma once

#include "reboot.h"

#include "Controller.h"
#include "Stack.h"
#include "FortInventory.h"

class AFortAthenaAIBotController : public AController // AAIController
{
public:
	using UPrimitiveComponent = UObject;

	static inline void (*OnPossesedPawnDiedOriginal)(AController* PlayerController, AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	AFortInventory*& GetInventory()
	{
		static auto InventoryOffset = GetOffset("Inventory");
		return Get<AFortInventory*>(InventoryOffset);
	}

	AActor* GetFocusActor()
	{
		static auto fn = FindObject<UFunction>("/Script/AIModule.AIController.GetFocusActor");

		AActor* ReturnValue;

		this->ProcessEvent(fn, &ReturnValue);

		return ReturnValue;
	}

	void ClearFocus()
	{
		static auto fn = FindObject<UFunction>("/Script/AIModule.AIController.K2_ClearFocus");
		this->ProcessEvent(fn);
	}

	void SetFocus(AActor* NewFocus)
	{
		static auto fn = FindObject<UFunction>("/Script/AIModule.AIController.K2_SetFocus");
		this->ProcessEvent(fn, &NewFocus);
	}

	void ThankBusDriver()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaAIBotController.ThankBusDriver");
		this->ProcessEvent(fn);
	}

	static void OnPossesedPawnDiedHook(AController* PlayerController, AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);
};