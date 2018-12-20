#pragma once

#include "dicom/io/file/detail/OutputStream.h"
namespace dicom::data { class AttributeSet; }
namespace dicom::io { struct TransferSyntax; }

namespace dicom::io::file::detail {

    [[nodiscard]] bool write_file_meta_information(
        const OutputStreamPtr& stream,
        const TransferSyntax* transfer_syntax,
        const data::AttributeSet* src
    );

}