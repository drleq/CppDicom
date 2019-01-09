#pragma once

#include "dicom/DataDictionary.h"
#include "dicom/io/file/AttributeFilter.h"
#include "dicom/io/ILoadResult.h"

namespace dicom::io::file {

    class DICOM_EXPORT FileMetadataSource
    {
    public:
        static [[nodiscard]] LoadResultPtr Load(
            const std::string_view& filename,
            const DataDictionaryPtr& data_dictionary,
            AttributeFilter attribute_filter = AttributeFilter(),
            PrivateAttributeFilter private_attribute_filter = PrivateAttributeFilter()
        );
    };

}