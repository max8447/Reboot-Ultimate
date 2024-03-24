#pragma once

#include "Array.h"
#include "reboot.h"
#include "FortBotTargetInfo.h"

struct FFortBotTargetHandler
{
public:
	TArray<FFortBotTargetInfo> GetTargets()
	{
		static auto TargetsOffset = FindOffsetStruct("/Script/FortniteGame.FortBotTargetHandler", "Targets");
		return *(TArray<FFortBotTargetInfo>*)(__int64(this) + TargetsOffset);
	}
};