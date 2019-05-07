#include "dicom_pch.h"
#include "dicom/io/part19/Part19Writer.h"

#include "dicom/data/AE.h"
#include "dicom/data/AS.h"
#include "dicom/data/AT.h"
#include "dicom/data/CS.h"
#include "dicom/data/DA.h"
#include "dicom/data/DS.h"
#include "dicom/data/DT.h"
#include "dicom/data/FD.h"
#include "dicom/data/FL.h"
#include "dicom/data/IS.h"
#include "dicom/data/LO.h"
#include "dicom/data/LT.h"
#include "dicom/data/OB.h"
#include "dicom/data/OD.h"
#include "dicom/data/OF.h"
#include "dicom/data/OL.h"
#include "dicom/data/OW.h"
#include "dicom/data/PN.h"
#include "dicom/data/SH.h"
#include "dicom/data/SL.h"
#include "dicom/data/SQ.h"
#include "dicom/data/SS.h"
#include "dicom/data/ST.h"
#include "dicom/data/TM.h"
#include "dicom/data/UC.h"
#include "dicom/data/UI.h"
#include "dicom/data/UL.h"
#include "dicom/data/UN.h"
#include "dicom/data/UR.h"
#include "dicom/data/US.h"
#include "dicom/data/UT.h"
#include "dicom/data/VRType.h"

#include "dicom/detail/Base64.hpp"

#include <iomanip>
#include <fstream>

using namespace dicom;
using namespace dicom::data;

namespace {
    // Helper to cast from VR* to T*. Acts as shorthand.
    template <typename T>
    [[nodiscard]] const T* as(const VR* attribute) {
        // Static cast should be OK as switch statement handles the type check.
        return static_cast<const T*>(attribute);
    }

    //--------------------------------------------------------------------------------------------------------

    void write_vr_type(std::ostream& dest, dicom::data::VRType vr_type) {
        // The VRType enum uses values equivalent to two character ASCII for Part10.  This also works when
        // writing out UTF-8.
        dest.write(
            reinterpret_cast<const char*>(&vr_type),
            2
        );
    }

    //--------------------------------------------------------------------------------------------------------
    
    void write_escaped_string(std::ostream& dest, const std::string_view& str) {
        std::string_view s = str;

        while (!s.empty()) {
            // Search for the next character that needs escaping.
            size_t next_escape_index = s.find_first_of("\"&'<>");
            if (next_escape_index == std::string_view::npos) {
                // Nothing to escape.  Just write everything else then stop.
                dest.write(s.data(), s.size());
                break;
            }

            if (next_escape_index != 0) {
                // Write out all data before the escaped character.
                dest.write(s.data(), next_escape_index);
            }

            // Write out the escape sequence.
            switch (s[next_escape_index]) {
            case '"': dest.write("&quot;", 6); break;
            case '&': dest.write("&amp;", 5); break;
            case '\'': dest.write("&apos;", 6); break;
            case '<': dest.write("&lt;", 4); break;
            case '>': dest.write("&gt;", 4); break;
            }

            s.remove_prefix(next_escape_index + 1);
        }
    }

    //--------------------------------------------------------------------------------------------------------

    template <typename T>
    void write_value(std::ostream& dest, const dicom::data::buffer<T>& binary) {
        auto tmp_buffer = base64::encode_to_byte_vector(
            reinterpret_cast<const uint8_t*>(binary.Get()),
            binary.ByteLength()
        );

        dest.write(
            reinterpret_cast<const char*>(tmp_buffer.data()),
            tmp_buffer.size()
        );
    }

    //--------------------------------------------------------------------------------------------------------

    void write_value(std::ostream& dest, const dicom::data::date& value) {
        // YYYYMMDD
        dest << std::dec << std::setw(4) << std::setfill('0') << value.Year();
        dest << std::dec << std::setw(2) << std::setfill('0') << static_cast<int>(value.Month());
        dest << std::dec << std::setw(2) << std::setfill('0') << static_cast<int>(value.Day());
    }

    //--------------------------------------------------------------------------------------------------------

    void write_value(std::ostream& dest, const dicom::data::time& value) {
        // hhmmss.ffffff
        dest << std::dec << std::setw(2) << std::setfill('0') << static_cast<int>(value.Hour());
        dest << std::dec << std::setw(2) << std::setfill('0') << static_cast<int>(value.Minute());
        dest << std::dec << std::setw(2) << std::setfill('0') << static_cast<int>(value.Second());
        dest << ".";
        dest << std::dec << std::setw(6) << std::setfill('0') << value.Millisecond();
    }

