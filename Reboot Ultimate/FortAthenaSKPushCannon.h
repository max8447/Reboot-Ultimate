#pragma once

#include "Actor.h"

#include "FortAthenaVehicle.h"
#include "reboot.h"
#include "gui.h"

class AFortAthenaSKPushCannon : public AFortAthenaVehicle // : public AFortAthenaSKPushVehicle
{
public:
	bool IsPushCannonBP()
	{
		static auto PushCannonBP = FindObject<UClass>("/Game/Athena/DrivableVehicles/PushCannon.PushCannon_C"); // We should loadobject it.
		return this->IsA(PushCannonBP);
	}

	void MultiCastPushCannonLaunchedPlayer()
	{
		static auto MultiCastPushCannonLaunchedPlayerFn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaSKPushCannon.MultiCastPushCannonLaunchedPlayer");
		this->ProcessEvent(MultiCastPushCannonLaunchedPlayerFn);
	}

	void OnLaunchPawn(AFortPlayerPawn* Pawn, FVector LaunchDir)
	{
		static auto OnLaunchPawnFn = IsPushCannonBP() ? FindObject<UFunction>("/Game/Athena/DrivableVehicles/PushCannon.PushCannon_C.OnLaunchPawn") : FindObject<UFunction>("/Script/FortniteGame.FortAthenaSKPushCannon.OnLaunchPawn");
		struct
		{
			AFortPlayerPawn* Pawn;                                                     // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			struct FVector                                     LaunchDir;                                                // (ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
		} AFortAthenaSKPushCannon_OnLaunchPawn_Params{ Pawn, LaunchDir };

		this->ProcessEvent(OnLaunchPawnFn, &AFortAthenaSKPushCannon_OnLaunchPawn_Params);
	}

	void OnPreLaunchPawn(AFortPlayerPawn* Pawn, FVector LaunchDir)
	{
		static auto OnPreLaunchPawnFn = IsPushCannonBP() ? FindObject<UFunction>("/Game/Athena/DrivableVehicles/PushCannon.PushCannon_C.OnPreLaunchPawn") : FindObject<UFunction>("/Script/FortniteGame.FortAthenaSKPushCannon.OnPreLaunchPawn");
		struct
		{
			AFortPlayerPawn* Pawn;                                                     // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			FVector                                     LaunchDir;                                                // (ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
		} AFortAthenaSKPushCannon_OnPreLaunchPawn_Params{ Pawn, LaunchDir };

		this->ProcessEvent(OnPreLaunchPawnFn, &AFortAthenaSKPushCannon_OnPreLaunchPawn_Params);
	}

	void ShootPawnOut(const FVector& LaunchDir)
	{
		auto PawnToShoot = this->GetPawnAtSeat(1);

		LOG_INFO(LogDev, "PawnToShoot: {}", __int64(PawnToShoot));

		if (!PawnToShoot)
			return;

		this->OnPreLaunchPawn(PawnToShoot, LaunchDir);
		PawnToShoot->ServerOnExitVehicle(ETryExitVehicleBehavior::ForceAlways);

		if (bEnableCannonAnimations)
		{
			this->OnLaunchPawn(PawnToShoot, LaunchDir);
		}
		else
		{
			static auto LaunchCharacterFn = FindObject<UFunction>(L"/Script/Engine.Character.LaunchCharacter");

			struct
			{
				FVector											   LaunchVelocity;                                           // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
				bool                                               bXYOverride;                                              // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
				bool                                               bZOverride;                                               // (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			} ACharacter_LaunchCharacter_Params{ FVector(LaunchDir.X * 6000 * *CannonXMultiplier, LaunchDir.Y * 5000 * *CannonYMultiplier, LaunchDir.Z * 7500 * *CannonZMultiplier), false, false };
			Cast<AFortPawn>(PawnToShoot)->ProcessEvent(LaunchCharacterFn, &ACharacter_LaunchCharacter_Params);
		}

		this->MultiCastPushCannonLaunchedPlayer();
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>("/Script/FortniteGame.FortAthenaSKPushCannon");
		return Class;
	}
};