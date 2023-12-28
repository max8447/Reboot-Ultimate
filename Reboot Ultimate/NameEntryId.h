#pragma once

#include "inc.h"

struct FNameEntryId
{
	uint32 Value; // well depends on version if its int32 or uint32 i think

	FNameEntryId() : Value(0) {}

	FNameEntryId(uint32 value) : Value(value) {}

	bool operator<(FNameEntryId Rhs) const { return Value < Rhs.Value; }
	bool operator>(FNameEntryId Rhs) const { return Rhs.Value < Value; }
	bool operator==(FNameEntryId Rhs) const { return Value == Rhs.Value; }
	bool operator!=(FNameEntryId Rhs) const { return Value != Rhs.Value; }
};