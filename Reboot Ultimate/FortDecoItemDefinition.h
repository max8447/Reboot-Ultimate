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
	static inline void (*ServerCreateBuildingAndSpawnDecoOriginal)(AFortDecoTool* DecoTool, FVector& BuildingLocation, FRotator& BuildingRotation, FVector& Location, FRotator& Rotation, EBuildingAttachmentType InBuildingAttachmentType);

	static void ServerCreateBuildingAndSpawnDecoHook(AFortDecoTool* DecoTool, FVector& BuildingLocation, FRotator& BuildingRotation, FVector& Location, FRotator& Rotation, EBuildingAttachmentType InBuildingAttachmentType);
};