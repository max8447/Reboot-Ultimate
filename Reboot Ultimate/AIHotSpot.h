#pragma once

#include "Actor.h"

class AAIHotSpot : public AActor
{
public:
	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.AIHotSpot");
		return Class;
	}
};