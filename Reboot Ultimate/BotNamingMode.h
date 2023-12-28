#pragma once

#include "inc.h"

enum class EBotNamingMode : uint8 // idk if this changes
{
	RealName = 0,
	SkinName = 1,
	Anonymous = 2,
	Custom = 3,
	EBotNamingMode_MAX = 4,
};