#include "FortDecoItemDefinition.h"
#include "BuildingTrap.h"

UClass* UFortDecoItemDefinition::StaticClass()
{
	static auto ptr = FindObject<UClass>("/Script/FortniteGame.FortDecoItemDefinition");
	return ptr;
}

void AFortDecoTool::ServerCreateBuildingAndSpawnDecoHook(UObject* Context, FFrame& Stack, void* Ret)
{
	LOG_INFO(LogDev, __FUNCTION__);

	auto DecoTool = (AFortDecoTool*)Context;

	FVector_NetQuantize10 BuildingLocation;
	FRotator BuildingRotation;
	FVector_NetQuantize10 Location;
	FRotator Rotation;
	EBuildingAttachmentType InBuildingAttachmentType;

	Stack.StepCompiledIn(&BuildingLocation);
	Stack.StepCompiledIn(&BuildingRotation);
	Stack.StepCompiledIn(&Location);
	Stack.StepCompiledIn(&Rotation);
	Stack.StepCompiledIn(&InBuildingAttachmentType);

	LOG_INFO(LogDev, "BuildingLocation: {}", BuildingLocation.ToString().ToString());
	LOG_INFO(LogDev, "BuildingLocation: {}", BuildingRotation.Vector().ToString().ToString());
	LOG_INFO(LogDev, "BuildingLocation: {}", Location.ToString().ToString());
	LOG_INFO(LogDev, "BuildingLocation: {}", Rotation.Vector().ToString().ToString());
	LOG_INFO(LogDev, "BuildingLocation: {}", (int)InBuildingAttachmentType);

	return ServerCreateBuildingAndSpawnDecoOriginal(Context, Stack, Ret);
}