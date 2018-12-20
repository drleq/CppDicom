#include "dicom_pch.h"
#include "dicom/DataDictionary.h"

using namespace std;
using namespace dicom::data;

namespace dicom {

    DataDictionary::DataDictionary() = default;

    //--------------------------------------------------------------------------------------------------------

    DataDictionary::~DataDictionary() = default;

    //--------------------------------------------------------------------------------------------------------
    
    optional<tag> DataDictionary::Get(tag_number _tag) const {
        if (is_private_tag(_tag)) { return nullopt; }

        auto it = m_basic_tags.find(_tag);
        if (it != m_basic_tags.end()) { return *it->second; }

        auto high_nibble = uint8_t(_tag >> 28);
        auto it2 = m_range_tags.find(high_nibble);
        if (it2 != m_range_tags.end()) {
            for (auto range : it2->second) {
                auto tag00 = range->FromNumber(_tag);
                if (tag00) { return tag00; }
            }
        }

        return nullopt;
    }

    //--------------------------------------------------------------------------------------------------------

    const private_tag* DataDictionary::Get(const std::string_view& creator_name, tag_number _tag) const {
        auto map_it = m_private_creators.find(creator_name);
        if (map_it == m_private_creators.end()) { return nullptr; }

        tag_number zero_group_tag = (_tag & 0xFFFF00FF);
        auto it = map_it->second.find(zero_group_tag);
        if (it != map_it->second.end()) {
            return it->second;
        }

        return nullptr;
    }

}
