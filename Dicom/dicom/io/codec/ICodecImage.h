#pragma once

#include "dicom/data/buffer.h"
#include "dicom/io/codec/PixelDataFormatType.h"

namespace dicom::io::codec {

    class DICOM_EXPORT ICodecImage
    {
    public:
        virtual ~ICodecImage() = default;

        [[nodiscard]] virtual const int8_t* Buffer() const = 0;
        [[nodiscard]] virtual       int8_t* Buffer()       = 0;

        [[nodiscard]] virtual PixelDataFormatType PixelFormat() const = 0;
        [[nodiscard]] virtual size_t Width() const = 0;
        [[nodiscard]] virtual size_t Height() const = 0;
        [[nodiscard]] virtual size_t Stride() const = 0;

        [[nodiscard]] virtual data::buffer<int8_t> DetachBuffer() = 0;
    };

}