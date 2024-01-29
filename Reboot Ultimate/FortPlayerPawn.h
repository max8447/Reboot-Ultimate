#pragma once

#include "FortPawn.h"
#include "FortPickup.h"
#include "FortAthenaVehicle.h"

struct PadHex100 { char pad[0x100]; };

using FZiplinePawnState = PadHex100;

enum class EFortCustomPartType : uint8_t // todo move
{
	Head = 0,
	Body = 1,
	Hat = 2,
	Backpack = 3,
	Charm = 4,
	Face = 5,
	NumTypes = 6,
	EFortCustomPartType_MAX = 7
};

enum class ETryExitVehicleBehavior : uint8_t
{
	DoNotForce = 0,
	ForceOnBlocking = 1,
	ForceAlways = 2,
	ETryExitVehicleBehavior_MAX = 3
};

class AFortPlayerPawn : public AFortPawn
{
public:
	static inline AActor* (*ServerOnExitVehicleOriginal)(AFortPlayerPawn* Pawn, ETryExitVehicleBehavior ExitForceBehavior); // actually returns AFortAthenaVehicle
	static inline void (*StartGhostModeExitOriginal)(UObject* Context, FFrame* Stack, void* Ret);
	static inline void (*ServerHandlePickupWithRequestedSwapOriginal)(UObject* Context, FFrame* Stack, void* Ret);

	bool IsInVehicle()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerPawn.IsInVehicle");

		struct
		{
			bool ReturnValue;
		}params;

		this->ProcessEvent(fn, &params);

		return params.ReturnValue;
	}

	uint8 GetVehicleSeatIndex()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerPawn.GetVehicleSeatIndex");

		struct
		{
			uint8                              ReturnValue;
		}params;

		this->ProcessEvent(fn, &params);

		return params.ReturnValue;
	}

	void BeginSkydiving(bool bFromBus)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerPawn.BeginSkydiving");
		this->ProcessEvent(fn, &bFromBus);
	}

	void OnRep_StartedInteractSearch()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPlayerPawn.OnRep_StartedInteractSearch");
		this->ProcessEvent(fn);
	}

	void SetStartedInteractSearch(bool NewValue)
	{
		static auto bStartedInteractSearchOffset = GetOffset("bStartedInteractSearch");
		static auto bStartedInteractSearchFieldMask = GetFieldMask(GetProperty("bStartedInteractSearch"));
		SetBitfieldValue(bStartedInteractSearchOffset, bStartedInteractSearchFieldMask, NewValue);
	}
	
	struct FFortAthenaLoadout* GetCosmeticLoadout();
	void ServerChoosePart(EFortCustomPartType Part, class UObject* ChosenCharacterPart);
	void ForceLaunchPlayerZipline(); // Thanks android
	AActor* ServerOnExitVehicle(ETryExitVehicleBehavior ExitForceBehavior); // actually returns AFortAthenaVehicle

	class AFortAthenaVehicle* GetVehicle();
	UFortWeaponItemDefinition* GetVehicleWeaponDefinition(class AFortAthenaVehicle* Vehicle);
	void UnEquipVehicleWeaponDefinition(UFortWeaponItemDefinition* VehicleWeaponDefinition);
	
	static void ServerReviveFromDBNOHook(AFortPlayerPawn* Pawn, AController* EventInstigator);
	static void ServerHandlePickupWithRequestedSwapHook(UObject* Context, FFrame* Stack, void* Ret); // we could native hook this but idk
	static void StartGhostModeExitHook(UObject* Context, FFrame* Stack, void* Ret); // we could native hook this but eh
	static AActor* ServerOnExitVehicleHook(AFortPlayerPawn* Pawn, ETryExitVehicleBehavior ExitForceBehavior); // actually returns AFortAthenaVehicle
	static void ServerSendZiplineStateHook(AFortPlayerPawn* Pawn, FZiplinePawnState InZiplineState);
	static void ServerHandlePickupHook(AFortPlayerPawn* Pawn, AFortPickup* Pickup, float InFlyTime, FVector InStartDirection, bool bPlayPickupSound);
	static void ServerHandlePickupInfoHook(AFortPlayerPawn* Pawn, AFortPickup* Pickup, __int64 Params);

	static UClass* StaticClass();
};