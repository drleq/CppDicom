#include "dicomnet_pch.h"
#include "dicom/net/detail/encode_dimse_message.h"

#include "dicom/net/detail/encode_command_set.h"
#include "dicom/net/detail/fragment_message_data.h"

namespace dicom::net::detail {

    std::vector<DataStorageSequence> encode_dimse_message(
        size_t maximum_fragment_length,
        const data::AttributeSet& command_set//,
        /* ??? dataset */
    ) {
        // Encode the command set to a buffer.
        auto encoded_command_set = encode_command_set(command_set);
        auto command_set_sequence = fragment_message_data(
            maximum_fragment_length,
            true,
            { encoded_command_set }
        );

        // Encode the dataset to a buffer.

        return command_set_sequence;
    }

}