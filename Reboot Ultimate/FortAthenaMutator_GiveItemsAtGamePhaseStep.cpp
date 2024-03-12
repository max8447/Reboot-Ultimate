#include "FortAthenaMutator_GiveItemsAtGamePhaseStep.h"

#include "FortPlayerControllerAthena.h"

void AFortAthenaMutator_GiveItemsAtGamePhaseStep::OnGamePhaseStepChangedHook(UObject* Context, FFrame& Stack, void* Ret)
{
	LOG_INFO(LogDev, __FUNCTION__);

	auto GiveItems = Cast<AFortAthenaMutator_GiveItemsAtGamePhaseStep>(Context);

	auto GameState = Cast<AFortGameStateAthena>(GetWorld()->GetGameState());

	if (!GameState)
		return OnGamePhaseStepChangedOriginal(Context, Stack, Ret);

	static bool bGaveItems = false;

	if ((int)GameState->GetGamePhaseStep() == (int)GiveItems->GetPhaseToGiveItems() && bGaveItems == false)
	{
		auto ItemsToGive = GiveItems->GetItemsToGive();

		auto ClientConnections = GetWorld()->GetNetDriver()->GetClientConnections();

		for (int i = 0; i < ClientConnections.Num(); i++)
		{
			auto CurrentController = Cast<AFortPlayerControllerAthena>(ClientConnections.At(i)->GetPlayerController());

			if (CurrentController)
			{
				auto WorldInventory = CurrentController->GetWorldInventory();

				auto ItemToGive = ItemsToGive.At(0).GetItemToDrop();
				auto NumberToGive = ItemsToGive.At(0).GetNumberToGive().GetValue();

				bool bShouldUpdate = false;
				WorldInventory->AddItem(ItemToGive, &bShouldUpdate, NumberToGive);
			}
		}

		bGaveItems = true;
	}

	// return OnGamePhaseStepChangedOriginal(Context, Stack, Ret);
}