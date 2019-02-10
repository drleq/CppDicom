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

    std::ostream& operator << (std::ostream& dest, dicom::data::VRType vr_type) {
        dest.write(
            reinterpret_cast<const char*>(&vr_type),
            2
        );
        return dest;
    }
    
    //--------------------------------------------------------------------------------------------------------
    
    std::ostream& operator << (std::ostream& dest, const std::string& str) {
        // TODO: Escape XML characters.
        dest.write(str.data(), str.size());
        return dest;
    }

    //--------------------------------------------------------------------------------------------------------

    template <typename T>
    std::ostream& operator << (std::ostream& dest, const dicom::data::buffer<T>& /*binary*/) {
        // TODO: Base64 encoding of binary data.
        return dest;
    }

    //--------------------------------------------------------------------------------------------------------

    std::ostream& operator << (std::ostream& dest, const dicom::data::uri& value) {
        dest << value.Value();
        return dest;
    }

    //--------------------------------------------------------------------------------------------------------

    std::ostream& operator << (std::ostream& dest, const dicom::data::date& value) {
        // YYYYMMDD
        dest << std::dec << std::setw(4) << std::setfill('0') << value.Year();
        dest << std::dec << std::setw(2) << std::setfill('0') << static_cast<int>(value.Month());
        dest << std::dec << std::setw(2) << std::setfill('0') << static_cast<int>(value.Day());
        return dest;
    }

    //--------------------------------------------------------------------------------------------------------

    std::ostream& operator << (std::ostream& dest, const dicom::data::time& value) {
        //hhmmss.ffffff
        dest << std::dec << std::setw(2) << std::setfill('0') << static_cast<int>(value.Hour());
        dest << std::dec << std::setw(2) << std::setfill('0') << static_cast<int>(value.Minute());
        dest << std::dec << std::setw(2) << std::setfill('0') << static_cast<int>(value.Second());
        dest << ".";
        dest << std::dec << std::setw(6) << std::setfill('0') << value.Millisecond();
        return dest;
    }

    //--------------------------------------------------------------------------------------------------------

    std::ostream& operator << (std::ostream& dest, const dicom::data::encoded_string& value) {
        if (value.Validity() == ValidityType::Valid) {
            dest << value.Parsed();
        } else {
            // TODO: Decide what to do here.
        }
        return dest;
    }

    //--------------------------------------------------------------------------------------------------------

    template <typename T>
    bool write_single_value_vr(std::ostream& dest, const T* vr) {
        dest << "<Value number=\"1\">" << vr->Value() << "</Value>";
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    template <typename T>
    bool write_multi_value_vr(std::ostream& dest, const T* vr) {
        int number = 1;
        for (auto value : *vr) {
            dest << "<Value number=\"" << number << "\">" << value << "</Value>";
        }
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool write_component_group(std::ostream& dest, const char* name, const dicom::data::ComponentGroup& value) {
        if (value.Empty()) {
            return true;
        }

        dest << "<" << name << ">";

        if (!value.FamilyName().empty()) {
            dest << "<FamilyName>" << value.FamilyName() << "</FamilyName>";
        }
        if (!value.GivenName().empty()) {
            dest << "<GivenName>" << value.GivenName() << "</GivenName>";
        }
        if (!value.MiddleName().empty()) {
            dest << "<MiddleName>" << value.MiddleName() << "</MiddleName>";
        }
        if (!value.Prefix().empty()) {
            dest << "<NamePrefix>" << value.Prefix() << "</NamePrefix>";
        }
        if (!value.Suffix().empty()) {
            dest << "<NameSuffix>" << value.Suffix() << "</NameSuffix>";
        }

        dest << "</" << name << ">";
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool write_patient_name_vr(std::ostream& dest, const PN* vr) {
        int number = 1;
        for (auto value : *vr) {
            dest << "<PatientName number=\"" << number << "\">";

            write_component_group(dest, "Alphabetic", value.Alphabetic());
            write_component_group(dest, "Ideographic", value.Ideographic());
            write_component_group(dest, "Phonetic", value.Phonetic());

            dest << "</PatientName>";
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool write_attribute_set(std::ostream& dest, const dicom::data::AttributeSetConstPtr& attribs) {
        for (auto& kvp : *attribs) {
            dest << "<DicomAttribute";

            // keyword?
            
            uint16_t group = dicom::get_tag_group(kvp.first);
            uint16_t element = dicom::get_tag_element(kvp.first);
            dest << " tag=\""
                << std::hex << std::setw(4) << std::setfill('0') << group
                << std::hex << std::setw(4) << std::setfill('0') << element 
                << "\"";

            dest << " vr=\"" << kvp.second->Type() << "\"";

            const std::string_view* private_creator;
            if (attribs->TryGetPrivateCreator(kvp.first, &private_creator)) {
                dest << "privateCreator=\"" << *private_creator << "\"";
            }

            dest << ">";

            switch (kvp.second->Type()) {
            // Handle tags that are represented by the Default Character Repertoire.
            case VRType::AE: write_single_value_vr(dest, as<AE>(kvp.second)); break;
            case VRType::AS: write_single_value_vr(dest, as<AS>(kvp.second)); break;
            case VRType::CS: write_multi_value_vr(dest, as<CS>(kvp.second)); break;
            case VRType::DA: write_multi_value_vr(dest, as<DA>(kvp.second)); break;
            case VRType::DS: write_multi_value_vr(dest, as<DS>(kvp.second)); break;
            case VRType::DT: write_single_value_vr(dest, as<DT>(kvp.second)); break;
            case VRType::IS: write_multi_value_vr(dest, as<IS>(kvp.second)); break;
            case VRType::TM: write_multi_value_vr(dest, as<TM>(kvp.second)); break;
            case VRType::UI: write_multi_value_vr(dest, as<UI>(kvp.second)); break;
            case VRType::UR: write_single_value_vr(dest, as<UR>(kvp.second)); break;

            // Handle tags that are represented by Unicode.
            case VRType::LO: write_multi_value_vr(dest, as<LO>(kvp.second)); break;
            case VRType::LT: write_single_value_vr(dest, as<LT>(kvp.second)); break;
            case VRType::PN: write_patient_name_vr(dest, as<PN>(kvp.second)); break;
            case VRType::SH: write_multi_value_vr(dest, as<SH>(kvp.second)); break;
            case VRType::ST: write_single_value_vr(dest, as<ST>(kvp.second)); break;
            case VRType::UC: write_multi_value_vr(dest, as<UC>(kvp.second)); break;
            case VRType::UT: write_single_value_vr(dest, as<UT>(kvp.second)); break;

            // Handle tags that are represented as binary.
            case VRType::FD: dest << as<FD>(kvp.second)->Value(); break;
            case VRType::FL: dest << as<FL>(kvp.second)->Value(); break;
            case VRType::OB: dest << as<OB>(kvp.second)->Value(); break;
            case VRType::OD: dest << as<OD>(kvp.second)->Value(); break;
            case VRType::OF: dest << as<OF>(kvp.second)->Value(); break;
            case VRType::OL: dest << as<OL>(kvp.second)->Value(); break;
            case VRType::OW: dest << as<OW>(kvp.second)->Value(); break;
            case VRType::SL: dest << as<SL>(kvp.second)->Value(); break;
            case VRType::SS: dest << as<SS>(kvp.second)->Value(); break;
            case VRType::UL: dest << as<UL>(kvp.second)->Value(); break;
            case VRType::UN: dest << as<UN>(kvp.second)->Value(); break;
            case VRType::US: dest << as<US>(kvp.second)->Value(); break;

            // Handle AT specifically
            case VRType::AT:
                write_multi_value_vr(dest, as<AT>(kvp.second));
                break;

            // Handle SQ specifically
            //case VRType::SQ: write_sq(ctx, as<SQ>(kvp.second), false); break;

            case VRType::Deferred: // We should not see Deferred items here.
            default:
                // Unknown VRType. Something very bad has happened.
                return false;
            }

            dest << "</DicomAttribute>";
        }

        return true;
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
        //std::ostringstream ss;
        fs << "<NativeDicomModel>";

        if (!write_attribute_set(fs, metadata)) {
            return false;
        }

        fs << "</NativeDicomModel>";
        
        return true;
    }

}