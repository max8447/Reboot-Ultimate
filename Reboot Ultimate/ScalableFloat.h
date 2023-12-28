#pragma once

#include "reboot.h"
#include "CurveTableRowHandle.h"

struct FScalableFloat
{
	float& GetValue()
	{
		static auto FloatOffset = FindOffsetStruct("/Script/GameplayAbilities.ScalableFloat", "Value");
		return *(float*)(__int64(this) + FloatOffset);
	}

	FCurveTableRowHandle& GetCurve()
	{
		static auto CurveOffset = FindOffsetStruct("/Script/GameplayAbilities.ScalableFloat", "Curve");
		return *(FCurveTableRowHandle*)(__int64(this) + CurveOffset);
	}
};