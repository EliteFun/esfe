#pragma once


// VERSION
#define ESFE_VERSION_NAME  "DEV"
#define ESFE_VERSION_MAJOR 0
#define ESFE_VERSION_MINOR 0
#define ESFE_VERSION_PATH  4

// OS
#if defined(_WIN32)
    #define ESFE_OS_WINDOWS
#elif defined(__APPLE__) && defined(__MACH__)
    #pragma message("WARNING: Some features are not available for apple")
    #define ESFE_OS_APPLE
#elif defined(__unix__)
    #define ESFE_OS_UNIX
#else
    #error Unsuported system
#endif


// COMPILER
#if defined(_MSC_VER)
    #define ESFE_COMPILER_MSVC
#elif defined(__GNUC__)
    #define ESFE_COMPILER_GCC
#else
    #define ESFE_COMPILER_GENERAL
    #pragma message("Using general compiler")
#endif


// OTHER
#ifndef NOMINMAX
#define NOMINMAX
#endif
