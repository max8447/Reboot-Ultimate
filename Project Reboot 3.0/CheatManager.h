#pragma once

#include "Object.h"

class UCheatManager : public UObject
{
public:
	void Teleport();
	void DestroyTarget();
	void God();

	void Mang(std::string Arg);

	static UClass* StaticClass();
};