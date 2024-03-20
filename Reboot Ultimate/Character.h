#pragma once

#include "Pawn.h"

class ACharacter : public APawn
{
public:
	bool IsCrouched()
	{
		static auto bIsCrouchedOffset = GetOffset("bIsCrouched");
		static auto bIsCrouchedFieldMask = GetFieldMask(GetProperty("bIsCrouched"));
		return ReadBitfieldValue(bIsCrouchedOffset, bIsCrouchedFieldMask);
	}

	void Crouch(bool bClientSimulation)
	{
		static auto CrouchFn = FindObject<UFunction>("/Script/Engine.Character.Crouch");
		this->ProcessEvent(CrouchFn, &bClientSimulation);
	}

	void UnCrouch(bool bClientSimulation)
	{
		static auto UnCrouchFn = FindObject<UFunction>("/Script/Engine.Character.UnCrouch");
		this->ProcessEvent(UnCrouchFn, &bClientSimulation);
	}
};