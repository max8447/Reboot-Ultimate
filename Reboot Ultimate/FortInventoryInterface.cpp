#include "FortInventoryInterface.h"

#include "reboot.h"
#include "FortPlayerControllerAthena.h"
#include "KismetStringLibrary.h"

char UFortInventoryInterface::RemoveInventoryItemHook(__int64 a1, FGuid a2, int Count, char bForceRemoveFromQuickBars, char bForceRemoval)
{
	// kms bruh

	static auto FortPlayerControllerSuperSize = (*(UClass**)(__int64(FindObject<UClass>("/Script/FortniteGame.FortPlayerController")) + Offsets::SuperStruct))->GetPropertiesSize();
	int SuperAdditionalOffset = Engine_Version >= 427 ? 16 : 8;
	auto ControllerObject = (UObject*)(__int64(a1) - (FortPlayerControllerSuperSize + SuperAdditionalOffset));

	// LOG_INFO(LogDev, "bForceRemoval: {}", (bool)bForceRemoval);
	// LOG_INFO(LogDev, "FortPlayerControllerSuperSize: {}", FortPlayerControllerSuperSize);
	// LOG_INFO(LogDev, "ControllerObject: {}", ControllerObject->GetFullName());

	LOG_INFO(LogDev, __FUNCTION__);

	if (!ControllerObject)
		return false;

	auto PlayerController = Cast<AFortPlayerControllerAthena>(ControllerObject);

	if (!PlayerController)
		return false;

	auto WorldInventory = PlayerController->GetWorldInventory();

	if (!WorldInventory)
		return false;

	bool bIsHooksAmmoData = false;

	if (auto ItemInstance = Cast<UFortWorldItemDefinition>(WorldInventory->FindItemInstance(a2)))
	{

		static auto AmmoDataOffset = FindOffsetStruct("/Script/FortniteGame.FortWeaponItemDefinition", "AmmoData");
		auto AmmoData = ItemInstance->Get<TSoftObjectPtr<UFortWorldItemDefinition>>(AmmoDataOffset);

		bIsHooksAmmoData = AmmoData.SoftObjectPtr.ObjectID.AssetPathName.ToString().contains("AthenaAmmoDataHooks");
	}

	bool bShouldUpdate = false;

	if (Globals::bInfiniteAmmo)
	{
		if (bIsHooksAmmoData)
		{
			LOG_INFO(LogDev, "bIsHooksAmmoData!");

			static auto HooksAmmoDefinition = FindObject<UFortWorldItemDefinition>("/Game/Athena/Items/Ammo/AthenaAmmoDataHooks.AthenaAmmoDataHooks");

			WorldInventory->AddItem(HooksAmmoDefinition, &bShouldUpdate, 1);

			if (bShouldUpdate)
				WorldInventory->Update();
		}
		else
		{
			LOG_INFO(LogDev, "NOT bIsHooksAmmoData!");
		}
	}
	else
	{
		WorldInventory->RemoveItem(a2, &bShouldUpdate, Count, bForceRemoval);

		if (bShouldUpdate)
			WorldInventory->Update();
	}

	if (Engine_Version < 424) // doesnt work on c2+ idk why
	{
		auto Pawn = PlayerController->GetMyFortPawn();

		if (Pawn)
		{
			auto CurrentWeapon = Pawn->GetCurrentWeapon();

			if (CurrentWeapon)
				WorldInventory->CorrectLoadedAmmo(CurrentWeapon->GetItemEntryGuid(), CurrentWeapon->GetAmmoCount());
		}
	}

	return true;
}