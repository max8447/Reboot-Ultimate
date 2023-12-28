#pragma once

#include "Array.h"
#include "inc.h"

struct FPerkItemSet
{
public:
	TArray<UFortSpyTechItemDefinition*>    Items;                                             // 0x0(0x10)(ZeroConstructor, NativeAccessSpecifierPublic)
	float                                        Time;                                              // 0x10(0x4)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_4C89[0x4];                                     // Fixing Size Of Struct [ Dumper-7 ]
};