#pragma once

#include "NameTypes.h"

enum class EAIParamType : uint8
{
	Float,
	Int,
	Bool
	// MAX UMETA(Hidden)
};

enum class EPathFollowingRequestResult : uint8
{
	Failed = 0,
	AlreadyAtGoal = 1,
	RequestSuccessful = 2,
	EPathFollowingRequestResult_MAX = 3,
};

struct FEnvNamedValue // i dont thin kthis ever changes
{
	FName ParamName;
	EAIParamType ParamType;
	float Value;
};