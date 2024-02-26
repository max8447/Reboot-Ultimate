#pragma once

#include "TSubClassOf.h"
#include "BehaviorTree.h"
#include "FortPawn.h"

class UAIBlueprintHelperLibrary : public UObject
{
public:
	static APawn* SpawnAIFromClass(UObject* WorldContextObject, TSubclassOf<APawn> PawnClass, UBehaviorTree* BehaviorTree, const FVector& Location, const FRotator& Rotation, bool bNoCollisionFail, AActor* Owner);

	static UClass* StaticClass();
};