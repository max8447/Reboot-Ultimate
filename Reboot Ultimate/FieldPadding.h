#pragma once

#include "Object.h"
#include "Field.h"

struct UFieldPadding : UObject
{
	UField* Next;
	void* pad; void* pad2;
};