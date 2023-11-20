#pragma once

#include "Object.h"

class USubsystem : public UObject
{
public:
};

class ULocalPlayerSubsystem : public USubsystem
{
public:
};

class UFortLocalPlayerSubsystem : public ULocalPlayerSubsystem
{
public:
};

class UFortGlobalUIContext : public UFortLocalPlayerSubsystem
{
public:
	void CopyToClipboard(const class FString& ClipboardText);
};