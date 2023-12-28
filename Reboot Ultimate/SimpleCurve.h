#pragma once

#include "reboot.h"

#include "RealCurve.h"
#include "SimpleCurveKey.h"
#include "Array.h"

struct FSimpleCurve : public FRealCurve
{
	TArray<FSimpleCurveKey>& GetKeys()
	{
		static auto KeysOffset = FindOffsetStruct("/Script/Engine.SimpleCurve", "Keys");
		return *(TArray<FSimpleCurveKey>*)(__int64(this) + KeysOffset);
	}
};