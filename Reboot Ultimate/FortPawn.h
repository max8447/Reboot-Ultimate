#pragma once

#include "Pawn.h"
#include "FortWeapon.h"
#include "FortDecoItemDefinition.h"
#include "AttributeSet.h"
#include "ActorComponent.h"
#include "GameplayTagContainer.h"

class UFortHealthSet : public UAttributeSet //public UFortAttributeSet
{
public:
	FFortGameplayAttributeData GetHealth()
	{
		static auto HealthOffset = GetOffset("Health");
		return Get<FFortGameplayAttributeData>(HealthOffset);
	}

	void OnRep_Health()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortHealthSet.OnRep_Health");
		this->ProcessEvent(fn, nullptr);
	}
};

class UCharacterMovementComponent : public UActorComponent // UPawnMovementComponent
{
public:
	float& GetMaxFlySpeed()
	{
		static auto MaxFlySpeedOffset = FindOffsetStruct("/Script/Engine.CharacterMovementComponent", "MaxFlySpeed");
		return *(float*)(__int64(this) + MaxFlySpeedOffset);
	}

	void SetCanWalkOffLedges(bool NewValue)
	{
		static auto bCanWalkOffLedgesOffset = GetOffset("bCanWalkOffLedges");
		static auto bCanWalkOffLedgesFieldMask = GetFieldMask(GetProperty("bCanWalkOffLedges"));
		SetBitfieldValue(bCanWalkOffLedgesOffset, bCanWalkOffLedgesFieldMask, NewValue);
	}

	void SetCanWalkOffLedgesWhenCrouching(bool NewValue)
	{
		static auto bCanWalkOffLedgesWhenCrouchingOffset = GetOffset("bCanWalkOffLedgesWhenCrouching");
		static auto bCanWalkOffLedgesWhenCrouchingFieldMask = GetFieldMask(GetProperty("bCanWalkOffLedgesWhenCrouching"));
		SetBitfieldValue(bCanWalkOffLedgesWhenCrouchingOffset, bCanWalkOffLedgesWhenCrouchingFieldMask, NewValue);
	}
};

class ACharacter : public APawn
{
public:
	UCharacterMovementComponent* GetCharacterMovement()
	{
		static auto CharacterMovementOffset = FindOffsetStruct("/Script/Engine.Character", "CharacterMovement");
		return *(UCharacterMovementComponent**)(__int64(this) + CharacterMovementOffset);
	}

	UActorComponent* GetCapsuleComponent()
	{
		static auto CapsuleComponentOffset = GetOffset("CapsuleComponent");
		return Get<UActorComponent*>(CapsuleComponentOffset);
	}

	void Jump()
	{
		static auto fn = FindObject<UFunction>("/Script/Engine.Character.Jump");
		this->ProcessEvent(fn);
	}

	void Crouch(bool bClientSimulation)
	{
		static auto fn = FindObject<UFunction>("/Script/Engine.Character.Crouch");
		this->ProcessEvent(fn, &bClientSimulation);
	}

	void UnCrouch(bool bClientSimulation)
	{
		static auto fn = FindObject<UFunction>("/Script/Engine.Character.UnCrouch");
		this->ProcessEvent(fn, &bClientSimulation);
	}
};

struct FCosmeticVariantInfo
{
public:
	FGameplayTag                          VariantChannelTag;                                 // 0x0(0x8)(Edit, BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	FGameplayTag                          ActiveVariantTag;                                  // 0x8(0x8)(Edit, BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

struct FMcpVariantChannelInfo : public FCosmeticVariantInfo
{
public:
	FGameplayTagContainer                 OwnedVariantTags;                                  // 0x10(0x20)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	UFortItemDefinition*					 ItemVariantIsUsedFor;                              // 0x30(0x8)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	FString                                CustomData;                                        // 0x38(0x10)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

class AFortPlayerMannequin : public AActor // ASkeletalMeshActor
{
public:
	TArray<FMcpVariantChannelInfo> GetOverrideVariants()
	{
		static auto OverrideVariantsOffset = GetOffset("OverrideVariants");
		return Get<TArray<FMcpVariantChannelInfo>>(OverrideVariantsOffset);
	}
};

class AFortPawn : public ACharacter
{
public:
	static inline void (*NetMulticast_Athena_BatchedDamageCuesOriginal)(UObject* Context, FFrame* Stack, void* Ret);
	static inline void (*MovingEmoteStoppedOriginal)(UObject* Context, FFrame* Stack, void* Ret);

