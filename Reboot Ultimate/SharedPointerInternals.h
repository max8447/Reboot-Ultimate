#pragma once

#ifndef PLATFORM_CPU_ARM_FAMILY
#if (defined(__arm__) || defined(_M_ARM) || defined(__aarch64__) || defined(_M_ARM64))
#define PLATFORM_CPU_ARM_FAMILY	1
#else
#define PLATFORM_CPU_ARM_FAMILY	0
#endif
#endif
#define PLATFORM_WEAKLY_CONSISTENT_MEMORY PLATFORM_CPU_ARM_FAMILY
#define	FORCE_THREADSAFE_SHAREDPTRS PLATFORM_WEAKLY_CONSISTENT_MEMORY

enum class ESPMode
{
    /** Forced to be not thread-safe. */
    NotThreadSafe = 0,

    /**
        *	Fast, doesn't ever use atomic interlocks.
        *	Some code requires that all shared pointers are thread-safe.
        *	It's better to change it here, instead of replacing ESPMode::Fast to ESPMode::ThreadSafe throughout the code.
        */
        Fast = FORCE_THREADSAFE_SHAREDPTRS ? 1 : 0,

        /** Conditionally thread-safe, never spin locks, but slower */
        ThreadSafe = 1
};