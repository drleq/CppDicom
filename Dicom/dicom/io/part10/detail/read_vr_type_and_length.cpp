#include "dicom_pch.h"
#include "dicom/io/part10/detail/read_vr_type_and_length.h"

#include "dicom/data/AttributeSet.h"
#include "dicom/io/part10/detail/InputContext.h"

using namespace dicom::data;

namespace dicom::io::part10::detail {

    void read_vr_type_and_length(
        InputContext& context,
        const data::AttributeSet* attribute_set,
        tag_number tag,
        std::streamoff end_position,
        data::VRType* vr_type,
        std::streamsize* length
    ) {
        *vr_type = VRType::UN;
        if (context.Encoding() == TagEncodingType::Explicit) {
            // Explicit encoding. VR type is in the stream.
            *vr_type = context.Stream()->ReadValue<VRType>();
        } else if (is_creator_tag(tag)) {
            // Private Creator tags are always type LO.
            *vr_type = VRType::LO;
        } else if (!is_group_length(tag)) {
            // Implicit encoding. VR type is obtained from data dictionary.
            *vr_type = context.LookupVRType(attribute_set, tag);
        }

        // Determine the length of the tag data
        if (context.Encoding() == TagEncodingType::Implicit) {
            *length = context.ReadImplicitTagLength();
            if (*length == 0xFFFFFFFF) {
                // Implicit data with an unknown length will be encoded like an SQ.
                *vr_type = VRType::SQ;
            }
        } else {
            *length = context.ReadExplicitTagLength(*vr_type, end_position);
        }
    }

}