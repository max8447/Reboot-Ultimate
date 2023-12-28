#pragma once

#include "Field.h"
#include "inc.h"
#include "Name.h"
#include "Array.h"
#include "String.h"
#include "Pair.h"

class UEnum : public UField
{
public:
	int64 GetValue(const std::string& EnumMemberName)
	{
		auto Names = (TArray<TPair<FName, int64>>*)(__int64(this) + sizeof(UField) + sizeof(FString));

		for (int i = 0; i < Names->Num(); ++i)
		{
			auto& Pair = Names->At(i);
			auto& Name = Pair.Key();
			auto Value = Pair.Value();

			if (Name.ComparisonIndex.Value)
			{
				auto nameStr = Name.ToString();

				if (nameStr.contains(EnumMemberName))
					return Value;
			}
		}

		return -1;
	}
};