#include "dicomnet_pch.h"
#include "dicom/net/detail/fragment_message_data.h"

namespace dicom::net::detail {

    std::vector<DataStorageSequence> fragment_message_data(
        size_t maximum_fragment_length,
        bool is_command_set,
        const DataStorageSequence& data
    ) {
        static const auto NonLastCommandFlag = std::make_shared<UniqueValueDataStorage>(data_buffer{ 0x01 });
        static const auto LastCommandFlag = std::make_shared<UniqueValueDataStorage>(data_buffer{ 0x03 });
        static const auto NonLastDatasetFlag = std::make_shared<UniqueValueDataStorage>(data_buffer{ 0x00 });
        static const auto LastDatasetFlag = std::make_shared<UniqueValueDataStorage>(data_buffer{ 0x02 });
        constexpr size_t MessageFlagSize = 1;
        constexpr size_t ValueItemHeaderSize = 4 + 1;
        constexpr size_t HeaderSize = ValueItemHeaderSize + MessageFlagSize;

        DataStoragePtr non_last_fragment_flag;
        DataStoragePtr last_fragment_flag;
        if (is_command_set) {
            non_last_fragment_flag = NonLastCommandFlag;
            last_fragment_flag = LastCommandFlag;
        } else {
            non_last_fragment_flag = NonLastDatasetFlag;
            last_fragment_flag = LastDatasetFlag;
        }

        // [data] contains a sequence of buffers representing all the data we want to send.  For
        // transmission over the ACSE layer the data needs to be split into fragments and sent as
        // individual messages.  Each fragment can consist of multiple buffers to make up the maximum
        // allowed length, including a single byte buffer at the beginning that
        std::vector<DataStorageSequence> fragments;
        DataStorageSequence fragment { non_last_fragment_flag };
        size_t fragment_remaining = maximum_fragment_length - HeaderSize;

        for (auto& s : data) {
            auto length = s->AsBuffer().size();

            size_t pos = 0;
            while (pos < length) {
                size_t sub_length = std::min(fragment_remaining, length - pos);

                auto sub_storage = std::make_shared<SubRangeDataStorage>(s, pos, sub_length);
                fragment.push_back(std::move(sub_storage));

                pos += sub_length;
                fragment_remaining -= sub_length;

                if (fragment_remaining == 0) {
                    fragments.push_back(std::move(fragment));

                    fragment_remaining = maximum_fragment_length - HeaderSize;
                    fragment.push_back(non_last_fragment_flag);
                }
            }
        }

        if (fragment.size() > 1) {
            fragment[0] = last_fragment_flag;
            fragments.push_back(std::move(fragment));
        }

        return fragments;
    }

}