#pragma once

#include "FortAthenaMutator_TDM.h"
#include "Class.h"

class AFortAthenaMutator_SpyRumble : public AFortAthenaMutator_TDM
{
public:
	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>("/Script/FortniteGame.AFortAthenaMutator_SpyRumble");
		return Class;
	}
};