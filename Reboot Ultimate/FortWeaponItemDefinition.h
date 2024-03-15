#pragma once

#include "FortWorldItemDefinition.h"
#include "FortAbilitySet.h"
#include "SoftClassPtr.h"

class UFortWeaponItemDefinition : public UFortWorldItemDefinition
{
public:
	TSoftObjectPtr<UFortAbilitySet> GetEquippedAbilitySet()
	{
		static auto EquippedAbilitySetOffset = GetOffset("EquippedAbilitySet");
		return Get<TSoftObjectPtr<UFortAbilitySet>>(EquippedAbilitySetOffset);
	}

	TArray<TSoftClassPtr<UObject>> GetEquippedAbilities()
	{
		static auto EquippedAbilitiesOffset = GetOffset("EquippedAbilities");
		return Get<TArray<TSoftClassPtr<UObject>>>(EquippedAbilitiesOffset);
	}

	int GetClipSize();
	UFortWorldItemDefinition* GetAmmoData();
	void RemoveGrantedWeaponAbilities(class AFortPlayerControllerAthena* PlayerController);
	void GiveGrantedWeaponAbilities(class AFortPlayerControllerAthena* PlayerController);

	static UClass* StaticClass();
};