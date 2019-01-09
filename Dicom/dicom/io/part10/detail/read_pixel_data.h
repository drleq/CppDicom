#pragma once

namespace dicom::io::part10::detail { class InputContext; }
namespace dicom::io::part10 { class PixelDataRange; }
#include "dicom/data/buffer.h"
#include "dicom/io/HandleBulkDataCallback.h"

namespace dicom::io::part10::detail {

    DICOM_EXPORT [[nodiscard]] dicom::data::buffer<int8_t> read_pixel_data_native(
        InputContext* ctx,
        bool reverse_endian,
        const PixelDataRange& range
    );

    DICOM_EXPORT [[nodiscard]] dicom::data::buffer<int8_t> read_pixel_data_encapsulated(
        InputContext* ctx,
        bool reverse_endian,
        const PixelDataRange& range
    );

    DICOM_EXPORT [[nodiscard]] bool stream_pixel_data_native(
        InputContext* ctx,
        bool reverse_endian,
        const PixelDataRange& range,
        HandleBulkDataCallback callback
    );

    DICOM_EXPORT [[nodiscard]] bool stream_pixel_data_encapsulated(
        InputContext* ctx,
        bool reverse_endian,
        const PixelDataRange& range,
        HandleBulkDataCallback callback
    );

}