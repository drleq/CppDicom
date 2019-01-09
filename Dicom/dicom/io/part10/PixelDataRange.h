#pragma once

#include "dicom/io/PixelDataEncodingType.h"

namespace dicom::io::part10 {

    class DICOM_EXPORT PixelDataRange
    {
    public:
        constexpr PixelDataRange(size_t start_offset, size_t length, PixelDataEncodingType encoding_type)
          : m_start_offset(start_offset),
            m_length(length),
            m_encoding_type(encoding_type)
        {}

        [[nodiscard]] constexpr size_t StartOffset() const { return m_start_offset; }
        [[nodiscard]] constexpr size_t Length() const { return m_length; }
        [[nodiscard]] constexpr PixelDataEncodingType EncodingType() const { return m_encoding_type; }

    private:
        size_t m_start_offset;
        size_t m_length;
        PixelDataEncodingType m_encoding_type;
    };

}