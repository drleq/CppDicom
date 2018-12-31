#pragma once

#include "dicom/tag.h"
#include "dicom/private_tag.h"

namespace dicom {

    class DICOM_EXPORT DataDictionary
    {
    public:
        DataDictionary();
        ~DataDictionary();

        //----------------------------------------------------------------------------------------------------

        void Add(const tag* info) {
            m_basic_tags.emplace(info->Number, info);
        }

        //----------------------------------------------------------------------------------------------------

        void Add(const range_tag* range_info) {
            auto high_nibble = uint8_t(range_info->RangeMin >> 28);
            m_range_tags[high_nibble].push_back(range_info);
        }

        //----------------------------------------------------------------------------------------------------

        void Add(const private_tag* private_info) {
            auto& map = m_private_creators[private_info->CreatorName()];
            int32_t _tag = make_tag_number(private_info->Group(), tag_element(private_info->Element));
            map.emplace(_tag, private_info);
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] std::optional<tag> Get(tag_number _tag) const;
        [[nodiscard]] const private_tag* Get(const std::string_view& creator_name, tag_number _tag) const;

    private:
        std::unordered_map<tag_number, const tag*> m_basic_tags;
        std::unordered_map<uint8_t, std::vector<const range_tag*>> m_range_tags;

        using private_group_element_map = std::map<tag_number, const private_tag*>;
        using private_creator_map = std::map<std::string_view, private_group_element_map>;
        private_creator_map m_private_creators;
    };

    using DataDictionaryPtr = std::shared_ptr<DataDictionary>;

}
