#pragma once

#include "Pawn.h"
#include "FortWeapon.h"
#include "FortDecoItemDefinition.h"
#include "AttributeSet.h"

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

class AFortPawn : public APawn
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