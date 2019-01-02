#pragma once

#include "dicom/io/PixelDataCompressionType.h"
#include "dicom/io/codec/ICodec.h"
#include "dicom/io/codec/PixelDataFormatType.h"

namespace dicom::io::codec {

    class DICOM_EXPORT ICodecFactory
    {
    public:
        virtual ~ICodecFactory() = default;

        [[nodiscard]] virtual std::unique_ptr<ICodec> Create00(
            PixelDataCompressionType codec_type,
            PixelDataFormatType pixel_format
        ) const = 0;
    };

}