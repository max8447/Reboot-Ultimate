#include "FortPlayerPawnAthena.h"
#include "FortInventory.h"
#include "FortPlayerControllerAthena.h"
#include "quests.h"

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
	
	bool bIsQuest = false;

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
		else
		{
			bIsQuest = true;
		}
	}
	else
	{
		bIsQuest = true;
	}

	constexpr bool bEnableQuests = false;

	if (bEnableQuests && bIsQuest)
	{
		auto PlayerController = Cast<AFortPlayerControllerAthena>(Pawn->GetController());
		auto QuestManager = PlayerController->GetQuestManager(ESubGame::Athena);

		bool QuestActive, QuestCompleted;

		// QuestManager->SendComplexCustomStatEvent(OtherActor, FGameplayTagContainer(), FGameplayTagContainer(), &QuestActive, &QuestCompleted, 1);

		UFortQuestItemDefinition* QuestItem = nullptr;
		FName BackendName;

		static auto QuestItemOffset = OtherActor->GetOffset("QuestItem");
		static auto QuestItemOffset2 = OtherActor->GetOffset("Quest_Item");
		static auto QuestItemOffset3 = OtherActor->GetOffset("QuestItemDefinition");
		static auto BackendNameOffset = OtherActor->GetOffset("BackendName");
		static auto BackendNameOffset2 = OtherActor->GetOffset("Quest_Backend_Name");
		static auto BackendNameOffset3 = OtherActor->GetOffset("ObjectiveBackendName");

		if (!QuestItem && QuestItemOffset != -1)
			QuestItem = OtherActor->Get<UFortQuestItemDefinition*>(QuestItemOffset);

		if (!QuestItem && QuestItemOffset2 != -1)
			QuestItem = OtherActor->Get<UFortQuestItemDefinition*>(QuestItemOffset2);

		if (!QuestItem && QuestItemOffset3 != -1)
			QuestItem = OtherActor->Get<UFortQuestItemDefinition*>(QuestItemOffset3);

		if (BackendName.ComparisonIndex.Value == 0 && BackendNameOffset != -1)
			BackendName = OtherActor->Get<FName>(BackendNameOffset);

		if (BackendName.ComparisonIndex.Value == 0 && BackendNameOffset2 != -1)
			BackendName = OtherActor->Get<FName>(BackendNameOffset2);

		if (BackendName.ComparisonIndex.Value == 0 && BackendNameOffset3 != -1)
			BackendName = OtherActor->Get<FName>(BackendNameOffset3);

		if (QuestItem && BackendName.ComparisonIndex.Value != 0)
		{
			Quests::ProgressQuest(PlayerController, QuestItem, BackendName);
		}
	}

	// return OnCapsuleBeginOverlapOriginal(Context, Stack, Ret); // we love explicit
}