#pragma once

namespace dicom::data { class AttributeSet; }
#include "dicom/net/DataStorage.h"

namespace dicom::net::detail {

    std::vector<DataStorageSequence> encode_dimse_message(
        size_t maximum_fragment_length,
        const data::AttributeSet& command_set//,
        /* ??? dataset */
    );

}