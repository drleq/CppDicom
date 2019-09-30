#pragma once

#include "dicom/net/DataStorage.h"

namespace dicom::net::detail {

    std::vector<DataStorageSequence> fragment_message_data(
        size_t maximum_fragment_length,
        bool is_command_set,
        const DataStorageSequence& data
    );

}