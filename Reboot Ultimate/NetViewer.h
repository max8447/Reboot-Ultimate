#pragma once

#include "Actor.h"
#include "Vector.h"
#include "NetConnection.h"

struct FNetViewer
{
	UNetConnection* Connection;                                               // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	AActor* InViewer;                                                 // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData)
	AActor* ViewTarget;                                               // 0x0010(0x0008) (ZeroConstructor, IsPlainOldData)
	FVector                                     ViewLocation;                                             // 0x0018(0x000C) (IsPlainOldData)
	FVector                                     ViewDir;
};