#pragma once

#include "reboot.h"

#include "Controller.h"
#include "Stack.h"
#include "FortInventory.h"
#include "EnvQueryTypes.h"
#include "FortAthenaAIBotDigestedSkillSet.h"
#include "PathFollowingComponent.h"

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

	TArray<UObject*> GetDigestedBotSkillSets()
	{
		static auto DigestedBotSkillSetsOffset = GetOffset("DigestedBotSkillSets");
		return Get<TArray<UObject*>>(DigestedBotSkillSetsOffset);
	}

	UFortAthenaAIBotAimingDigestedSkillSet*& GetCacheAimingDigestedSkillSet()
	{
		static auto CacheAimingDigestedSkillSetOffset = GetOffset("CacheAimingDigestedSkillSet");
		return Get<UFortAthenaAIBotAimingDigestedSkillSet*>(CacheAimingDigestedSkillSetOffset);
	}

	UFortAthenaAIBotHarvestDigestedSkillSet*& GetCacheHarvestDigestedSkillSet()
	{
		static auto CacheHarvestDigestedSkillSetOffset = GetOffset("CacheHarvestDigestedSkillSet");
		return Get<UFortAthenaAIBotHarvestDigestedSkillSet*>(CacheHarvestDigestedSkillSetOffset);
	}

	UFortAthenaAIBotInventoryDigestedSkillSet*& GetCacheInventoryDigestedSkillSet()
	{
		static auto CacheInventoryDigestedSkillSetOffset = GetOffset("CacheInventoryDigestedSkillSet");
		return Get<UFortAthenaAIBotInventoryDigestedSkillSet*>(CacheInventoryDigestedSkillSetOffset);
	}

	UFortAthenaAIBotLootingDigestedSkillSet*& GetCacheLootingSkillSet()
	{
		static auto CacheLootingSkillSetOffset = GetOffset("CacheLootingSkillSet");
		return Get<UFortAthenaAIBotLootingDigestedSkillSet*>(CacheLootingSkillSetOffset);
	}

	UFortAthenaAIBotMovementDigestedSkillSet*& GetCacheMovementSkillSet()
	{
		static auto CacheMovementSkillSetOffset = GetOffset("CacheMovementSkillSet");
		return Get<UFortAthenaAIBotMovementDigestedSkillSet*>(CacheMovementSkillSetOffset);
	}

	UFortAthenaAIBotPerceptionDigestedSkillSet*& GetCachePerceptionDigestedSkillSet()
	{
		static auto CachePerceptionDigestedSkillSetOffset = GetOffset("CachePerceptionDigestedSkillSet");
		return Get<UFortAthenaAIBotPerceptionDigestedSkillSet*>(CachePerceptionDigestedSkillSetOffset);
	}

	UFortAthenaAIBotPlayStyleDigestedSkillSet*& GetCachePlayStyleSkillSet()
	{
		static auto CachePlayStyleSkillSetOffset = GetOffset("CachePlayStyleSkillSet");
		return Get<UFortAthenaAIBotPlayStyleDigestedSkillSet*>(CachePlayStyleSkillSetOffset);
	}

	UPathFollowingComponent* GetPathFollowingComponent()
	{
		static auto PathFollowingComponentOffset = GetOffset("PathFollowingComponent");
		return Get<UPathFollowingComponent*>(PathFollowingComponentOffset);
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

	EPathFollowingRequestResult MoveToActor(AActor* Goal, float AcceptanceRadius, bool bStopOnOverlap, bool bUsePathfinding, bool bCanStrafe, TSubclassOf<UObject> FilterClass, bool bAllowPartialPath)
	{
		static auto MoveToActorFn = FindObject<UFunction>("/Script/AIModule.AIController.MoveToActor");

		struct
		{
			AActor* Goal;
			float AcceptanceRadius;
			bool bStopOnOverlap;
			bool bUsePathfinding;
			bool bCanStrafe;
			TSubclassOf<UObject> FilterClass;
			bool bAllowPartialPath;
			EPathFollowingRequestResult ReturnValue;
		}AAIController_MoveToActor_Params{ Goal , AcceptanceRadius, true, false, true, nullptr, true };

		this->ProcessEvent(MoveToActorFn, &AAIController_MoveToActor_Params);

		return AAIController_MoveToActor_Params.ReturnValue;
	}

	void MoveToLocation(FVector& Dest, float AcceptanceRadius, bool bStopOnOverlap, bool bUsePathfinding, bool bProjectDestinationToNavigation, bool bCanStrafe, TSubclassOf<UObject> FilterClass, bool bAllowPartialPath)
	{
		static auto MoveToLocationFn = FindObject<UFunction>("/Script/AIModule.AIController.MoveToLocation");

		struct
		{
			FVector Dest;
			float AcceptanceRadius;
			bool bStopOnOverlap;
			bool bUsePathfinding;
			bool bProjectDestinationToNavigation;
			bool bCanStrafe;
			TSubclassOf<UObject> FilterClass;
			bool bAllowPartialPath;
			EPathFollowingRequestResult ReturnValue;
		}AAIController_MoveToLocation_Params{ Dest , AcceptanceRadius, bStopOnOverlap, bUsePathfinding, bProjectDestinationToNavigation, bCanStrafe, FilterClass, bAllowPartialPath };

		this->ProcessEvent(MoveToLocationFn, &AAIController_MoveToLocation_Params);
	}

	static void OnPossesedPawnDiedHook(AController* PlayerController, AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);
};