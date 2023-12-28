#pragma once

#include "FortAthenaMutator.h"
#include "reboot.h"
#include "HeistExitCraftSpawnData.h"

class AFortAthenaMutator_Heist : public AFortAthenaMutator
{
public:
	/* TArray<FHeistExitCraftSpawnData>& GetHeistExitCraftSpawnData()
	{
		static auto HeistExitCraftSpawnDataOffset = GetOffset("HeistExitCraftSpawnData");
		return Get<TArray<FHeistExitCraftSpawnData>>(HeistExitCraftSpawnDataOffset);
	} */

	float& GetSpawnExitCraftTime()
	{
		static auto SpawnExitCraftTimeOffset = GetOffset("SpawnExitCraftTime");
		return Get<float>(SpawnExitCraftTimeOffset);
	}
	
	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortAthenaMutator_Heist");
		return Class;
	}
};