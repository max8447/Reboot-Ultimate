#pragma once

#include "GameplayAbilitySpecHandle.h"
#include "inc.h"

struct FGameplayAbilitySpecHandleAndPredictionKey
{
	FGameplayAbilitySpecHandle AbilityHandle;
	int32 PredictionKeyAtCreation;
};