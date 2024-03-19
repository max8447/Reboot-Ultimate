#include "AIController.h"

bool AAIController::RunBehaviorTree(UBehaviorTree* BTAsset)
{
	static auto RunBehaviorTreeFn = FindObject<UFunction>("/Script/AIModule.AIController.RunBehaviorTree");

	struct
	{
		UBehaviorTree* BTAsset;
		bool ReturnValue;
	}AAIController_RunBehaviorTree_Params{ BTAsset };

	this->ProcessEvent(RunBehaviorTreeFn, &AAIController_RunBehaviorTree_Params);

	return AAIController_RunBehaviorTree_Params.ReturnValue;
}

bool AAIController::UseBlackboard(UBlackboardData* BlackboardAsset, UBlackboardComponent** BlackboardComponent)
{
	static auto UseBlackboardFn = FindObject<UFunction>("/Script/AIModule.AIController.UseBlackboard");

	struct
	{
		UBlackboardData* BlackboardAsset;
		UBlackboardComponent* BlackboardComponent;
		bool ReturnValue;
	}AAIController_UseBlackboard_Params{ BlackboardAsset };

	this->ProcessEvent(UseBlackboardFn, &AAIController_UseBlackboard_Params);

	if (BlackboardComponent)
		*BlackboardComponent = AAIController_UseBlackboard_Params.BlackboardComponent;

	return AAIController_UseBlackboard_Params.ReturnValue;
}

void AAIController::OnUsingBlackBoard(UBlackboardComponent* BlackboardComp, UBlackboardData* BlackboardAsset)
{
	static auto OnUsingBlackBoardFn = FindObject<UFunction>("/Script/AIModule.AIController.OnUsingBlackBoard");

	struct
	{
		UBlackboardComponent* BlackboardComp;
		UBlackboardData* BlackboardAsset;
	}AAIController_OnUsingBlackBoard_Params{ BlackboardComp , BlackboardAsset };

	this->ProcessEvent(OnUsingBlackBoardFn, &AAIController_OnUsingBlackBoard_Params);
}

EPathFollowingRequestResult AAIController::MoveToLocation(FVector Dest, float AcceptanceRadius, bool bStopOnOverlap, bool bUsePathfinding, bool bProjectDestinationToNavigation, bool bCanStrafe, TSubclassOf<UNavigationQueryFilter> FilterClass, bool bAllowPartialPath)
{
	static auto MoveToLocationFn = FindObject<UFunction>("/Script/AIModule.AIController.MoveToLocation");

	struct
	{
		FVector Dest;
		float AcceptanceRadius;
		bool bStopOnOverlap;
		bool bUsePathfinding;
		bool bProjectDestinationToNavigation;
		bool bCanStrafe;
		TSubclassOf<UNavigationQueryFilter> FilterClass;
		bool bAllowPartialPath;
		EPathFollowingRequestResult ReturnValue;
	}AAIController_MoveToLocation_Params{ Dest , AcceptanceRadius , bStopOnOverlap , bUsePathfinding , bProjectDestinationToNavigation , bCanStrafe , FilterClass , bAllowPartialPath };

	this->ProcessEvent(MoveToLocationFn, &AAIController_MoveToLocation_Params);

	return AAIController_MoveToLocation_Params.ReturnValue;
}

EPathFollowingRequestResult AAIController::MoveToActor(AActor* Goal, float AcceptanceRadius, bool bStopOnOverlap, bool bUsePathfinding, bool bCanStrafe, TSubclassOf<UNavigationQueryFilter> FilterClass, bool bAllowPartialPath)
{
	static auto MoveToActorFn = FindObject<UFunction>("/Script/AIModule.AIController.MoveToActor");

	struct
	{
		AActor* Goal;
		float AcceptanceRadius;
		bool bStopOnOverlap;
		bool bUsePathfinding;
		bool bCanStrafe;
		TSubclassOf<UNavigationQueryFilter> FilterClass;
		bool bAllowPartialPath;
		EPathFollowingRequestResult ReturnValue;
	}AAIController_MoveToActor_Params{ Goal , AcceptanceRadius , bStopOnOverlap , bUsePathfinding , bCanStrafe , FilterClass , bAllowPartialPath };

	this->ProcessEvent(MoveToActorFn, &AAIController_MoveToActor_Params);

	return AAIController_MoveToActor_Params.ReturnValue;
}