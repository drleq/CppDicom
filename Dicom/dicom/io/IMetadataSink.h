#pragma once

#include "dicom/data/AttributeSet.h"
#include "dicom/io/TransferSyntax.h"

namespace dicom::io {

    // bool (const void* data, size_t length)
    using WritePixelDataFunction = std::function<bool(const void*, size_t)>;

    // bool (size_t frame_index, WritePixelDataFunction write_func)
    using WritePixelDataCallback = std::function<bool(size_t, WritePixelDataFunction)>;

    class DICOM_EXPORT IMetadataSink
    {
    public:
        virtual ~IMetadataSink() = default;

        [[nodiscard]] virtual bool Save(
            const std::string& location,
            const TransferSyntax* transfer_syntax,
            const data::AttributeSetConstPtr& metadata,
            WritePixelDataCallback write_pixel_data_callback
        ) const = 0;
    };

    using MetadataSinkPtr = std::shared_ptr<IMetadataSink>;

}