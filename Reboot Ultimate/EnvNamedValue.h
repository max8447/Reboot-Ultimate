#pragma once

#include "Name.h"
#include "EAIParamType.h"

struct FEnvNamedValue // i dont thin kthis ever changes
{
	FName ParamName;
	EAIParamType ParamType;
	float Value;
};