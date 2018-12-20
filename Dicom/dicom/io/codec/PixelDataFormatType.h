#pragma once

namespace dicom::io::codec {

    enum class PixelDataFormatType
    {
        RGB24,
        ARGB32,
        GrayscaleUnsigned16,
        GrayscaleSigned16,
        GrayscaleUnsigned8,
        GrayscaleSigned8
    };

}