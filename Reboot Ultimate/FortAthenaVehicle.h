#pragma once

#include "Actor.h"

#include "reboot.h"
#include "FortWeaponItemDefinition.h"
#include "FortPlayerPawn.h"

struct FWeaponSeatDefinition
{
public:
	UFortWeaponItemDefinition* GetVehicleWeapon()
	{
		static auto VehicleWeaponOffset = FindOffsetStruct("/Script/FortniteGame.WeaponSeatDefinition", "VehicleWeapon");
		return *(UFortWeaponItemDefinition**)(__int64(this) + VehicleWeaponOffset);
	}
};

class UFortVehicleSeatWeaponComponent : public UActorComponent
{
public:
	TArray<FWeaponSeatDefinition> GetWeaponSeatDefinitions()
	{
		static auto WeaponSeatDefinitionsOffset = FindOffsetStruct("/Script/FortniteGame.FortVehicleSeatWeaponComponent", "WeaponSeatDefinitions");
		return *(TArray<FWeaponSeatDefinition>*)(__int64(this) + WeaponSeatDefinitionsOffset);
	}

	int32& GetActiveSeatIdx()
	{
		static auto ActiveSeatIdxOffset = FindOffsetStruct("/Script/FortniteGame.FortVehicleSeatWeaponComponent", "ActiveSeatIdx");
		return *(int32*)(__int64(this) + ActiveSeatIdxOffset);
	}

	bool& IsWeaponEquipped()
	{
		static auto bWeaponEquippedOffset = FindOffsetStruct("/Script/FortniteGame.FortVehicleSeatWeaponComponent", "bWeaponEquipped");
		return *(bool*)(__int64(this) + bWeaponEquippedOffset);
	}

	AFortWeapon*& GetCachedWeapon()
	{
		static auto CachedWeaponOffset = FindOffsetStruct("/Script/FortniteGame.FortVehicleSeatWeaponComponent", "CachedWeapon");
		return *(AFortWeapon**)(__int64(this) + CachedWeaponOffset);
	}

	UFortWeaponItemDefinition*& GetCachedWeaponDef()
	{
		static auto CachedWeaponDefOffset = FindOffsetStruct("/Script/FortniteGame.FortVehicleSeatWeaponComponent", "CachedWeaponDef");
		return *(UFortWeaponItemDefinition**)(__int64(this) + CachedWeaponDefOffset);
	}

	void EquipVehicleWeapon(AFortPawn* FortPawn, FWeaponSeatDefinition* WeaponSeatDefinition, int32 ItemLevel)
	{
		static auto EquipVehicleWeaponFn = FindObject<UFunction>("/Script/FortniteGame.FortVehicleSeatWeaponComponent.EquipVehicleWeapon");

		struct
		{
			AFortPawn* FortPawn;
			int32 ItemLevel;
			FWeaponSeatDefinition       WeaponSeatDefinition;
		}params{ FortPawn , ItemLevel };

		this->ProcessEvent(EquipVehicleWeaponFn, &params);

		if (WeaponSeatDefinition != nullptr)
			*WeaponSeatDefinition = std::move(params.WeaponSeatDefinition);
	}
};

class AFortAthenaVehicle : public AActor// : public AFortPhysicsPawn // Super changes based on version
{
public:
	UFortVehicleSeatWeaponComponent* GetSeatWeaponComponent(int32 SeatIndex)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaVehicle.GetSeatWeaponComponent");

		struct
		{
			int32                              SeatIndex;
			UFortVehicleSeatWeaponComponent* ReturnValue;
		}params{ SeatIndex };

		this->ProcessEvent(fn, &params);

		return params.ReturnValue;
	}

	class AFortPlayerPawn* GetPawnAtSeat(int SeatIdx)
	{
		static auto GetPawnAtSeatFn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaVehicle.GetPawnAtSeat");
		struct { int SeatIdx; class AFortPlayerPawn* ReturnValue; } GetPawnAtSeat_Params{SeatIdx};
		this->ProcessEvent(GetPawnAtSeatFn, &GetPawnAtSeat_Params);

		return GetPawnAtSeat_Params.ReturnValue;
	}

	int FindSeatIndex(class AFortPlayerPawn* PlayerPawn)
	{
		static auto FindSeatIndexFn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaVehicle.FindSeatIndex");
		struct { AFortPlayerPawn* PlayerPawn; int ReturnValue; } AFortAthenaVehicle_FindSeatIndex_Params{ PlayerPawn };
		this->ProcessEvent(FindSeatIndexFn, &AFortAthenaVehicle_FindSeatIndex_Params);

		return AFortAthenaVehicle_FindSeatIndex_Params.ReturnValue;
	}

	UFortWeaponItemDefinition* GetVehicleWeaponForSeat(int SeatIdx);

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>("/Script/FortniteGame.FortAthenaVehicle");
		return Class;
	}
};