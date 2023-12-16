#pragma once

#include "FortWorldItemDefinition.h"

class UFortWeaponItemDefinition : public UFortWorldItemDefinition
{
public:
	int& GetClipSize();
	int& GetSpread();
	TArray<int>& GetDamage();
	UFortWorldItemDefinition* GetAmmoData();

	static UClass* StaticClass();
};