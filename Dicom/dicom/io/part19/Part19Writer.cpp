#include "dicom_pch.h"
#include "dicom/io/part19/Part19Writer.h"

#include "dicom/data/VRType.h"

#include "pugixml/pugixml.hpp"
#include <iomanip>
#include <sstream>

namespace {
    std::string format_tag_number(dicom::tag_number tag) {
        uint16_t group = dicom::get_tag_group(tag);
        uint16_t element = dicom::get_tag_element(tag);

        std::ostringstream ss;
        ss << std::hex << std::setw(4) << std::setfill('0');
        ss << group << element;
        return ss.str();
    }

    //--------------------------------------------------------------------------------------------------------

    const char* format_vr_type(dicom::data::VRType vr_type) {
        return reinterpret_cast<const char*>(vr_type);
    }

    //--------------------------------------------------------------------------------------------------------

    bool write_attribute_set(pugi::xml_node& node, const dicom::data::AttributeSetConstPtr& as) {
        for (auto& kvp : *as) {
            auto vr_type = kvp.second->Type();

            auto child = node.append_child("DicomAttribute");
            // keyword?
            child.append_attribute("tag").set_value(format_tag_number(kvp.first).c_str());
            child.append_attribute("vr").set_value(format_vr_type(vr_type));

            const std::string_view* private_creator;
            if (as->TryGetPrivateCreator(kvp.first, &private_creator)) {
                child.append_attribute("privateCreator").set_value(private_creator->data());
            }

            //switch (vr_type) {
                // Do stuff to encode value
            //}
        }

        return true;
    }
}

namespace dicom::io::part19 {

    bool Part19Writer::Write(
        //const OutputStreamPtr& stream,
        const TransferSyntax* /*transfer_syntax*/,
        const data::AttributeSetConstPtr& metadata,
        WritePixelDataCallback /*write_pixel_data_callback*/
    ) {
        pugi::xml_document doc;
        auto root = doc.append_child("NativeDicomModel");

        if (!write_attribute_set(root, metadata)) {
            return false;
        }
        
        return true;
    }

}