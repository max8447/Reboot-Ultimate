#pragma once

#include "BuildingActor.h"

struct FFortBotTargetInfo
{
public:
	AActor* GetSourceActor()
	{
		static auto SourceActorOffset = FindOffsetStruct("/Script/FortniteGame.FortBotTargetInfo", "SourceActor");
		return *(AActor**)(__int64(this) + SourceActorOffset);
	}
};