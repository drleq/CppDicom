#pragma once

#include "dicom/io/IMetadataSource.h"
#include "dicom/io/file/AttributeFilter.h"

namespace dicom::io::file {

    class FileMetadataSource : public IMetadataSource
    {
    public:
        FileMetadataSource(
            AttributeFilter attribute_filter = AttributeFilter(),
            PrivateAttributeFilter private_attribute_filter = PrivateAttributeFilter()
        );
        virtual ~FileMetadataSource();

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] LoadResultPtr Load(
            const std::string_view& filename,
            const DataDictionaryPtr& data_dictionary
        ) const override final;

    private:
        AttributeFilter m_attribute_filter;
        PrivateAttributeFilter m_private_attribute_filter;
    };

}