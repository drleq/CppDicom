#pragma once

#ifdef __GNUG__
    #define DICOMNET_EXPORT
#endif
#ifdef _MSC_VER
    #ifdef DICOMNET_EXPORT_SYMBOLS
        #define DICOMNET_EXPORT __declspec(dllexport)
    #else
        #define DICOMNET_EXPORT __declspec(dllimport)
    #endif
    #include <SDKDDKVer.h>
#endif

// Precompiled headers
#include "dicom_precompiled.h"

// ASIO
#include "asio/buffer.hpp"
#include "asio/high_resolution_timer.hpp"
#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"
#include "asio/read.hpp"
#include "asio/write.hpp"