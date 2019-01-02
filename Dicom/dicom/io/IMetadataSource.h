#pragma once

#include "dicom/DataDictionary.h"
#include "dicom/io/ILoadResult.h"

namespace dicom::io {

    class DICOM_EXPORT IMetadataSource
    {
    public:
        virtual ~IMetadataSource() = default;

        [[nodiscard]] virtual LoadResultPtr Load(
            const std::string_view& location,
            const DataDictionaryPtr& data_dictionary
        ) const = 0;
    };

    using MetadataSourcePtr = std::shared_ptr<IMetadataSource>;

}