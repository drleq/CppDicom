#include "dicom_pch.h"
#include "dicom/data/AT.h"

namespace dicom::data {

    AT::AT()
      : VR(VRType::AT)
    {}

    //--------------------------------------------------------------------------------------------------------

    AT::AT(tag_number value)
      : VR(VRType::AT),
        m_values(1, value)
    {}

    //--------------------------------------------------------------------------------------------------------

    AT::AT(tag_group group, tag_element element)
      : AT(make_tag_number(group, element))
    {}

    //--------------------------------------------------------------------------------------------------------

    AT::AT(const container_type& values)
      : VR(VRType::AT),
        m_values(values)
    {}

    //--------------------------------------------------------------------------------------------------------

    AT::AT(container_type&& values)
      : VR(VRType::AT),
        m_values(std::forward<container_type>(values))
    {}

    //--------------------------------------------------------------------------------------------------------

	AT::AT(std::initializer_list<tag_number> values)
	  : VR(VRType::AT),
		m_values(values)
	{}

	//--------------------------------------------------------------------------------------------------------

    AT::AT(const AT& other) = default;
    AT::AT(AT&& other) = default;

    AT& AT::operator = (const AT& other) = default;
    AT& AT::operator = (AT&& other) = default;

    //--------------------------------------------------------------------------------------------------------

    AT::~AT() = default;

    //--------------------------------------------------------------------------------------------------------

    ValidityType AT::Validate() const {
        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t AT::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const AT*>(other);
        auto length = m_values.size();
        auto other_length = typed->m_values.size();

        auto cmp_len = std::min(length, other_length);
        for (size_t i = 0; i < cmp_len; i++) {
            tag_number tag = m_values[i];
            tag_number other_tag = typed->m_values[i];
            if (tag == other_tag) { continue; }
            return (tag < other_tag) ? -1 : 1;
        }

        if (length < other_length) { return -1; }
        return (length == other_length) ? 0 : 1;
    }

}