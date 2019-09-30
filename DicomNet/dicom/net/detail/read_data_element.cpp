#include "dicomnet_pch.h"
#include "dicom/net/detail/read_data_element.h"

#include "dicom/data/VR.h"
#include "dicom/io/part10/detail/InputContext.h"
#include "dicom/io/part10/detail/read_vr.h"

namespace dicom::net::detail {

    [[nodiscard]] bool read_data_element(
        io::part10::detail::InputContext& ctx,
        tag_number* tag,
        std::unique_ptr<data::VR>* attribute
    ) {
        *tag = ctx.ReadTagNumber();
        auto length = ctx.ReadImplicitTagLength();

        auto vr_type = ctx.DataDictionary()->Get(*tag);
        if (!vr_type) {
            // Unknown attribute.
            return false;
        }

        *attribute = io::part10::detail::read_vr(ctx, length, vr_type->Type);
        if (!attribute) {
            return false;
        }

        return !ctx.Failed() && ctx.Stream()->Good();
    }

}