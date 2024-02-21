#pragma once

#include "Object.h"

class UKismetMathLibrary : public UObject
{
public:
	static float RandomFloatInRange(float min, float max);
	static int RandomIntegerInRange(int min, int max);
	static bool RandomBoolWithWeight(float weight);

	static UClass* StaticClass();
};