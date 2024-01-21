#pragma once

#include "Object.h"

class UAthenaNavSystem : public UObject // UFortNavSystem
{
public:
	ANavigationData* GetMainNavData()
	{
		static auto MainNavDataOffset = GetOffset("MainNavData");
		return Get<ANavigationData*>(MainNavDataOffset);
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.AthenaNavSystem");
		return Class;
	}
};