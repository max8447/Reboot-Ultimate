#pragma once

#include "Controller.h"
#include "BehaviorTree.h"
#include "BlackboardData.h"
#include "BlackboardComponent.h"
#include "reboot.h"

class AAIController : public AController
{
public:
	UBlackboardComponent* GetBlackboard()
	{
		static auto BlackboardOffset = GetOffset("Blackboard");
		return Get<UBlackboardComponent*>(BlackboardOffset);
	}

	bool RunBehaviorTree(UBehaviorTree* BTAsset)
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

	bool UseBlackboard(UBlackboardData* BlackboardAsset, UBlackboardComponent** BlackboardComponent)
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

	void OnUsingBlackBoard(UBlackboardComponent* BlackboardComp, UBlackboardData* BlackboardAsset)
	{
		static auto OnUsingBlackBoardFn = FindObject<UFunction>("/Script/AIModule.AIController.OnUsingBlackBoard");

		struct
		{
			UBlackboardComponent* BlackboardComp;
			UBlackboardData* BlackboardAsset;
		}AAIController_OnUsingBlackBoard_Params{ BlackboardComp , BlackboardAsset };

		this->ProcessEvent(OnUsingBlackBoardFn, &AAIController_OnUsingBlackBoard_Params);
	}
};