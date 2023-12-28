#pragma once

struct FGuid
{
	unsigned int A;
	unsigned int B;
	unsigned int C;
	unsigned int D;

	bool operator==(const FGuid& other)
	{
		return A == other.A && B == other.B && C == other.C && D == other.D;
	}

	bool operator!=(const FGuid& other)
	{
		return !(*this == other);
	}
};