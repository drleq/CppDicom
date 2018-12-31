#pragma once

namespace dicom::io::file::detail { class OutputContext; }
#include "dicom/data/SQ.h"

namespace dicom::io::file::detail {

    DICOM_EXPORT void write_sq_item(
        OutputContext* context,
        const data::SQ::item_type& item,
        bool unknown_length
    );

}