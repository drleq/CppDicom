#include "dicom_pch.h"
#include "dicom/io/file/detail/write_attributes.h"

#include "dicom/data/AttributeSet.h"
#include "dicom/data/string_converter/StringConverter.h"
#include "dicom/data/CS.h"
#include "dicom/io/file/detail/OutputContext.h"
#include "dicom/io/file/detail/write_data_element.h"
#include "dicom/Tags.h"

using namespace dicom::data;

namespace dicom::io::file::detail {

    bool write_attributes(OutputContext* ctx, const data::AttributeSet* src) {
        auto& stream = ctx->Stream();

        // Iterate all attributes excluding File Meta Information tags.
        auto it = src->EndGroup(tags::FileMetaInformationGroupLength.Group());
        auto end_it = src->End();

        for (; it != end_it; ++it) {
            tag_number tag = it->first;
            const VR* attribute = it->second;

            // Stop at pixel data.
            if (tag == tags::PixelData) { break; }

            // Skip group length tags.
            if (is_group_length(tag)) { continue; }

            if (tag != tags::SpecificCharacterSet) {
                // Write the attribute.
                write_data_element(ctx, tag, attribute);
                continue;
            }

            // SpecificCharacterSet
            if (attribute->Type() != VRType::CS) { return false; }
            if (attribute->Validity() != ValidityType::Valid && attribute->Validity() != ValidityType::Acceptable) { return false; }
                
            // Update the specific character set.
            auto character_sets = static_cast<const CS*>(attribute)->Parsed();
            auto string_encoding = string_converter::convert_to_string_encoding(character_sets);
            ctx->SetStringEncoding(string_encoding);

            // Write out the coerced character set description
            CS coerced_attribute(character_sets);
            write_data_element(ctx, tag, &coerced_attribute);
        }

        return *stream && !ctx->Failed();
    }

}