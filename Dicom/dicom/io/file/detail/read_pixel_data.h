#pragma once

namespace dicom::io::file::detail { class InputContext; }
namespace dicom::io::file { class PixelDataRange; }
#include "dicom/data/buffer.h"
#include "dicom/io/HandleBulkDataCallback.h"

namespace dicom::io::file::detail {

    [[nodiscard]] dicom::data::buffer<int8_t> read_pixel_data_native(
        InputContext* ctx,
        bool reverse_endian,
        const PixelDataRange& range
    );

    [[nodiscard]] dicom::data::buffer<int8_t> read_pixel_data_encapsulated(
        InputContext* ctx,
        bool reverse_endian,
        const PixelDataRange& range
    );

    [[nodiscard]] bool stream_pixel_data_native(
        InputContext* ctx,
        bool reverse_endian,
        const PixelDataRange& range,
        HandleBulkDataCallback callback
    );

    [[nodiscard]] bool stream_pixel_data_encapsulated(
        InputContext* ctx,
        bool reverse_endian,
        const PixelDataRange& range,
        HandleBulkDataCallback callback
    );

}