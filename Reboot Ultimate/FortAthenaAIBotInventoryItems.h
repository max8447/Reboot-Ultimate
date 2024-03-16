#pragma once

#include "FortItemDefinition.h"

class UFortAthenaAIBotInventoryItems : public UObject
{
public:
	TArray<FItemAndCount> GetItems()
	{
		static auto ItemsOffset = GetOffset("Items");
		return Get<TArray<FItemAndCount>>(ItemsOffset);
	}
};