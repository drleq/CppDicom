#pragma once

#include "dicom/data/AttributeSet.h"
#include "dicom/data/StringEncodingType.h"
#include "dicom/io/TransferSyntax.h"

namespace dicom::io::part10 {

    // bool (const void* data, size_t length)
    using WritePixelDataFunction = std::function<bool(const void*, size_t)>;

    // bool (size_t frame_index, WritePixelDataFunction write_func)
    using WritePixelDataCallback = std::function<bool(size_t, WritePixelDataFunction)>;

    class DICOM_EXPORT FileMetadataSink
    {
    public:
        static [[nodiscard]] bool Save(
            const std::string& location,
            const TransferSyntax* transfer_syntax,
            const data::AttributeSetConstPtr& metadata,
            WritePixelDataCallback write_pixel_data_callback
        );
    };

}