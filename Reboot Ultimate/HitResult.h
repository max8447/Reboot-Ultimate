#pragma once

#include "Vector.h"

struct FHitResult
{
	static class UStruct* GetStruct();
	static int GetStructSize();

	bool IsBlockingHit();
	FVector& GetLocation();
	void CopyFromHitResult(FHitResult* Other);
};