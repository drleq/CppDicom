#pragma once

#include "dicom/DataDictionary.h"
#include "dicom/io/part10/InputStream.h"

namespace dicom::data { class AttributeSet; }

namespace dicom::io::part10::detail {

    DICOM_EXPORT [[nodiscard]] bool read_file_meta_information(
        const InputStreamPtr& stream,
        const DataDictionaryPtr& data_dictionary,
        data::AttributeSet* dest
    );

}