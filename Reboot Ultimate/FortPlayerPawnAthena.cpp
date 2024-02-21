#include "FortPlayerPawnAthena.h"
#include "FortInventory.h"
#include "FortPlayerControllerAthena.h"

void AFortPlayerPawnAthena::OnCapsuleBeginOverlapHook(UObject* Context, FFrame* Stack, void* Ret)
{
	using UPrimitiveComponent = UObject;

	auto Pawn = (AFortPlayerPawnAthena*)Context;
	UPrimitiveComponent* OverlappedComp;
	AActor* OtherActor;
	UPrimitiveComponent* OtherComp;
	int OtherBodyIndex;
	bool bFromSweep;
	auto SweepResultPtr = (FHitResult*)std::realloc(0, FHitResult::GetStructSize());

	LOG_INFO(LogDev, "OnCapsuleBeginOverlapHook!");

	Stack->StepCompiledIn(&OverlappedComp);
	Stack->StepCompiledIn(&OtherActor);
	Stack->StepCompiledIn(&OtherComp);
	Stack->StepCompiledIn(&OtherBodyIndex);
	Stack->StepCompiledIn(&bFromSweep);
	Stack->StepCompiledIn(SweepResultPtr);

	std::free(SweepResultPtr);

	LOG_INFO(LogDev, "OtherActor: {}", OtherActor->IsValidLowLevel() ? OtherActor->GetFullName() : "BadRead");
	LOG_INFO(LogDev, "OverlappedComp: {}", OverlappedComp->GetFullName());
	LOG_INFO(LogDev, "OtherComp: {}", OtherComp->GetFullName());
	LOG_INFO(LogDev, "OtherBodyIndex: {}", OtherBodyIndex);
	LOG_INFO(LogDev, "bFromSweep: {}", (bool)bFromSweep);
	
	if (!Pawn->IsDBNO())
	{
		if (auto Pickup = Cast<AFortPickup>(OtherActor))
		{
			static auto PawnWhoDroppedPickupOffset = Pickup->GetOffset("PawnWhoDroppedPickup");

			if (Pickup->Get<AFortPawn*>(PawnWhoDroppedPickupOffset) != Pawn)
			{
				auto ItemDefinition = Pickup->GetPrimaryPickupItemEntry()->GetItemDefinition();

				if (!ItemDefinition)
				{
					return;
				}

				if (!IsPrimaryQuickbar(ItemDefinition))
				{
					ServerHandlePickupHook(Pawn, Pickup, 0.4f, FVector(), true);
				}
			}
		}
		/*
		
		else
		{
			auto PlayerController = Cast<AFortPlayerControllerAthena>(Pawn->GetController());
			auto QuestManager = PlayerController->GetQuestManager(ESubGame::Athena);

			bool QuestActive, QuestCompleted;

			QuestManager->SendComplexCustomStatEvent(OtherActor, FGameplayTagContainer(), FGameplayTagContainer(), &QuestActive, &QuestCompleted, 1);
		}

		*/
	}

	// return OnCapsuleBeginOverlapOriginal(Context, Stack, Ret); // we love explicit
}