#pragma once

#include "reboot.h"

#include "Actor.h"
#include "Frame.h"

class AFortMinigame : public AActor // AInfo
{
public:
	static inline void (*ClearPlayerInventoryOriginal)(UObject* Context, FFrame& Stack, void* Ret);

	static void ClearPlayerInventoryHook(UObject* Context, FFrame& Stack, void* Ret);
};