#include "dicom_pch.h"
#include "dicom/io/file/detail/read_data_element.h"

#include "dicom/DataDictionary.h"
#include "dicom/Tags.h"
#include "dicom/data/AttributeSet.h"
#include "dicom/data/VRType.h"
#include "dicom/io/file/detail/create_deferred_vr.h"
#include "dicom/io/file/detail/InputContext.h"
#include "dicom/io/file/detail/read_vr.h"
#include "dicom/io/file/detail/read_vr_type_and_length.h"

using namespace std;
using namespace dicom::data;

namespace dicom::io::file::detail {

    unique_ptr<data::VR> read_data_element(
        InputContext& ctx,
        const data::AttributeSet* attribute_set,
        tag_number* tag_out
    ) {
        tag_number tag = *tag_out = ctx.ReadTagNumber();

        if (tag == tags::PixelData) {
            // Don't read the VR type or length for pixel data. We want to handle that elsewhere.
            return nullptr;
        }

        VRType vr_type;
        streamsize length;
        read_vr_type_and_length(
            ctx,
            attribute_set,
            tag,
            ctx.Stream()->Length(),
            &vr_type,
            &length
        );

        bool is_group_len = is_group_length(tag) && (tag != tags::FileMetaInformationGroupLength);
        if (is_group_len) {
            // Deliberately skip the tag.
            ctx.Stream()->Seek(length, ios::cur);
            return nullptr;
        }

        AttributeFilterResult filter_result = ctx.Filter(attribute_set, tag);
        switch (filter_result) {
        case AttributeFilterResult::Drop:
            ctx.Stream()->Seek(length, ios::cur);
            return nullptr;

        case AttributeFilterResult::Defer:
            return create_deferred_vr(ctx, length, vr_type);

        case AttributeFilterResult::Load:
            return read_vr(ctx, length, vr_type);

        default:
            // The [filter_result] wasn't a known value. Abandon all hope.
            ctx.SetFailed();
            return nullptr;
        }
    }

}