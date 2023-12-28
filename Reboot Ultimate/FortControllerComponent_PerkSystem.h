#pragma once

#include "ActorComponent.h"
#include "reboot.h"
#include "PerkMutatorData.h"
#include "GameplayTag.h"
#include "PerkItemSet.h"
#include "FortSpyTechItemDefinition.h"

class UFortControllerComponent_PerkSystem : public UActorComponent // UFortControllerComponent
{
public:
	float& GetServerTimeToRelease()
	{
		static auto ServerTimeToReleaseOffset = FindOffsetStruct("/Script/FortniteGame.FortControllerComponent_PerkSystem", "ServerTimeToRelease");
		return *(float*)(__int64(this) + ServerTimeToReleaseOffset);
	}

	FPerkMutatorData& GetMutatorData()
	{
		static auto MutatorDataOffset = FindOffsetStruct("/Script/FortniteGame.FortControllerComponent_PerkSystem", "MutatorData");
		return *(FPerkMutatorData*)(__int64(this) + MutatorDataOffset);
	}


	FGameplayTag GetCachedFactionTag()
	{
		static auto CachedFactionTagOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "CachedFactionTag");
		return *(FGameplayTag*)(__int64(this) + CachedFactionTagOffset);
	}

	TArray<FPerkItemSet> GetPerkSelection()
	{
		static auto PerkSelectionOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "PerkSelection");
		return *(TArray<FPerkItemSet>*)(__int64(this) + PerkSelectionOffset);
	}

	int32& GetRerollCount()
	{
		static auto RerollCountOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "RerollCount");
		return *(int32*)(__int64(this) + RerollCountOffset);
	}

	TArray<UFortSpyTechItemDefinition*> GetSpyTechArray()
	{
		static auto SpyTechArrayOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "SpyTechArray");
		return *(TArray<UFortSpyTechItemDefinition*>*)(__int64(this) + SpyTechArrayOffset);
	}

	TArray<UFortSpyTechItemDefinition*> GetDefaultPerks()
	{
		static auto DefaultPerksOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "DefaultPerks");
		return *(TArray<UFortSpyTechItemDefinition*>*)(__int64(this) + DefaultPerksOffset);
	}

	TArray<UFortSpyTechItemDefinition*> GetAllSelectedPerks()
	{
		static auto AllSelectedPerksOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "AllSelectedPerks");
		return *(TArray<UFortSpyTechItemDefinition*>*)(__int64(this) + AllSelectedPerksOffset);
	}

	FRoundTechDataCache& GetRoundStartCache()
	{
		static auto RoundStartCacheOffset = FindOffsetStruct("/Script/FortniteGame.FortAthenaMutator_PerkSystemMutator", "RoundStartCache");
		return *(FRoundTechDataCache*)(__int64(this) + RoundStartCacheOffset);
	}

	void OnRep_PerkSelection()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortControllerComponent_PerkSystem.OnRep_PerkSelection");
		this->ProcessEvent(fn);
	}

	void OnRep_SpyTechArray()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortControllerComponent_PerkSystem.OnRep_SpyTechArray");
		this->ProcessEvent(fn);
	}

	void OnRep_RerollCount()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortControllerComponent_PerkSystem.OnRep_RerollCount");
		this->ProcessEvent(fn);
	}

	void OnRep_ServerTimeToRelease()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortControllerComponent_PerkSystem.OnRep_ServerTimeToRelease");
		this->ProcessEvent(fn);
	}

	void OnRep_AllSelectedPerks()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortControllerComponent_PerkSystem.OnRep_AllSelectedPerks");
		this->ProcessEvent(fn);
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>("/Script/FortniteGame.FortControllerComponent_PerkSystem");
		return Class;
	}
};