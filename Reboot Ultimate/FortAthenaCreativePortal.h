#pragma once

#include "BuildingActor.h"
#include "FortVolume.h"
#include "Stack.h"
#include "Text.h"

struct FCreativeLoadedLinkData
{
	struct FString                                     CreatorName;                                              // 0x0000(0x0010) (ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FString                                     SupportCode;                                              // 0x0010(0x0010) (ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FString                                     Mnemonic;                                                 // 0x0020(0x0010) (ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int                                                Version;                                                  // 0x0030(0x0004) (ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0034(0x0004) MISSED OFFSET
	TArray<struct FLocalizedStringPair>                LinkTitle;                                                // 0x0038(0x0010) (ZeroConstructor, NativeAccessSpecifierPublic)
	struct FText                                       AltTitle;                                                 // 0x0048(0x0018) (NativeAccessSpecifierPublic)
	TArray<struct FLocalizedStringPair>                LinkTagline;                                              // 0x0060(0x0010) (ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<struct FLocalizedStringPair>                IslandIntroduction;                                       // 0x0070(0x0010) (ZeroConstructor, NativeAccessSpecifierPublic)
	struct FString                                     LinkYoutubeId;                                            // 0x0080(0x0010) (ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FString                                     ImageUrl;                                                 // 0x0090(0x0010) (ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FString                                     IslandType;                                               // 0x00A0(0x0010) (ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FString                                     QuestContextTag;                                          // 0x00B0(0x0010) (ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FString                                     AccountId;                                                // 0x00C0(0x0010) (ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

class AFortAthenaCreativePortal : public ABuildingActor // ABuildingGameplayActor
{
public:
	static inline void (*TeleportPlayerToLinkedVolumeOriginal)(UObject* Context, FFrame& Stack, void* Ret);
	static inline void (*TeleportPlayerOriginal)(UObject* Context, FFrame& Stack, void* Ret);

	void OnRep_IslandInfo()
	{
		static auto fn = FindObject<UFunction>("/Script/FortniteGame.FortAthenaCreativePortal.OnRep_IslandInfo");
		this->ProcessEvent(fn);
	}

	FCreativeLoadedLinkData* GetIslandInfo()
	{
		static auto CreativeLoadedLinkDataStruct = FindObject<UStruct>("/Script/FortniteGame.CreativeLoadedLinkData");

		if (!CreativeLoadedLinkDataStruct)
			return nullptr;

		static auto IslandInfoOffset = GetOffset("IslandInfo");
		return GetPtr<FCreativeLoadedLinkData>(IslandInfoOffset);
	}

	void* GetOwningPlayer()
	{
		static auto OwningPlayerOffset = GetOffset("OwningPlayer", false);

		if (OwningPlayerOffset == -1)
			return nullptr;

		return GetPtr<void>(OwningPlayerOffset);
	}

	bool& GetPortalOpen()
	{
		static auto bPortalOpenOffset = GetOffset("bPortalOpen");
		return Get<bool>(bPortalOpenOffset);
	}

	bool& GetUserInitiatedLoad()
	{
		static auto bUserInitiatedLoadOffset = GetOffset("bUserInitiatedLoad");
		return Get<bool>(bUserInitiatedLoadOffset);
	}

	bool& GetInErrorState()
	{
		static auto bInErrorStateOffset = GetOffset("bInErrorState");
		return Get<bool>(bInErrorStateOffset);
	}

	AFortVolume*& GetLinkedVolume()
	{
		static auto LinkedVolumeOffset = GetOffset("LinkedVolume");
		return Get<AFortVolume*>(LinkedVolumeOffset);
	}

	FString& GetCreatorName()
	{
		auto IslandInfo = GetIslandInfo();

		if (!IslandInfo)
		{
			return *(FString*)0;
		}

		static auto CreatorNameOffset = FindOffsetStruct("/Script/FortniteGame.CreativeLoadedLinkData", "CreatorName");
		return *(FString*)(__int64(IslandInfo) + CreatorNameOffset);
	}

	static void TeleportPlayerToLinkedVolumeHook(UObject* Context, FFrame& Stack, void* Ret);
	static void TeleportPlayerHook(UObject* Context, FFrame& Stack, void* Ret);
	// hook TeleportPlayer ?? but do what with it
};