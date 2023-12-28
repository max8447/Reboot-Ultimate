#pragma once

#include "Object.h"
#include "Name.h"

#include "reboot.h"
#include "DataTable.h"
#include "CurveTableMode.h"
#include "SimpleCurveKey.h"

class UCurveTable : public UObject
{
public:
	static int GetCurveTableSize()
	{
		static auto CurveTableClass = FindObject<UClass>("/Script/Engine.CurveTable");
		return CurveTableClass->GetPropertiesSize();
	}

	ECurveTableMode GetCurveTableMode() const
	{
		static auto CurveTableModeOffset = GetCurveTableSize() - 8;
		return *(ECurveTableMode*)(__int64(this) + CurveTableModeOffset);
	}

	void* GetKey(const FName& RowName, int Index)
	{
		auto CurveTableMode = GetCurveTableMode();

		// LOG_INFO(LogDev, "RowName {} CurveTableMode {} Size {}", RowName.ComparisonIndex.Value ? RowName.ToString() : "InvalidComparision", (int)CurveTableMode, GetCurveTableSize());

		if (CurveTableMode == ECurveTableMode::SimpleCurves)
		{
			auto& RowMap = ((UDataTable*)this)->GetRowMap<FSimpleCurve>(); // its the same offset so
			auto Curve = RowMap.Find(RowName);
			auto& Keys = Curve->GetKeys();
			return Keys.Num() > Index ? &Curve->GetKeys().at(Index) : nullptr;
		}
		else if (CurveTableMode == ECurveTableMode::RichCurves)
		{
			LOG_INFO(LogDev, "RICHCURVE UNIMPLEMENTED!");
		}

		return nullptr;
	}

	float GetValueOfKey(void* Key)
	{
		if (!Key)
			return 0.f;

		auto CurveTableMode = GetCurveTableMode();

		if (CurveTableMode == ECurveTableMode::SimpleCurves) return ((FSimpleCurveKey*)Key)->Value;
		else if (CurveTableMode == ECurveTableMode::RichCurves) return 0.f;

		return 0.f;
	}
};