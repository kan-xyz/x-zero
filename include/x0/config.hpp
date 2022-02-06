#pragma once

#define X0_VERSION_MAJOR 1
#define X0_VERSION_MINOR 0
#define X0_VERSION_PATCH 0
#define X0_VERSION_STR "1.0.0";
#define X0_VERSION_INT ((X0_VERSION_MAJOR * 10000) + (X0_VERSION_MINOR * 100) + X0_VERSION_PATCH)

#if defined(_WIN32) || defined(WIN32) || defined(__WIN32__)
#	if defined(_WIN64)
#		define X0_PLATFORM_WINDOWS 1
#	else
#		error "only windows 64-bit is supported"
#	endif // defined(_WIN64)
#elif defined(__APPLE__)
#	if defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR)
#		define X0_PLATFORM_IOS 1
#	elif defined(TARGET_OS_MAC)
#		define X0_PLATFORM_MACOS 1
#	else
#		error "unknown apple platform detected"
#	endif // defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR)
#elif defined(__unix__)
#	if defined(__linux__)
#		define X0_PLATFORM_LINUX 1
#	elif defined(__ANDROID__)
#		define X0_PLATFORM_ANDROID 1
#	else
#		error "unknown unix system detected"
#	endif // defined(__linux__)
#else
#	error "unknown platform detected"
#endif // defined(_WIN32) || defined(WIN32) || defined(__WIN32__)

#if defined(_MSC_VER) && X0_PLATFORM_WINDOWS
#	define X0_COMPILER_MSVC 1
#elif defined(__GNUC__)
#	define X0_COMPILER_GCC 1
#	define X0_GCC_VERSION __GNUC__
#elif defined(__clang__)
#	define X0_COMPILER_CLANG 1
#endif // defined(_MSC_VER)

#if X0_COMPILER_MSVC
#	define X0_DLL_EXPORT __declspec(dllexport)
#	define X0_DLL_IMPORT __declspec(dllimport)
#elif X0_GCC_VERSION >= 4
#	define X0_DLL_EXPORT __attribute__((__visibility__("default")))
#	define X0_DLL_IMPORT __attribute__((__visibility__("default")))
#else
#	define X0_DLL_EXPORT
#	define X0_DLL_IMPORT
#endif // X0_COMPILER_MSVC

#if X0_COMPILER_MSVC
#	define X0_FORCE_INLINE __forceinline
#elif X0_COMPILER_GCC
#	define __attribute__((always_inline)) inline
#else
#	define X0_FORCE_INLINE inline
#endif // X0_COMPILER_MSVC

#if defined(_DEBUG) || !defined(NDEBUG)
#	define X0_DEBUG 1
#else
#	define X0_DEBUG 0
#endif // defined(_DEBUG)

#if X0_COMPILER_MSVC
#	define X0_DEPRECATED __declspec(deprecated)
#elif X0_COMPILER_GCC
#	define X0_DEPRECATED __attribute__((deprecated))
#else
#	define X0_DEPRECATED
#endif // X0_COMPILER_MSVC
