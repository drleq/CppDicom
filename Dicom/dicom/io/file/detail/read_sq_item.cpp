#include "dicom_pch.h"
#include "dicom/io/file/detail/read_sq_item.h"

#include "dicom/DataDictionary.h"
#include "dicom/io/file/detail/create_deferred_vr.h"
#include "dicom/io/file/detail/InputContext.h"
#include "dicom/io/file/detail/read_vr.h"
#include "dicom/io/file/detail/read_vr_type_and_length.h"

using namespace std;
using namespace dicom::data;

namespace {
    constexpr dicom::tag_number ItemDeliminationItem = 0xFFFEE00D;
}

namespace dicom::io::file::detail {

    SQ::item_type read_sq_item(InputContext& ctx, std::streamsize length) {
        auto& stream = ctx.Stream();
        auto item = make_unique<AttributeSet>();

        auto end_position = stream->Tell() + length;
        auto end_position_without_delimiter = end_position - static_cast<streamoff>(sizeof(tag_number) + sizeof(uint32_t));

        while (stream->Tell() < end_position && !ctx.Failed()) {
            // Read the next tag.
            auto tag = ctx.ReadTagNumber();

            // If this is the end of the Item then quit.
            if (tag == ItemDeliminationItem) {
                // Skip the length. It should be zero.
                stream->Seek(sizeof(uint32_t), ios::cur);
                break;
            }

            VRType vr_type;
            streamsize tag_length;
            read_vr_type_and_length(
                ctx,
                item.get(),
                tag,
                end_position_without_delimiter,
                &vr_type,
                &tag_length
            );
            
            if (is_group_length(tag)) {
                stream->Seek(tag_length, ios::cur);
                continue;
            }


            AttributeFilterResult filter_result = ctx.Filter(item.get(), tag);
            switch (filter_result) {
            case AttributeFilterResult::Drop:
                stream->Seek(tag_length, ios::cur);
                break;

            case AttributeFilterResult::Defer:
                item->Add(tag, create_deferred_vr(ctx, tag_length, vr_type));
                break;

            case AttributeFilterResult::Load:
                item->Add(tag, read_vr(ctx, tag_length, vr_type));
                break;

            default:
                // The [filter_result] wasn't a known value. Abandon all hope.
                ctx.SetFailed();
                return nullptr;
            }
        }

        return item;
    }

}