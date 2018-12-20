#include "dicom_pch.h"
#include "dicom/io/codec/CodecImage.h"

namespace {
    using namespace dicom::io::codec;

    size_t bytes_per_pixel(PixelDataFormatType pixel_format) {
        switch (pixel_format) {
        case PixelDataFormatType::GrayscaleSigned16:
        case PixelDataFormatType::GrayscaleUnsigned16:
            return 2;

        case PixelDataFormatType::RGB24:
            return 3;

        case PixelDataFormatType::ARGB32:
            return 4;

        default:
            throw std::invalid_argument("Unknown pixel data format");
        }
    }
}

//------------------------------------------------------------------------------------------------------------

namespace dicom::io::codec {

    CodecImage::CodecImage()
      : m_pixel_format(PixelDataFormatType(-1)),
        m_width(0),
        m_height(0),
        m_stride(0)
    {}

    //--------------------------------------------------------------------------------------------------------

    CodecImage::CodecImage(PixelDataFormatType pixel_format, size_t width, size_t height)
      : m_pixel_format(pixel_format),
        m_width(width),
        m_height(height)
    {
        m_stride = width * bytes_per_pixel(pixel_format);
        m_buffer = data::buffer<int8_t>(m_stride * height);
    }

    //--------------------------------------------------------------------------------------------------------

    CodecImage::CodecImage(
        int8_t* buffer,
        PixelDataFormatType pixel_format,
        size_t width,
        size_t height,
        size_t stride
    ) : m_buffer(buffer, stride * height),
        m_pixel_format(pixel_format),
        m_width(width),
        m_height(height),
        m_stride(stride)
    {
        if (buffer == nullptr) {
            throw std::invalid_argument("Buffer cannot be null");
        }

        // This will assert if [pixel_format] is unknown
        bytes_per_pixel(pixel_format);
    }

    //--------------------------------------------------------------------------------------------------------

    CodecImage::~CodecImage() = default;

    //--------------------------------------------------------------------------------------------------------

    data::buffer<int8_t> CodecImage::DetachBuffer() {
        m_pixel_format = PixelDataFormatType(-1);
        m_width = 0;
        m_height = 0;
        m_stride = 0;
        return std::move(m_buffer);
    }

}