#pragma once

#include "Object.h"
#include "TSubclassOf.h"
#include "Actor.h"

class UCheatManager : public UObject
{
public:
	void Teleport();
	void DestroyTarget();
	void God();
	void DestroyAll(TSubclassOf<AActor> AClass);

	void Mang(std::string Cmd);

	static UClass* StaticClass();
};