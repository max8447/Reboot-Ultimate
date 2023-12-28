#pragma once

#include "Struct.h"
#include "reboot.h"
#include "FortWeaponItemDefinition.h"
#include "ScalableFloat.h"

struct FGunGameGunEntry
{
	static UStruct* GetStruct()
	{
		static auto Struct = FindObject<UStruct>("/Script/FortniteGame.GunGameGunEntry");
		return Struct;
	}

	static int GetStructSize() { return GetStruct()->GetPropertiesSize(); }

	UFortWeaponItemDefinition*& GetWeapon()
	{
		static auto WeaponOffset = FindOffsetStruct("/Script/FortniteGame.GunGameGunEntry", "Weapon");
		return *(UFortWeaponItemDefinition**)(__int64(this) + WeaponOffset);
	}

	FScalableFloat& GetEnabled()
	{
		static auto EnabledOffset = FindOffsetStruct("/Script/FortniteGame.GunGameGunEntry", "Enabled");
		return *(FScalableFloat*)(__int64(this) + EnabledOffset);
	}

	FScalableFloat& GetAwardAtElim()
	{
		static auto AwardAtElimOffset = FindOffsetStruct("/Script/FortniteGame.GunGameGunEntry", "AwardAtElim");
		return *(FScalableFloat*)(__int64(this) + AwardAtElimOffset);
	}
};

struct FGunGameGunEntries
{
	TArray<FGunGameGunEntry>                    Entries;                                                  // 0x0000(0x0010) (ZeroConstructor, NativeAccessSpecifierPublic)
};