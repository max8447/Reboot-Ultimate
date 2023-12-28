#pragma once

#include "Struct.h"
#include "reboot.h"
#include "AthenaBarrierFlag.h"

struct FBarrierTeamState // Idk if this actually changes
{
	static UStruct* GetStruct()
	{
		static auto Struct = FindObject<UStruct>(L"/Script/FortniteGame.BarrierTeamState");
		return Struct;
	}

	static int GetStructSize() { return GetStruct()->GetPropertiesSize(); }

	EBarrierFoodTeam& GetFoodTeam()
	{
		static auto FoodTeamOffset = FindOffsetStruct("/Script/FortniteGame.BarrierTeamState", "FoodTeam");
		return *(EBarrierFoodTeam*)(__int64(this) + FoodTeamOffset);
	}

	AAthenaBarrierFlag*& GetObjectiveFlag()
	{
		static auto ObjectiveFlagOffset = FindOffsetStruct("/Script/FortniteGame.BarrierTeamState", "ObjectiveFlag");
		return *(AAthenaBarrierFlag**)(__int64(this) + ObjectiveFlagOffset);
	}

	AAthenaBarrierObjective*& GetObjectiveObject()
	{
		static auto ObjectiveObjectOffset = FindOffsetStruct("/Script/FortniteGame.BarrierTeamState", "ObjectiveObject");
		return *(AAthenaBarrierObjective**)(__int64(this) + ObjectiveObjectOffset);
	}
};