    //--------------------------------------------------------------------------------------------------------

    void write_value(std::ostream& dest, const dicom::data::uri& value) {
        write_escaped_string(dest, value.Value());
    }

    //--------------------------------------------------------------------------------------------------------

    void write_value(std::ostream& dest, const std::string_view& value) {
        write_escaped_string(dest, value);
    }

    //--------------------------------------------------------------------------------------------------------

    void write_value(std::ostream& dest, const std::string& value) {
        write_escaped_string(dest, value);
    }

    //--------------------------------------------------------------------------------------------------------

    void write_value(std::ostream& dest, const dicom::data::encoded_string& value) {
        write_escaped_string(dest, value.Parsed());
    }

    //--------------------------------------------------------------------------------------------------------

    template <typename T>
    void write_value(std::ostream& dest, const T& value) {
        dest << std::dec << value;
    }

    //--------------------------------------------------------------------------------------------------------

    template <typename T>
    void write_single_value_vr(std::ostream& dest, const T* vr) {
        dest << "<Value number=\"1\">";
        write_value(dest, vr->Value());
        dest << "</Value>";
    }

    //--------------------------------------------------------------------------------------------------------

    template <typename T>
    void write_multi_value_vr(std::ostream& dest, const T* vr) {
        int number = 1;
        for (auto value : *vr) {
            dest << "<Value number=\"" << number++ << "\">";
            write_value(dest, value);
            dest << "</Value>";
        }
    }

    //--------------------------------------------------------------------------------------------------------

    template <typename T>
    void write_binary_vr(std::ostream& dest, const T* vr) {
        write_value(dest, vr->Value());
    }

    //--------------------------------------------------------------------------------------------------------

    void write_component_group(std::ostream& dest, const char* name, const dicom::data::ComponentGroup& value) {
        if (value.Empty()) {
            return;
        }

        dest << "<" << name << ">";

        if (!value.FamilyName().empty()) {
            dest << "<FamilyName>";
            write_escaped_string(dest, value.FamilyName());
            dest << "</FamilyName>";
        }
        if (!value.GivenName().empty()) {
            dest << "<GivenName>";
            write_escaped_string(dest, value.GivenName());
            dest << "</GivenName>";
        }
        if (!value.MiddleName().empty()) {
            dest << "<MiddleName>";
            write_escaped_string(dest, value.MiddleName());
            dest << "</MiddleName>";
        }
        if (!value.Prefix().empty()) {
            dest << "<NamePrefix>";
            write_escaped_string(dest, value.Prefix());
            dest << "</NamePrefix>";
        }
        if (!value.Suffix().empty()) {
            dest << "<NameSuffix>";
            write_escaped_string(dest, value.Suffix());
            dest << "</NameSuffix>";
        }

        dest << "</" << name << ">";
    }

    //--------------------------------------------------------------------------------------------------------

