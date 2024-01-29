#pragma once

#include "reboot.h"

#include "Controller.h"
#include "Stack.h"
#include "FortInventory.h"
#include "EnvQueryTypes.h"
#include "FortAthenaAIBotDigestedSkillSet.h"
#include "FortAthenaAIBotSkillSet.h"
#include "PathFollowingComponent.h"
#include "FortPlayerController.h"

class AAIController : public AController
{
public:
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

	void SetFocalPoint(FVector FP)
	{
		static auto fn = FindObject<UFunction>("/Script/AIModule.AIController.K2_SetFocalPoint");
		this->ProcessEvent(fn, &FP);
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

	EPathFollowingRequestResult MoveToLocation(FVector& Dest, float AcceptanceRadius, bool bStopOnOverlap, bool bUsePathfinding, bool bProjectDestinationToNavigation, bool bCanStrafe, TSubclassOf<UObject> FilterClass, bool bAllowPartialPath)
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

		return AAIController_MoveToLocation_Params.ReturnValue;
	}
};

struct FAIStimulus
{
public:
	float                                        Age;                                               // 0x0(0x4)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	float                                        ExpirationAge;                                     // 0x4(0x4)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	float                                        Strength;                                          // 0x8(0x4)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	FVector										 StimulusLocation;                                  // 0xC(0xC)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	FVector										 ReceiverLocation;                                  // 0x18(0xC)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	FName										 Tag;                                               // 0x24(0x8)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_1226[0xC];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	uint8                                        BitPad_C0 : 1;                                     // Fixing Bit-Field Size  [ Dumper-7 ]
	uint8                                        bSuccessfullySensed : 1;                           // Mask: 0x2, PropSize: 0x10x38(0x1)(BlueprintVisible, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                        Pad_1227[0x3];                                     // Fixing Size Of Struct [ Dumper-7 ]
};

class AFortAthenaAIBotController : public AAIController
{
public:
	using UPrimitiveComponent = UObject;

	static inline void (*OnPossesedPawnDiedOriginal)(AController* PlayerController, AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);
	static inline void (*OnPerceptionSensedOriginal)(AController* PlayerController, AActor* SourceActor, FAIStimulus& Stim);

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

	TArray<TSubclassOf<UFortAthenaAIBotSkillSet>> GetBotSkillSetClasses()
	{
		static auto BotSkillSetClassesOffset = GetOffset("BotSkillSetClasses");
		return Get<TArray<TSubclassOf<UFortAthenaAIBotSkillSet>>>(BotSkillSetClassesOffset);
	}
	
	UPathFollowingComponent* GetPathFollowingComponent()
	{
		static auto PathFollowingComponentOffset = GetOffset("PathFollowingComponent");
		return Get<UPathFollowingComponent*>(PathFollowingComponentOffset);
	}

	FString& GetBotPlayerName()
	{
		static auto BotPlayerNameOffset = GetOffset("BotPlayerName");
		return Get<FString>(BotPlayerNameOffset);
	}

	void ThankBusDriver()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaAIBotController.ThankBusDriver");
		this->ProcessEvent(fn);
	}

	static void OnPossesedPawnDiedHook(AController* PlayerController, AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);
	static void OnPerceptionSensedHook(AFortAthenaAIBotController* PlayerController, AActor* SourceActor, FAIStimulus& Stim);
};