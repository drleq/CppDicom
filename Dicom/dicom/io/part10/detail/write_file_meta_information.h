#pragma once

#include "dicom/io/part10/OutputStream.h"
namespace dicom::data { class AttributeSet; }
namespace dicom::io { struct TransferSyntax; }

namespace dicom::io::part10::detail {

    DICOM_EXPORT [[nodiscard]] bool write_file_meta_information(
        const OutputStreamPtr& stream,
        const TransferSyntax* transfer_syntax,
        const data::AttributeSet* src
    );

}