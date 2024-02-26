#include "AIBlueprintHelperLibrary.h"

APawn* UAIBlueprintHelperLibrary::SpawnAIFromClass(UObject* WorldContextObject, TSubclassOf<APawn> PawnClass, UBehaviorTree* BehaviorTree, const FVector& Location, const FRotator& Rotation, bool bNoCollisionFail, AActor* Owner)
{
	static auto SpawnAIFromClassFn = FindObject<UFunction>("/Script/AIModule.AIBlueprintHelperLibrary.SpawnAIFromClass");

	struct
	{
		UObject* WorldContextObject;
		TSubclassOf<APawn> PawnClass;
		UBehaviorTree* BehaviorTree;
		FVector Location;
		FRotator Rotation;
		bool bNoCollisionFail;
		AActor* Owner;
		APawn* ReturnValue;
	}AIBlueprintHelperLibrary_SpawnAIFromClass_Params{ WorldContextObject , PawnClass , BehaviorTree , Location , Rotation , bNoCollisionFail , Owner };

	StaticClass()->ProcessEvent(SpawnAIFromClassFn, &AIBlueprintHelperLibrary_SpawnAIFromClass_Params);

	return AIBlueprintHelperLibrary_SpawnAIFromClass_Params.ReturnValue;
}

UClass* UAIBlueprintHelperLibrary::StaticClass()
{
	static auto Class = FindObject<UClass>(L"/Script/AIModule.AIBlueprintHelperLibrary");
	return Class;
}