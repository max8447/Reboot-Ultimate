#pragma once

#include "Object.h"
#include "Frame.h"
#include "TimerHandle.h"
#include "ActiveItemGrantInfo.h"

#include "FortWorldItemDefinition.h"

class UFortGameplayAbilityAthena_PeriodicItemGrant : public UObject // UFortGameplayAbility
{
public:
	static inline void (*StopItemAwardTimersOriginal)(UObject* Context, FFrame& Stack, void* Ret);
	static inline void (*StartItemAwardTimersOriginal)(UObject* Context, FFrame& Stack, void* Ret);

	TMap<FActiveItemGrantInfo, FScalableFloat>& GetItemsToGrant()
	{
		static auto ItemsToGrantOffset = GetOffset("ItemsToGrant");
		return Get<TMap<FActiveItemGrantInfo, FScalableFloat>>(ItemsToGrantOffset);
	}

	TArray<FTimerHandle>& GetActiveTimers()
	{
		static auto ActiveTimersOffset = GetOffset("ActiveTimers");
		return Get<TArray<FTimerHandle>>(ActiveTimersOffset);
	}

	static void StopItemAwardTimersHook(UObject* Context, FFrame& Stack, void* Ret);
	static void StartItemAwardTimersHook(UObject* Context, FFrame& Stack, void* Ret);
};