#pragma once

#include "dicom/DataDictionary.h"
#include "dicom/io/part10/AttributeFilter.h"
#include "dicom/io/part10/InputStream.h"
#include "dicom/io/ILoadResult.h"

namespace dicom::io::part10 {

    class DICOM_EXPORT Part10Reader
    {
    public:
        static [[nodiscard]] LoadResultPtr Read(
            const InputStreamPtr& stream,
            const DataDictionaryPtr& data_dictionary,
            AttributeFilter attribute_filter = AttributeFilter(),
            PrivateAttributeFilter private_attribute_filter = PrivateAttributeFilter()
        );
    };

}