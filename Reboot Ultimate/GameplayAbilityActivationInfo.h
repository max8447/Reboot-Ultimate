#pragma once

#include "Class.h"

struct FGameplayAbilityActivationInfo // TODO Move
{
	static UStruct* GetStruct()
	{
		static auto Struct = FindObject<UStruct>("/Script/GameplayAbilities.GameplayAbilityActivationInfo");
		return Struct;
	}

	static int GetStructSize() { return GetStruct()->GetPropertiesSize(); }
};