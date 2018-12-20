#pragma once

#include "dicom/io/codec/ICodecImage.h"

namespace dicom::io::codec {

    using WriteDataCallback = std::function<bool (const void*, size_t)>;

    class ICodec
    {
    public:
        virtual ~ICodec() = default;

        [[nodiscard]] virtual std::unique_ptr<ICodecImage> Decode00(
            const void* buf,
            size_t buf_length
        ) const = 0;

        [[nodiscard]] virtual bool Encode00(
            const ICodecImage* image,
            const WriteDataCallback& write_callback
        ) const = 0;
    };

}