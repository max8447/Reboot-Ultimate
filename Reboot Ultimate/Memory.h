#pragma once

#include "inc.h"

struct FMemory
{
	static inline void* (*Realloc)(void* Original, SIZE_T Count, uint32_t Alignment /* = DEFAULT_ALIGNMENT */);
};

template <typename T = __int64>
static T* AllocUnreal(size_t Size)
{
	return (T*)FMemory::Realloc(0, Size, 0);
}