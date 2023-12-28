#pragma once

#include "Array.h"

struct FGameplayAbilitySpecContainer : public FFastArraySerializer
{
	TArray<FGameplayAbilitySpec>& GetItems()
	{
		static auto ItemsOffset = FindOffsetStruct("/Script/GameplayAbilities.GameplayAbilitySpecContainer", "Items");
		return *(TArray<FGameplayAbilitySpec>*)(__int64(this) + ItemsOffset);
	}
};