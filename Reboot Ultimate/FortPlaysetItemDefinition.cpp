#include "FortPlaysetItemDefinition.h"

#include "PlaysetLevelStreamComponent.h"
#include "FortGameModeAthena.h"

void UFortPlaysetItemDefinition::ShowPlayset(UFortPlaysetItemDefinition* PlaysetItemDef, AFortVolume* Volume)
{
	auto VolumeToUse = Volume;

	static auto PlaysetLevelStreamComponentClass = FindObject<UClass>("/Script/FortniteGame.PlaysetLevelStreamComponent");
	auto LevelStreamComponent = (UPlaysetLevelStreamComponent*)VolumeToUse->GetComponentByClass(PlaysetLevelStreamComponentClass);

	if (!LevelStreamComponent)
		return;

	static auto SetPlaysetFn = FindObject<UFunction>("/Script/FortniteGame.PlaysetLevelStreamComponent.SetPlayset");
	LevelStreamComponent->ProcessEvent(SetPlaysetFn, &PlaysetItemDef);

	LoadPlaysetOriginal(LevelStreamComponent);

	auto ActorClassCount = PlaysetItemDef->GetActorClassCount();

	for (auto& [ActorClass, Count] : ActorClassCount.Pairs)
	{
		for (int i = 0; i < Count; i++)
		{
			auto SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorClass.Get(), Volume->GetActorLocation());
		}
	}
}

UClass* UFortPlaysetItemDefinition::StaticClass()
{
	static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortPlaysetItemDefinition");
	return Class;
}