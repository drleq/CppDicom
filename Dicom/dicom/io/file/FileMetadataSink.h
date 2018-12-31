#pragma once

#include "dicom/io/IMetadataSink.h"
#include "dicom/data/StringEncodingType.h"

namespace dicom::io::file {

    class DICOM_EXPORT FileMetadataSink : public IMetadataSink
    {
    public:
        FileMetadataSink();
        virtual ~FileMetadataSink();

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Save(
            const std::string& location,
            const TransferSyntax* transfer_syntax,
            const data::AttributeSetConstPtr& metadata,
            WritePixelDataCallback write_pixel_data_callback
        ) const override final;
    };

}