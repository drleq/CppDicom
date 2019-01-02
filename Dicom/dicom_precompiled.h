#pragma once

#ifdef __GNUG__
    #define DICOM_EXPORT
#endif
#ifdef _MSC_VER
    #ifdef DICOM_EXPORT_SYMBOLS
        #define DICOM_EXPORT __declspec(dllexport)
    #else
        #define DICOM_EXPORT __declspec(dllimport)
    #endif
#endif

#define DICOM_DLL_VERSION_MAJOR 0
#define DICOM_DLL_VERSION_MINOR 1

// STL types
#include <array>
#include <chrono>
#include <cstring>
#include <functional>
#include <ios>
#include <map>
#include <memory>
#include <optional>
#include <set>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>