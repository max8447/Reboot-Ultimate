#pragma once

#include "reboot.h"

#include "Text.h"
#include "BotNamingMode.h"

class UFortBotNameSettings : public UObject
{
public:
	EBotNamingMode& GetNamingMode()
	{
		static auto NamingModeOffset = GetOffset("NamingMode");
		return Get<EBotNamingMode>(NamingModeOffset);
	}

	FText& GetOverrideName()
	{
		static auto OverrideNameOffset = GetOffset("OverrideName");
		return Get<FText>(OverrideNameOffset);
	}

	bool ShouldAddPlayerIDSuffix()
	{
		static auto bAddPlayerIDSuffixOffset = GetOffset("bAddPlayerIDSuffix");
		return Get<bool>(bAddPlayerIDSuffixOffset);
	}
};