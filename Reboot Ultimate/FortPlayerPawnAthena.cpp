#include "FortPlayerPawnAthena.h"
#include "FortInventory.h"
#include "FortPlayerControllerAthena.h"

void AFortPlayerPawnAthena::OnCapsuleBeginOverlapHook(UObject* Context, FFrame* Stack, void* Ret)
{
	using UPrimitiveComponent = UObject;

	auto Pawn = (AFortPlayerPawnAthena*)Context;
	auto PlayerController = Cast<AFortPlayerControllerAthena>(Pawn->GetController());
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

	static UClass* CoinClass = FindObject<UClass>("/Game/Athena/Items/QuestInteractables/ItemCollection/BP_ItemCollection_Touch.BP_ItemCollection_Touch_C");
	static UClass* BoatTimedClass = FindObject<UClass>("/Game/Athena/Items/QuestInteractables/TimedChallenge/BoatTrial/Prop_QuestInteractable_TimeTrials_Boat.Prop_QuestInteractable_TimeTrials_Boat_C");
	static UClass* FireClass = FindObject<UClass>("/Game/Athena/Items/QuestInteractables/FlamingHoops/Boat/Actor_QuestObject_Touch_FlamingHoopsBoat_Parent.Actor_QuestObject_Touch_FlamingHoopsBoat_Parent_C");

	// LOG_INFO(LogDev, "OtherActor: {}", __int64(OtherActor));
	// LOG_INFO(LogDev, "OtherActorName: {}", OtherActor->IsValidLowLevel() ? OtherActor->GetName() : "BadRead")

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

		else if (OtherActor->IsA(CoinClass) && OtherComp->GetName() == "CollectOverlap")
		{
			// static auto BackendNameProp = FindObject<UProperty>("/Game/Athena/Items/QuestInteractables/ItemCollection/BP_ItemCollection_Touch.BP_ItemCollection_Touch_C.QuestBackendName");
			static auto QuestItemProp = FindObject<UProperty>("/Game/Athena/Items/QuestInteractables/ItemCollection/BP_ItemCollection_Touch.BP_ItemCollection_Touch_C.CollectItemQuest");
			static auto ParentQuestUpdatedFn = FindObject<UFunction>("/Game/Athena/Items/QuestInteractables/ItemCollection/BP_ItemCollection_Touch.BP_ItemCollection_Touch_C.ParentQuestUpdated");

			FName BackendName = *(FName*)(__int64(OtherActor) + BackendNameProp->Offset);

			UFortQuestItemDefinition* QuestDef = *(UFortQuestItemDefinition**)(__int64(OtherActor) + QuestItemProp->Offset);

			if (!QuestDef)
				return OnCapsuleBeginOverlapOriginal(Context, Stack, Ret);

			PlayerController->ProgressQuest(PlayerController, QuestDef, BackendName);
			OtherActor->ProcessEvent(ParentQuestUpdatedFn, nullptr);
		}
		else if (Pawn->IsInVehicle() && OtherActor->IsA(BoatTimedClass))
		{
			std::string OverlapName = OtherComp->GetName();
			if (OverlapName.contains("CP"))
			{
				std::string Number = SplitString(true, "CP", OverlapName);
				std::string Ok = SplitString(false, (OverlapName.contains("Collision") ? "Collision" : "Coll"), Number);
				int Idx = std::stoi(Ok) - 1;

				static auto GateHitFn = FindObject<UFunction>("/Game/Athena/Items/QuestInteractables/TimedChallenge/BoatTrial/Prop_QuestInteractable_TimeTrials_Boat.Prop_QuestInteractable_TimeTrials_Boat_C.QuestItem");

				OtherActor->ProcessEvent(GateHitFn, &Idx);

				if (Idx == 7)
				{
					static auto QuestItemProp = FindObject<UProperty>("/Game/Athena/Items/QuestInteractables/TimedChallenge/BoatTrial/Prop_QuestInteractable_TimeTrials_Boat.Prop_QuestInteractable_TimeTrials_Boat_C.QuestItem");
					static auto QuestBackendObjectiveName = FindObject<UProperty>("/Game/Athena/Items/QuestInteractables/TimedChallenge/BoatTrial/Prop_QuestInteractable_TimeTrials_Boat.Prop_QuestInteractable_TimeTrials_Boat_C.QuestBackendObjectiveName");

					auto Backendname = *(FName*)(__int64(OtherActor) + QuestBackendObjectiveName->Offset);
					auto Quest = *(UFortQuestItemDefinition**)(__int64(OtherActor) + QuestItemProp->Offset);
					auto QuestManager = PlayerController->GetQuestManager(ESubGame::Athena);

					if (!QuestManager->GetQuestWithDefinition(Quest)->HasCompletedObjectiveWithName(Backendname))
					{
						PlayerController->ProgressQuest(PlayerController, Quest, Backendname);

						static auto PlaySuccessFXFn = FindObject<UFunction>("/Game/Athena/Items/QuestInteractables/TimedChallenge/BoatTrial/Prop_QuestInteractable_TimeTrials_Boat.Prop_QuestInteractable_TimeTrials_Boat_C.PlaySuccessFX");
						static auto ParentQuestUpdatedFn = FindObject<UFunction>("/Game/Athena/Items/QuestInteractables/TimedChallenge/BoatTrial/Prop_QuestInteractable_TimeTrials_Boat.Prop_QuestInteractable_TimeTrials_Boat_C.ParentQuestUpdated");
						static auto AwardQuestFn = FindObject<UFunction>("/Game/Athena/Items/QuestInteractables/TimedChallenge/BoatTrial/Prop_QuestInteractable_TimeTrials_Boat.Prop_QuestInteractable_TimeTrials_Boat_C.AwardQuest");

						OtherActor->ProcessEvent(PlaySuccessFXFn, &PlayerController);
						OtherActor->ProcessEvent(ParentQuestUpdatedFn, nullptr);
						OtherActor->ProcessEvent(AwardQuestFn, &Pawn);
					}
				}
			}
		}
		else if (Pawn->IsInVehicle() && OtherActor->IsA(FireClass))
		{
			static UProperty* QuestItemProp = FindObject<UProperty>("/Game/Athena/Items/QuestInteractables/Generic/Actor_QuestObject_Touch_Parent.Actor_QuestObject_Touch_Parent_C.QuestItem");
			static UProperty* QuestBackendObjectiveName = FindObject<UProperty>("/Game/Athena/Items/QuestInteractables/Generic/Actor_QuestObject_Touch_Parent.Actor_QuestObject_Touch_Parent_C.ObjBackendName");

			auto Backendname = *(FName*)(__int64(OtherActor) + QuestBackendObjectiveName->Offset);
			auto Quest = *(UFortQuestItemDefinition**)(__int64(OtherActor) + QuestItemProp->Offset);
			auto QuestManager = (PlayerController)->GetQuestManager(ESubGame::Athena);

			if (!QuestManager->GetQuestWithDefinition(Quest)->HasCompletedObjectiveWithName(Backendname))
			{
				static auto ObjectiveSuccessfullyCompletedFn = FindObject<UFunction>("/Game/Athena/Items/QuestInteractables/TimedChallenge/BoatTrial/Prop_QuestInteractable_TimeTrials_Boat.Prop_QuestInteractable_TimeTrials_Boat_C.ObjectiveSuccessfullyCompleted");

				PlayerController->ProgressQuest(PlayerController, Quest, Backendname);
				OtherActor->ProcessEvent(ObjectiveSuccessfullyCompletedFn, &PlayerController);
			}
		}

		*/
	}

	// return OnCapsuleBeginOverlapOriginal(Context, Stack, Ret); // we love explicit
}