#pragma once

#include "Controller.h"
#include "BehaviorTree.h"
#include "BlackboardData.h"
#include "BlackboardComponent.h"
#include "reboot.h"
#include "PathFollowingTypes.h"
#include "TSubClassOf.h"

using UNavigationQueryFilter = UObject;

class AAIController : public AController
{
public:

	UBlackboardComponent* GetBlackboard()
	{
		static auto BlackboardOffset = GetOffset("Blackboard");
		return Get<UBlackboardComponent*>(BlackboardOffset);
	}

	bool RunBehaviorTree(UBehaviorTree* BTAsset);
	bool UseBlackboard(UBlackboardData* BlackboardAsset, UBlackboardComponent** BlackboardComponent);
	void OnUsingBlackBoard(UBlackboardComponent* BlackboardComp, UBlackboardData* BlackboardAsset);
	EPathFollowingRequestResult MoveToLocation(FVector Dest, float AcceptanceRadius, bool bStopOnOverlap, bool bUsePathfinding, bool bProjectDestinationToNavigation, bool bCanStrafe, TSubclassOf<UNavigationQueryFilter> FilterClass, bool bAllowPartialPath);
	EPathFollowingRequestResult MoveToActor(AActor* Goal, float AcceptanceRadius, bool bStopOnOverlap, bool bUsePathfinding, bool bCanStrafe, TSubclassOf<UNavigationQueryFilter> FilterClass, bool bAllowPartialPath);
};