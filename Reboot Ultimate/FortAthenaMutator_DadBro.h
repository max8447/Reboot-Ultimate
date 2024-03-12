#pragma once

#include "FortAthenaMutator.h"

class AFortAthenaMutator_DadBro : public AFortAthenaMutator
{
public:
	static inline void (*OnGamePhaseStepChangedOriginal)(UObject* Context, FFrame& Stack, void* Ret);

	static void OnGamePhaseStepChangedHook(UObject* Context, FFrame& Stack, void* Ret);
};