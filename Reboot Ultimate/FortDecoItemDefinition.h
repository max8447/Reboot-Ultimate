#pragma once

#include "FortWeaponItemDefinition.h"
#include "FortWeapon.h"

class UFortDecoItemDefinition : public UFortWeaponItemDefinition
{
public:

	static UClass* StaticClass();
};

enum class EBuildingAttachmentType : uint8
{
	ATTACH_Floor = 0,
	ATTACH_Wall = 1,
	ATTACH_Ceiling = 2,
	ATTACH_Corner = 3,
	ATTACH_All = 4,
	ATTACH_WallThenFloor = 5,
	ATTACH_FloorAndStairs = 6,
	ATTACH_CeilingAndStairs = 7,
	ATTACH_StairsBothSides = 8,
	ATTACH_None = 9,
	ATTACH_MAX = 10,
};

class AFortDecoTool : public AFortWeapon
{
public:
	using FVector_NetQuantize10 = FVector;
	static inline void (*ServerCreateBuildingAndSpawnDecoOriginal)(UObject* Context, FFrame& Stack, void* Ret);

	static void ServerCreateBuildingAndSpawnDecoHook(UObject* Context, FFrame& Stack, void* Ret);
};