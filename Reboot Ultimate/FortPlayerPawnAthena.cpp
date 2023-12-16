#include "FortPlayerPawnAthena.h"
#include "FortInventory.h"
#include "FortPlayerControllerAthena.h"

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

	// LOG_INFO(LogDev, "OnCapsuleBeginOverlapHook!");

	Stack->StepCompiledIn(&OverlappedComp);
	Stack->StepCompiledIn(&OtherActor);
	Stack->StepCompiledIn(&OtherComp);
	Stack->StepCompiledIn(&OtherBodyIndex);
	Stack->StepCompiledIn(&bFromSweep);
	Stack->StepCompiledIn(SweepResultPtr);

	std::free(SweepResultPtr);

	// LOG_INFO(LogDev, "OtherActor: {}", __int64(OtherActor));
	// LOG_INFO(LogDev, "OtherActorName: {}", OtherActor->IsValidLowLevel() ? OtherActor->GetName() : "BadRead")

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

			auto PlayerController = Cast<AFortPlayerControllerAthena>(Pawn->GetController());

			if (!PlayerController)
			{
				return;
			}

			auto WorldInventory = PlayerController->GetWorldInventory();

			if (!WorldInventory)
			{
				return;
			}

			auto& ItemInstances = WorldInventory->GetItemList().GetItemInstances();

			bool  ItemDefGoingInPrimary = IsPrimaryQuickbar(ItemDefinition);
			int   PrimarySlotsFilled = 0;
			bool  bCanStack = false;
			bool  bFoundStack = false;

			for (int i = 0; i < ItemInstances.Num(); ++i)
			{
				auto ItemInstance = ItemInstances.at(i);

				if (!ItemInstance)
					continue;

				auto CurrentItemDefinition = ItemInstance->GetItemEntry()->GetItemDefinition();

				if (!CurrentItemDefinition)
					continue;

				if (ItemDefGoingInPrimary && IsPrimaryQuickbar(CurrentItemDefinition))
					PrimarySlotsFilled++;

				bool bIsInventoryFull = (PrimarySlotsFilled /* - 6 */) >= 5;

				if (CurrentItemDefinition == ItemDefinition)
				{
					bFoundStack = true;

					if (ItemInstance->GetItemEntry()->GetCount() < ItemDefinition->GetMaxStackSize())
					{
						bCanStack = true;
						break;
					}
				}

				if (bIsInventoryFull)
				{
					return;
				}
			}

			// std::cout << "bCanStack: " << bCanStack << '\n';
			// std::cout << "bFoundStack: " << bFoundStack << '\n';

			if (!bCanStack ? (!bFoundStack ? true : ItemDefinition->DoesAllowMultipleStacks()) : true)
				ServerHandlePickupHook(Pawn, Pickup, 0.4f, FVector(), true);
		}
	}

	// return OnCapsuleBeginOverlapOriginal(Context, Stack, Ret);
}

