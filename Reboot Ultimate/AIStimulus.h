#pragma once

#include "reboot.h"

struct FAIStimulus
{
public:
	bool WasSuccessfullySensed()
	{
		static auto bSuccessfullySensedOffset = FindOffsetStruct("/Script/AIModule.AIStimulus", "bSuccessfullySensed");
		return *(bool*)(__int64(this) + bSuccessfullySensedOffset);
	}
};