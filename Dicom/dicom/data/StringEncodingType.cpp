#include "dicom_pch.h"
#include "dicom/data/StringEncodingType.h"

#include "dicom/data/string_converter/iso_iec_2022_converter.h"
#include "dicom/data/AttributeSet.h"
#include "dicom/data/encoded_string.h"
#include "dicom/data/LO.h"
#include "dicom/data/LT.h"
#include "dicom/data/PN.h"
#include "dicom/data/SH.h"
#include "dicom/data/ST.h"
#include "dicom/data/UT.h"

//-------------------------------------------------------------------------------------------------

namespace {
    using namespace dicom::data;

    template <typename TVR>
    [[nodiscard]] bool extract_string_encodings_from_vr(
        const VR* vr,
        std::set<StringEncodingType>& string_encodings
    ) {
        const encoded_string& value = static_cast<const TVR*>(vr)->Value();
        string_encodings.insert(value.Encoding());

        switch (value.Encoding()) {
        case StringEncodingType::CodeExtension_ISO_IEC_646:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_1:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_2:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_3:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_4:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_5:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_6:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_7:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_8:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_9:
        case StringEncodingType::CodeExtension_JIS_X_0201:
        case StringEncodingType::CodeExtension_JIS_X_0208:
        case StringEncodingType::CodeExtension_JIS_X_0212:
        case StringEncodingType::CodeExtension_TIS_620_2533:
        case StringEncodingType::CodeExtension_KS_X_1001:
            return string_converter::extract_string_encodings(
                std::string_view(value.Value(), value.Value().ByteLength()),
                string_encodings
            );

        default:
            return true;
        }
    }
}

//-------------------------------------------------------------------------------------------------

namespace dicom::data {

    bool extract_string_encodings(
        const AttributeSet& as,
        std::set<StringEncodingType>& string_encodings
    ) {
        auto it = as.BeginGroup(0x0008);
        auto end_it = as.End();

        for (; it != end_it; ++it) {
            const VR* vr = it->second;
            if (!vr->IsValid()) { continue; }

            bool result = false;
            switch (vr->Type()) {
            case VRType::LO: result = extract_string_encodings_from_vr<LO>(vr, string_encodings); break;
            case VRType::LT: result = extract_string_encodings_from_vr<LT>(vr, string_encodings); break;
            case VRType::PN: result = extract_string_encodings_from_vr<PN>(vr, string_encodings); break;
            case VRType::SH: result = extract_string_encodings_from_vr<SH>(vr, string_encodings); break;
            case VRType::ST: result = extract_string_encodings_from_vr<ST>(vr, string_encodings); break;
            case VRType::UT: result = extract_string_encodings_from_vr<UT>(vr, string_encodings); break;

            default:
                continue;
            }

            if (!result) { return false; }
        }

        return true;
    }

}