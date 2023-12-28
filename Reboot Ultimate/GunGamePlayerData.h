#pragma once

#include "Array.h"
#include "FortWeaponItemDefinition.h"

struct FGunGamePlayerData
{
	TArray<UFortWeaponItemDefinition*>           CurrentlyAssignedWeapons;                                 // 0x0000(0x0010) (ZeroConstructor, NativeAccessSpecifierPublic)
};