	enum class EMovementMode : uint8
	{
		MOVE_None = 0,
		MOVE_Walking = 1,
		MOVE_NavWalking = 2,
		MOVE_Falling = 3,
		MOVE_Swimming = 4,
		MOVE_Flying = 5,
		MOVE_Custom = 6,
		MOVE_MAX = 7,
	};

	AFortWeapon* EquipWeaponDefinition(UFortWeaponItemDefinition* WeaponData, const FGuid& ItemEntryGuid);
	bool PickUpActor(AActor* PickupTarget, UFortDecoItemDefinition* PlacementDecoItemDefinition);

	void PawnStartFire(uint8 FireModeNum)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPawn.PawnStartFire");
		this->ProcessEvent(fn, &FireModeNum);
	}

	void PawnStopFire(uint8 FireModeNum)
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPawn.PawnStopFire");
		this->ProcessEvent(fn, &FireModeNum);
	}

	bool IsDead()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortPawn.IsDead");

		bool                               ReturnValue;

		this->ProcessEvent(fn, &ReturnValue);

		return ReturnValue;
	}

	UFortHealthSet* GetHealthSet()
	{
		static auto HealthSetOffset = GetOffset("HealthSet");
		return Get<UFortHealthSet*>(HealthSetOffset);
	}

	AFortWeapon*& GetCurrentWeapon()
	{
		static auto CurrentWeaponOffset = GetOffset("CurrentWeapon");
		return Get<AFortWeapon*>(CurrentWeaponOffset);
	}

	bool IsDBNO()
	{
		static auto bIsDBNOFieldMask = GetFieldMask(GetProperty("bIsDBNO"));
		static auto bIsDBNOOffset = GetOffset("bIsDBNO");

		return ReadBitfieldValue(bIsDBNOOffset, bIsDBNOFieldMask);
	}

	void SetDBNO(bool IsDBNO)
	{
		static auto bIsDBNOFieldMask = GetFieldMask(GetProperty("bIsDBNO"));
		static auto bIsDBNOOffset = GetOffset("bIsDBNO");

		this->SetBitfieldValue(bIsDBNOOffset, bIsDBNOFieldMask, IsDBNO);
	}

	void SetHasPlayedDying(bool NewValue)
	{
		static auto bPlayedDyingFieldMask = GetFieldMask(GetProperty("bPlayedDying"));
		static auto bPlayedDyingOffset = GetOffset("bPlayedDying");

		this->SetBitfieldValue(bPlayedDyingOffset, bPlayedDyingFieldMask, NewValue);
	}
	
	void OnRep_IsDBNO();
	float GetShield();
	float GetHealth();
	void SetHealth(float NewHealth);
	void SetMaxHealth(float NewHealthVal);
	void SetShield(float NewShield);
	void SetMaxShield(float NewShieldVal);
	static void NetMulticast_Athena_BatchedDamageCuesHook(UObject* Context, FFrame* Stack, void* Ret);
	static void MovingEmoteStoppedHook(UObject* Context, FFrame* Stack, void* Ret);
	void LaunchURL(const class FString& URL);
	void CopyToClipboard(const class FString& ClipboardText);
	void SetMovementMode(enum class EMovementMode NewMovementMode, uint8 NewCustomMode);

	static UClass* StaticClass();
};