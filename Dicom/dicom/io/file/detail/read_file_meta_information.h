#pragma once

#include "dicom/DataDictionary.h"
#include "dicom/io/file/detail/InputStream.h"

namespace dicom::data { class AttributeSet; }

namespace dicom::io::file::detail {

    [[nodiscard]] bool read_file_meta_information(
        const InputStreamPtr& stream,
        const DataDictionaryPtr& data_dictionary,
        data::AttributeSet* dest
    );

}