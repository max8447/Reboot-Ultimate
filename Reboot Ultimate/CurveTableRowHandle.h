#pragma once

#include "CurveTable.h"
#include "Name.h"

struct FCurveTableRowHandle
{
	UCurveTable* CurveTable;
	FName RowName;
};