#include "FortDecoItemDefinition.h"
#include "BuildingTrap.h"

UClass* UFortDecoItemDefinition::StaticClass()
{
	static auto ptr = FindObject<UClass>("/Script/FortniteGame.FortDecoItemDefinition");
	return ptr;
}

void AFortDecoTool::ServerCreateBuildingAndSpawnDecoHook(AFortDecoTool* DecoTool, FVector& BuildingLocation, FRotator& BuildingRotation, FVector& Location, FRotator& Rotation, EBuildingAttachmentType InBuildingAttachmentType)
{
	LOG_INFO(LogDev, __FUNCTION__);

	LOG_INFO(LogDev, "BuildingLocation: {}", BuildingLocation.ToString().ToString());
	LOG_INFO(LogDev, "BuildingLocation: {}", BuildingRotation.Vector().ToString().ToString());
	LOG_INFO(LogDev, "BuildingLocation: {}", Location.ToString().ToString());
	LOG_INFO(LogDev, "BuildingLocation: {}", Rotation.Vector().ToString().ToString());
	LOG_INFO(LogDev, "BuildingLocation: {}", (int)InBuildingAttachmentType);

	return ServerCreateBuildingAndSpawnDecoOriginal(DecoTool, BuildingLocation, BuildingRotation, Location, Rotation, InBuildingAttachmentType);
}