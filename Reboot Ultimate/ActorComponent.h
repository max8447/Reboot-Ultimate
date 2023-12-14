#pragma once

#include "Actor.h"

class UActorComponent : public UObject
{
public:
	AActor* GetOwner();
};

class UFortHeldObjectComponent : public UActorComponent
{
public:
	void OnThrowCompleteHook();
};