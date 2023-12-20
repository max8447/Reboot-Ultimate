#pragma once

#include "FortWorldItemDefinition.h"

class UFortWeaponItemDefinition : public UFortWorldItemDefinition
{
public:
	int& GetClipSize();
	float& GetSpread();
	TArray<int>& GetDamage();
	UFortWorldItemDefinition* GetAmmoData();
	EFortRarity& GetRarity();
	EFortItemTier& GetTier();

	static UClass* StaticClass();
};