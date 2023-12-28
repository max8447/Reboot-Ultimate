#pragma once

#include "SharedPointer.h"
#include "inc.h"
#include "TextData.h"

class FText
{
public:
	TSharedRef<ITextData, ESPMode::ThreadSafe> TextData;
	uint32 Flags;
};