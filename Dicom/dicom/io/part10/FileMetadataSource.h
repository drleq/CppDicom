#pragma once

#include "dicom/DataDictionary.h"
#include "dicom/io/part10/AttributeFilter.h"
#include "dicom/io/ILoadResult.h"

namespace dicom::io::part10 {

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