#include "dicom_pch.h"
#include "dicom/io/part10/detail/write_sq_item.h"

#include "dicom/io/part10/detail/OutputContext.h"
#include "dicom/io/part10/detail/write_data_element.h"

using namespace dicom::data;

namespace {
    constexpr dicom::tag_number ItemDeliminationItem = 0xFFFEE00D;
    constexpr uint32_t ZeroLength = 0;
}

namespace dicom::io::part10::detail {

    void write_sq_item(
        OutputContext* ctx,
        const data::SQ::item_type& item,
        bool unknown_length
    ) {
        for (auto& kvp : *item) {
            tag_number tag = kvp.first;
            const VR* attribute = kvp.second;

            // Skip group length tags.
            if (is_group_length(tag)) { continue; }

            // Write the attribute.
            write_data_element(ctx, tag, attribute);
        }

        if (unknown_length) {
            // Close the item sequence.
            ctx->WriteTagNumber(ItemDeliminationItem);
            ctx->WriteSQLength(ZeroLength);
        }
    }

}