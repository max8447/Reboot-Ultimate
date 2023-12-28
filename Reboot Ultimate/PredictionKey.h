#pragma once

#include "Class.h"

struct FPredictionKey // todo move
{
	// __int64 real;

	static UStruct* GetStruct()
	{
		static auto Struct = FindObject<UStruct>("/Script/GameplayAbilities.PredictionKey");
		return Struct;
	}

	static int GetStructSize() { return GetStruct()->GetPropertiesSize(); }
};