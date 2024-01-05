#include "FortDecoItemDefinition.h"
#include "BuildingTrap.h"

UClass* UFortDecoItemDefinition::StaticClass()
{
	static auto ptr = FindObject<UClass>("/Script/FortniteGame.FortDecoItemDefinition");
	return ptr;
}