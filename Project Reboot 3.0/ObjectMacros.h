#pragma once

#include "inc.h"

enum EObjectFlags
{
    RF_NoFlags = 0x00000000,
    RF_Public = 0x00000001,
    RF_Standalone = 0x00000002,
    RF_MarkAsNative = 0x00000004,
    RF_Transactional = 0x00000008,
    RF_ClassDefaultObject = 0x00000010,
    RF_ArchetypeObject = 0x00000020,
    RF_Transient = 0x00000040,
    RF_MarkAsRootSet = 0x00000080,
    RF_TagGarbageTemp = 0x00000100,
    RF_NeedInitialization = 0x00000200,
    RF_NeedLoad = 0x00000400,
    RF_KeepForCooker = 0x00000800,
    RF_NeedPostLoad = 0x00001000,
    RF_NeedPostLoadSubobjects = 0x00002000,
    RF_NewerVersionExists = 0x00004000,
    RF_BeginDestroyed = 0x00008000,
    RF_FinishDestroyed = 0x00010000,
    RF_BeingRegenerated = 0x00020000,
    RF_DefaultSubObject = 0x00040000,
    RF_WasLoaded = 0x00080000,
    RF_TextExportTransient = 0x00100000,
    RF_LoadCompleted = 0x00200000,
    RF_InheritableComponentTemplate = 0x00400000,
    RF_DuplicateTransient = 0x00800000,
    RF_StrongRefOnFrame = 0x01000000,
    RF_NonPIEDuplicateTransient = 0x02000000,
    RF_WillBeLoaded = 0x08000000,
    RF_HasExternalPackage = 0x10000000,
    RF_AllocatedInSharedPage = 0x80000000,
};

enum class EInternalObjectFlags : int
{
    None = 0,

    LoaderImport = 1 << 20, ///< Object is ready to be imported by another package during loading
    Garbage = 1 << 21, ///< Garbage from logical point of view and should not be referenced. This flag is mirrored in EObjectFlags as RF_Garbage for performance
    PersistentGarbage = 1 << 22, ///< Same as above but referenced through a persistent reference so it can't be GC'd
    ReachableInCluster = 1 << 23, ///< External reference to object in cluster exists
    ClusterRoot = 1 << 24, ///< Root of a cluster
    Native = 1 << 25, ///< Native (UClass only). 
    Async = 1 << 26, ///< Object exists only on a different thread than the game thread.
    AsyncLoading = 1 << 27, ///< Object is being asynchronously loaded.
    Unreachable = 1 << 28, ///< Object is not reachable on the object graph.
    // PendingKill UE_DEPRECATED(5.0, "PendingKill flag should no longer be used. Use Garbage flag instead.") = 1 << 29, ///< Objects that are pending destruction (invalid for gameplay but valid objects). This flag is mirrored in EObjectFlags as RF_PendingKill for performance
    PendingKill = 1 << 29,
    RootSet = 1 << 30, ///< Object will not be garbage collected, even if unreferenced.
    PendingConstruction = 1 << 31 ///< Object didn't have its class constructor called yet (only the UObjectBase one to initialize its most basic members)

    /* GarbageCollectionKeepFlags = Native | Async | AsyncLoading | LoaderImport,
    PRAGMA_DISABLE_DEPRECATION_WARNINGS
    MirroredFlags = Garbage | PendingKill, /// Flags mirrored in EObjectFlags

    //~ Make sure this is up to date!
    AllFlags = LoaderImport | Garbage | PersistentGarbage | ReachableInCluster | ClusterRoot | Native | Async | AsyncLoading | Unreachable | PendingKill | RootSet | PendingConstruction
    PRAGMA_ENABLE_DEPRECATION_WARNINGS */
};

ENUM_CLASS_FLAGS(EInternalObjectFlags)

#define BODY_MACRO_COMBINE_INNER(A,B,C,D) A##B##C##D
#define BODY_MACRO_COMBINE(A,B,C,D) BODY_MACRO_COMBINE_INNER(A,B,C,D)