    void write_patient_name_vr(std::ostream& dest, const PN* vr) {
        int number = 1;
        for (auto value : *vr) {
            dest << "<PatientName number=\"" << number++ << "\">";

            write_component_group(dest, "Alphabetic", value.Alphabetic());
            write_component_group(dest, "Ideographic", value.Ideographic());
            write_component_group(dest, "Phonetic", value.Phonetic());

            dest << "</PatientName>";
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void write_attribute_set(std::ostream& dest, const dicom::data::AttributeSet* attribs);

    void write_sq_vr(std::ostream& dest, const SQ* vr) {
        int number = 1;
        for (auto& attrib_set : *vr) {
            dest << "<Item number=\"" << number++ << "\">";

            write_attribute_set(dest, attrib_set.get());

            dest << "</Item>";
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void write_attribute_set(std::ostream& dest, const dicom::data::AttributeSet* attribs) {
        for (auto& kvp : *attribs) {
            if (kvp.second->Empty() || !kvp.second->IsValid()) {
                continue;
            }

            dest << "<DicomAttribute";

            // keyword?
            
            uint16_t group = dicom::get_tag_group(kvp.first);
            uint16_t element = dicom::get_tag_element(kvp.first);
            dest << " tag=\""
                << std::hex << std::setw(4) << std::setfill('0') << group
                << std::hex << std::setw(4) << std::setfill('0') << element 
                << "\"";

            dest << " vr=\"";
            write_vr_type(dest, kvp.second->Type());
            dest << "\"";

            const std::string_view* private_creator;
            if (attribs->TryGetPrivateCreator(kvp.first, &private_creator)) {
                dest << " privateCreator=\"" << *private_creator << "\"";
            }

            dest << ">";

            switch (kvp.second->Type()) {
            // Handle tags that can contain a single value.
            case VRType::AE: write_single_value_vr(dest, as<AE>(kvp.second)); break;
            case VRType::AS: write_single_value_vr(dest, as<AS>(kvp.second)); break;
            case VRType::DT: write_single_value_vr(dest, as<DT>(kvp.second)); break;
            case VRType::LT: write_single_value_vr(dest, as<LT>(kvp.second)); break;
            case VRType::ST: write_single_value_vr(dest, as<ST>(kvp.second)); break;
            case VRType::UR: write_single_value_vr(dest, as<UR>(kvp.second)); break;
            case VRType::UT: write_single_value_vr(dest, as<UT>(kvp.second)); break;

            // Handle tags that can contain multiple values
            case VRType::AT: write_multi_value_vr(dest, as<AT>(kvp.second)); break;
            case VRType::CS: write_multi_value_vr(dest, as<CS>(kvp.second)); break;
            case VRType::DA: write_multi_value_vr(dest, as<DA>(kvp.second)); break;
            case VRType::DS: write_multi_value_vr(dest, as<DS>(kvp.second)); break;
            case VRType::IS: write_multi_value_vr(dest, as<IS>(kvp.second)); break;
            case VRType::LO: write_multi_value_vr(dest, as<LO>(kvp.second)); break;
            case VRType::SH: write_multi_value_vr(dest, as<SH>(kvp.second)); break;
            case VRType::TM: write_multi_value_vr(dest, as<TM>(kvp.second)); break;
            case VRType::UC: write_multi_value_vr(dest, as<UC>(kvp.second)); break;
            case VRType::UI: write_multi_value_vr(dest, as<UI>(kvp.second)); break;

            // Handle tags that are represented as binary.
            case VRType::FD: write_binary_vr(dest, as<FD>(kvp.second)); break;
            case VRType::FL: write_binary_vr(dest, as<FL>(kvp.second)); break;
            case VRType::OB: write_binary_vr(dest, as<OB>(kvp.second)); break;
            case VRType::OD: write_binary_vr(dest, as<OD>(kvp.second)); break;
            case VRType::OF: write_binary_vr(dest, as<OF>(kvp.second)); break;
            case VRType::OL: write_binary_vr(dest, as<OL>(kvp.second)); break;
            case VRType::OW: write_binary_vr(dest, as<OW>(kvp.second)); break;
            case VRType::SL: write_binary_vr(dest, as<SL>(kvp.second)); break;
            case VRType::SS: write_binary_vr(dest, as<SS>(kvp.second)); break;
            case VRType::UL: write_binary_vr(dest, as<UL>(kvp.second)); break;
            case VRType::UN: write_binary_vr(dest, as<UN>(kvp.second)); break;
            case VRType::US: write_binary_vr(dest, as<US>(kvp.second)); break;

            // Handle PN specifically.
            case VRType::PN:
                write_patient_name_vr(dest, as<PN>(kvp.second));
                break;

            // Handle SQ specifically
            case VRType::SQ:
                write_sq_vr(dest, as<SQ>(kvp.second));
                break;

            case VRType::Deferred: // We should not see Deferred items here.
            default:
                // Unknown VRType. Something very bad has happened.
                continue;
            }

            dest << "</DicomAttribute>";
        }
    }
}

namespace dicom::io::part19 {

    bool Part19Writer::Write(
        std::string filename,
        //const OutputStreamPtr& stream,
        //const TransferSyntax* /*transfer_syntax*/,
        const data::AttributeSetConstPtr& metadata//,
        //WritePixelDataCallback /*write_pixel_data_callback*/
    ) {
        std::ofstream fs{ filename };

        fs << "<NativeDicomModel>";
        write_attribute_set(fs, metadata.get());
        fs << "</NativeDicomModel>";

        return true;
    }

}