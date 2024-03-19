#pragma once

#include "inc.h"

enum class EPathFollowingRequestResult : uint8
{
	Failed = 0,
	AlreadyAtGoal = 1,
	RequestSuccessful = 2,
	EPathFollowingRequestResult_MAX = 3,
};

enum class EPathFollowingAction : uint8
{
	Error = 0,
	NoMove = 1,
	DirectMove = 2,
	PartialPath = 3,
	PathToGoal = 4,
	EPathFollowingAction_MAX = 5,
};

enum class EPathFollowingStatus : uint8
{
	Idle = 0,
	Waiting = 1,
	Paused = 2,
	Moving = 3,
	EPathFollowingStatus_MAX = 4,
};