#pragma once

#include "dicom/io/codec/ICodecImage.h"

namespace dicom::io::codec {

    class CodecImage : public ICodecImage
    {
    public:
        CodecImage();
        CodecImage(PixelDataFormatType pixel_format, size_t width, size_t height);
        CodecImage(
            int8_t* buffer,
            PixelDataFormatType pixel_format,
            size_t width,
            size_t height,
            size_t stride
        );
        virtual ~CodecImage();

        [[nodiscard]] const int8_t* Buffer() const override final { return m_buffer; }
        [[nodiscard]]       int8_t* Buffer()       override final { return m_buffer; }

        [[nodiscard]] PixelDataFormatType PixelFormat() const override final { return m_pixel_format; }
        [[nodiscard]] size_t Width() const override final { return m_width; }
        [[nodiscard]] size_t Height() const override final { return m_height; }
        [[nodiscard]] size_t Stride() const override final { return m_stride; }

        [[nodiscard]] data::buffer<int8_t> DetachBuffer() override final;

    private:
        data::buffer<int8_t> m_buffer;
        PixelDataFormatType m_pixel_format;
        size_t m_width;
        size_t m_height;
        size_t m_stride;
    };

}