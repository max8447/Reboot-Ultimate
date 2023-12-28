#pragma once

#include "GameplayAttributeData.h"

#include "reboot.h"

struct FFortGameplayAttributeData : public FGameplayAttributeData
{
	float& GetMinimum()
	{
		static auto MinimumOffset = FindOffsetStruct("/Script/FortniteGame.FortGameplayAttributeData", "Minimum");
		return *(float*)(__int64(this) + MinimumOffset);
	}
};