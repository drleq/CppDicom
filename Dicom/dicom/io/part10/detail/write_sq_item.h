#pragma once

namespace dicom::io::part10::detail { class OutputContext; }
#include "dicom/data/SQ.h"

namespace dicom::io::part10::detail {

    DICOM_EXPORT void write_sq_item(
        OutputContext* context,
        const data::SQ::item_type& item,
        bool unknown_length
    );

}