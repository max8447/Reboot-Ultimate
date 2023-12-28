#pragma once

#include "FortAthenaMutator.h"

#include "FortAthenaMutator_TDM.h"
#include "ActorComponent.h"
#include "PerkMutatorData.h"
#include "PerkItemSet.h"
#include "RoundTechDataCache.h"
#include "FortAthenaMutator_SpyRumble.h"

class AFortAthenaMutator_PerkSystemMutator : public AFortAthenaMutator
{
public:
	FPerkMutatorData& GetMutatorData()
	{
		static auto MutatorDataOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "MutatorData");
		return *(FPerkMutatorData*)(__int64(this) + MutatorDataOffset);
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>("/Script/FortniteGame.AFortAthenaMutator_SpyRumble");
		return Class;
	}
};