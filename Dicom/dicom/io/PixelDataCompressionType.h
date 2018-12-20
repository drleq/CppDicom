#pragma once

namespace dicom::io {

    enum class PixelDataCompressionType
    {
        None,
        RLE,
        Jpeg,
        JpegLossless,
        JpegLS,
        JpegLSLossless,
        Jpeg2000,
        Jpeg2000Lossless,
        Mpeg2,
        Mpeg4,
        Deflate,
        Jpip,
        JpipDeflate
    };

}