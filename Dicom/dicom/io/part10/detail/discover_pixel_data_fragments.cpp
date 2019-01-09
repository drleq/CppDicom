#include "dicom_pch.h"
#include "dicom/io/part10/detail/discover_pixel_data_fragments.h"

#include "dicom/io/part10/detail/InputContext.h"

namespace {
    constexpr dicom::tag_number SequenceDeliminationItem = 0xFFFEE0DD;
}

namespace dicom::io::part10::detail {

    std::vector<FragmentInfo> discover_pixel_data_fragments(
        InputContext* context,
        size_t raw_length,
        size_t* real_length
    ) {
        std::vector<FragmentInfo> fragments;
        size_t remaining = raw_length;
        *real_length = 0;

        auto& stream = context->Stream();

        while (remaining > 0 && *stream && !context->Failed()) {
            auto tag = context->ReadTagNumber();
            auto tag_length = static_cast<uint32_t>(context->ReadSQLength());

            if (tag == SequenceDeliminationItem) {
                remaining -= sizeof(FragmentInfo);
                break;
            }
            fragments.emplace_back(FragmentInfo{ tag, tag_length });

            stream->Seek(tag_length, std::ios::cur);
            remaining -= (tag_length + sizeof(FragmentInfo));
            *real_length += tag_length;
        }

        bool ok = stream->Good() && (remaining == 0);
        return ok ? fragments : std::vector<FragmentInfo>();
    }

}