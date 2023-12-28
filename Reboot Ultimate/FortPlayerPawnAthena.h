#pragma once

#include "FortPlayerPawn.h"
#include "HitResult.h"

class AFortPlayerPawnAthena : public AFortPlayerPawn
{
public:
	static inline void (*OnCapsuleBeginOverlapOriginal)(UObject* Context, FFrame* Stack, void* Ret);

	uint8& GetDBNORevivalStacking()
	{
		static auto DBNORevivalStackingOffset = GetOffset("DBNORevivalStacking");
		return Get<uint8>(DBNORevivalStackingOffset);
	}

	static void OnCapsuleBeginOverlapHook(UObject* Context, FFrame* Stack, void* Ret);
};

namespace OnCapsuleBeginOverlap
{
	using UPrimitiveComponent = UActorComponent; // USceneComponent

	static void (*OnCapsuleBeginOverlapOG)(UObject* Pawn, UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, FHitResult SweepResult);
	void OnCapsuleBeginOverlapHook(AFortPlayerPawnAthena* Pawn, UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, FHitResult SweepResult);
}