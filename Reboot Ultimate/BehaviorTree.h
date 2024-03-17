#pragma once

#include "BlackboardData.h"

class UBehaviorTree : public UObject
{
public:
	UBlackboardData* GetBlackboardAsset()
	{
		static auto BlackboardAssetOffset = GetOffset("BlackboardAsset");
		return Get<UBlackboardData*>(BlackboardAssetOffset);
	}
};