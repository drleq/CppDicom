#include "dicom_pch.h"
#include "dicom/data/OB.h"

namespace dicom::data {

    OB::OB()
      : OB(buffer<int8_t>())
    {}

    //--------------------------------------------------------------------------------------------------------

    OB::OB(const buffer<int8_t>& binary_value)
      : OB(binary_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

	OB::OB(buffer<int8_t>&& binary_value)
	  : VR(VRType::OB),
        m_value(std::forward<buffer<int8_t>>(binary_value))
	{}

    //--------------------------------------------------------------------------------------------------------

    OB::OB(const OB& other)
      : VR(other),
        m_value(other.m_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    OB::OB(OB&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}

	//--------------------------------------------------------------------------------------------------------

    OB::~OB() = default;

    //--------------------------------------------------------------------------------------------------------

    OB& OB::operator = (const OB& other) {
        VR::operator = (other);
        m_value = other.m_value.Copy();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    OB& OB::operator = (OB&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType OB::Validate() const {
        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t OB::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const OB*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool OB::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const OB*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool OB::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const OB*>(other);
        return m_value != typed->m_value;
    }

}