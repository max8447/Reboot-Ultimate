#pragma once

#include "Actor.h"
#include "TSubClassOf.h"
#include "Controller.h"

class APawn : public AActor
{
public:
	UObject* GetPlayerState()
	{
		static auto PlayerStateOffset = GetOffset("PlayerState");
		return Get(PlayerStateOffset);
	}

	TSubclassOf<AController> GetAIControllerClass()
	{
		static auto AIControllerClassOffset = GetOffset("AIControllerClass");
		return Get<TSubclassOf<AController>>(AIControllerClassOffset);
	}

	class AController*& GetController()
	{
		static auto ControllerOffset = GetOffset("Controller");
		return Get<class AController*>(ControllerOffset);
	}
};