#include "dicom_pch.h"
#include "dicom/data/UN.h"

namespace dicom::data {

    UN::UN()
      : UN(buffer<int8_t>())
    {}

    //--------------------------------------------------------------------------------------------------------

    UN::UN(const buffer<int8_t>& binary_value)
      : UN(binary_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

	UN::UN(buffer<int8_t>&& binary_value)
	  : VR(VRType::UN),
        m_value(std::forward<buffer<int8_t>>(binary_value))
	{}

    //--------------------------------------------------------------------------------------------------------

    UN::UN(const UN& other)
      : VR(other),
        m_value(other.m_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    UN::UN(UN&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}

	//--------------------------------------------------------------------------------------------------------

	UN::~UN() = default;

    //--------------------------------------------------------------------------------------------------------

    UN& UN::operator = (const UN& other) {
        VR::operator = (other);
        m_value = other.m_value.Copy();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    UN& UN::operator = (UN&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType UN::Validate() const {
        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t UN::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const UN*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool UN::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const UN*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool UN::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const UN*>(other);
        return m_value != typed->m_value;
    }

}