void OnCapsuleBeginOverlap::OnCapsuleBeginOverlapHook(AFortPlayerPawnAthena* Pawn, UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, FHitResult SweepResult)
{
	if (Pawn->GetController()->IsA(FindObject<UClass>("/Script/FortniteGame.FortAthenaAIBotController")))
		return OnCapsuleBeginOverlapOG(Pawn, OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	static UClass* CoinClass = FindObject<UClass>("/Game/Athena/Items/QuestInteractables/ItemCollection/BP_ItemCollection_Touch.BP_ItemCollection_Touch_C");
	static UClass* BoatTimedClass = FindObject<UClass>("/Game/Athena/Items/QuestInteractables/TimedChallenge/BoatTrial/Prop_QuestInteractable_TimeTrials_Boat.Prop_QuestInteractable_TimeTrials_Boat_C");
	static UClass* FireClass = FindObject<UClass>("/Game/Athena/Items/QuestInteractables/FlamingHoops/Boat/Actor_QuestObject_Touch_FlamingHoopsBoat_Parent.Actor_QuestObject_Touch_FlamingHoopsBoat_Parent_C");

	// LOG_INFO(LogDev, "OnCapsuleBeginOverlapHook!");

	if (OtherActor->IsA(CoinClass) && OtherComp->GetName() == "CollectOverlap")
	{
		LOG_INFO(LogGame, "XP Coin!");
		AFortPlayerControllerAthena* PC = (AFortPlayerControllerAthena*)Pawn->GetController();

		static UProperty* BackendNameProp = FindObject<UProperty>("/Game/Athena/Items/QuestInteractables/ItemCollection/BP_ItemCollection_Touch.BP_ItemCollection_Touch_C.QuestBackendName");
		static UProperty* QuestItemProp = FindObject<UProperty>("/Game/Athena/Items/QuestInteractables/ItemCollection/BP_ItemCollection_Touch.BP_ItemCollection_Touch_C.CollectItemQuest");
		static auto Func = FindObject<UFunction>("/Game/Athena/Items/QuestInteractables/ItemCollection/BP_ItemCollection_Touch.BP_ItemCollection_Touch_C.ParentQuestUpdated");

		FName BackendName = *(FName*)(__int64(OtherActor) + BackendNameProp->Offset);

		UFortQuestItemDefinition* QuestDef = *(UFortQuestItemDefinition**)(__int64(OtherActor) + QuestItemProp->Offset);
		if (!QuestDef)
			return;
		PC->ProgressQuest(PC, QuestDef, BackendName);
		OtherActor->ProcessEvent(Func, nullptr);
	}
	else if (Pawn->IsInVehicle() && OtherActor->IsA(BoatTimedClass))
	{
		std::string OverlapName = OtherComp->GetName();
		if (OverlapName.contains("CP"))
		{
			std::string Number = SplitString(true, "CP", OverlapName);
			std::string Ok = SplitString(false, (OverlapName.contains("Collision") ? "Collision" : "Coll"), Number);
			int Idx = std::stoi(Ok) - 1;

			//LOG_INFO(LogGame, "Index is " + to_string(Idx));

			static auto Func = FindObject<UFunction>("/Game/Athena/Items/QuestInteractables/TimedChallenge/BoatTrial/Prop_QuestInteractable_TimeTrials_Boat.Prop_QuestInteractable_TimeTrials_Boat_C.GateHit");

			OtherActor->ProcessEvent(Func, &Idx);

			if (Idx == 7)
			{
				static UProperty* QuestItemProp = FindObject<UProperty>("/Game/Athena/Items/QuestInteractables/TimedChallenge/BoatTrial/Prop_QuestInteractable_TimeTrials_Boat.Prop_QuestInteractable_TimeTrials_Boat_C.QuestItem");
				static UProperty* QuestBackendObjectiveName = FindObject<UProperty>("/Game/Athena/Items/QuestInteractables/TimedChallenge/BoatTrial/Prop_QuestInteractable_TimeTrials_Boat.Prop_QuestInteractable_TimeTrials_Boat_C.QuestBackendObjectiveName");

				auto Backendname = *(FName*)(__int64(OtherActor) + QuestBackendObjectiveName->Offset);
				auto Quest = *(UFortQuestItemDefinition**)(__int64(OtherActor) + QuestItemProp->Offset);
				auto QuestManager = ((AFortPlayerControllerAthena*)Pawn->GetController())->GetQuestManager(ESubGame::Athena);

				auto PC = Cast<AFortPlayerControllerAthena>(Pawn->GetController());

				if (!QuestManager->GetQuestWithDefinition(Quest)->HasCompletedObjectiveWithName(Backendname))
				{
					PC->ProgressQuest((AFortPlayerControllerAthena*)Pawn->GetController(), Quest, Backendname);

					static auto Func2 = FindObject<UFunction>("/Game/Athena/Items/QuestInteractables/TimedChallenge/BoatTrial/Prop_QuestInteractable_TimeTrials_Boat.Prop_QuestInteractable_TimeTrials_Boat_C.PlaySuccessFX");
					static auto Func3 = FindObject<UFunction>("/Game/Athena/Items/QuestInteractables/TimedChallenge/BoatTrial/Prop_QuestInteractable_TimeTrials_Boat.Prop_QuestInteractable_TimeTrials_Boat_C.ParentQuestUpdated");
					static auto Func4 = FindObject<UFunction>("/Game/Athena/Items/QuestInteractables/TimedChallenge/BoatTrial/Prop_QuestInteractable_TimeTrials_Boat.Prop_QuestInteractable_TimeTrials_Boat_C.AwardQuest");

					auto Controller = Pawn->GetController();

					OtherActor->ProcessEvent(Func2, &Controller);
					OtherActor->ProcessEvent(Func3, nullptr);
					OtherActor->ProcessEvent(Func4, &Pawn);
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
		auto QuestManager = ((AFortPlayerControllerAthena*)Pawn->GetController())->GetQuestManager(ESubGame::Athena);

		auto PC = Cast<AFortPlayerControllerAthena>(Pawn->GetController());

		if (!QuestManager->GetQuestWithDefinition(Quest)->HasCompletedObjectiveWithName(Backendname))
		{
			PC->ProgressQuest((AFortPlayerControllerAthena*)Pawn->GetController(), Quest, Backendname);

			static auto Func = FindObject<UFunction>("/Game/Athena/Items/QuestInteractables/FlamingHoops/Actor_QuestObject_Touch_FlamingHoops_Parent.Actor_QuestObject_Touch_FlamingHoops_Parent_C.ObjectiveSuccessfullyCompleted");

			auto Controller = Pawn->GetController();

			OtherActor->ProcessEvent(Func, &Controller);
		}
	}

	// return OnCapsuleBeginOverlapOG(Pawn, OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}