#pragma once

struct FGameplayAttributeData
{
	float& GetBaseValue()
	{
		static auto BaseValueOffset = FindOffsetStruct("/Script/GameplayAbilities.GameplayAttributeData", "BaseValue");
		return *(float*)(__int64(this) + BaseValueOffset);
	}

	float& GetCurrentValue()
	{
		static auto CurrentValueOffset = FindOffsetStruct("/Script/GameplayAbilities.GameplayAttributeData", "CurrentValue");
		return *(float*)(__int64(this) + CurrentValueOffset);
	}
};