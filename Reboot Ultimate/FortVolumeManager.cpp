#include "FortVolumeManager.h"

#include "FortGameModeAthena.h"

AFortVolume* AFortVolumeManager::SpawnVolumeHook(AFortVolumeManager* VolumeManager, UClass* VolumeActor, UFortPlaysetItemDefinition* Playset, FVector Location, FRotator Rotation)
{
	// They inlined SetPlayset idk why

	static auto VolumeObjectsOffset = VolumeManager->GetOffset("VolumeObjects");
	auto& VolumeObjects = VolumeManager->Get<TArray<AFortVolume*>>(VolumeObjectsOffset);

	LOG_INFO(LogDev, "SpawnVolumeHook!");
	auto Volume = SpawnVolumeOriginal(VolumeManager, VolumeActor, Playset, Location, Rotation);

	return Volume;
}