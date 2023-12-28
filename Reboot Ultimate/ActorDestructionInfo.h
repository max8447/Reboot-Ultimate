#pragma once

#include "WeakObjectPtrTemplates.h"
#include "Level.h"
#include "Vector.h"
#include "String.h"
#include "Name.h"
#include "NetworkGuid.h"

struct FActorDestructionInfo
{
	TWeakObjectPtr<ULevel>		Level;
	TWeakObjectPtr<UObject>		ObjOuter;
	FVector			DestroyedPosition;
	FNetworkGUID	NetGUID;
	FString			PathName;
	FName			StreamingLevelName;
};