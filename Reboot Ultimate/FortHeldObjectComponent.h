#pragma once

#include "ActorComponent.h"

class UFortHeldObjectComponent : public UActorComponent
{
public:
	void OnThrowCompleteHook();
};