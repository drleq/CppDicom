#pragma once

#include "dicom/data/AttributeSet.h"
#include "dicom/data/buffer.h"
#include "dicom/io/HandleBulkDataCallback.h"

namespace dicom::io {

    class ILoadResult
    {
    public:
        virtual ~ILoadResult() = default;

        [[nodiscard]] virtual const data::AttributeSetPtr& Metadata() const = 0;

        [[nodiscard]] virtual size_t FrameCount() const = 0;
        [[nodiscard]] virtual bool StreamPixelData(size_t frame_index, HandleBulkDataCallback callback) const = 0;
        [[nodiscard]] virtual data::buffer<int8_t> GetPixelData(size_t frame_index) const = 0;
    };

    using LoadResultPtr = std::shared_ptr<ILoadResult>;

}