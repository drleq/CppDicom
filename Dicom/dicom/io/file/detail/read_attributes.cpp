#include "dicom_pch.h"
#include "dicom/io/file/detail/read_attributes.h"

#include "dicom/DataDictionary.h"
#include "dicom/data/string_converter/StringConverter.h"
#include "dicom/data/AttributeSet.h"
#include "dicom/data/CS.h"
#include "dicom/data/UI.h"
#include "dicom/io/file/detail/derive_pixel_data_ranges.h"
#include "dicom/io/file/detail/InputContext.h"
#include "dicom/io/file/detail/read_data_element.h"
#include "dicom/io/TransferSyntax.h"
#include "dicom/Tags.h"

using namespace dicom::data;

namespace dicom::io::file::detail {

    bool read_attributes(
        InputContext& ctx,
        AttributeSet* dest,
        std::vector<PixelDataRange>* pixel_data_ranges
    ) {
        while (*ctx.Stream() && !ctx.Failed()) {
            // Read the next data element.
            tag_number tag;
            auto vr = read_data_element(ctx, dest, &tag);

            if (tag == tags::PixelData) {
                if (!derive_pixel_data_ranges(ctx, dest, pixel_data_ranges)) {
                    return false;
                }
                continue;
            }

            if (vr == nullptr) {
                continue;
            }

            if (tag == tags::SpecificCharacterSet) {
                // We have encountered the SpecificCharacterSet attribute. Attempt to update the
                // string converter. Note that we do not need to apply it retroactively.
                auto cs = dynamic_cast<CS*>(vr.get());
                if (cs == nullptr || cs->Validity() == ValidityType::Invalid) { return false; }
                auto string_encoding = string_converter::convert_to_string_encoding(cs->Parsed());
                ctx.SetStringEncoding(string_encoding);
            }

            dest->Add(tag, std::move(vr));
        }

        return ctx.Stream()->Good() && !ctx.Failed();
    }

}