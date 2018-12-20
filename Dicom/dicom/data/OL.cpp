#include "dicom_pch.h"
#include "dicom/data/OL.h"

namespace dicom::data {

    OL::OL()
      : OL(buffer<int32_t>())
    {}

    //--------------------------------------------------------------------------------------------------------

    OL::OL(const buffer<int32_t>& binary_value)
      : OL(binary_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    OL::OL(buffer<int32_t>&& binary_value)
	  : VR(VRType::OL),
        m_value(std::forward<buffer<int32_t>>(binary_value))
	{}

    //--------------------------------------------------------------------------------------------------------

    OL::OL(const OL& other)
      : VR(other),
        m_value(other.m_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    OL::OL(OL&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}
    
	//--------------------------------------------------------------------------------------------------------

    OL::~OL() = default;

    //--------------------------------------------------------------------------------------------------------

    OL& OL::operator = (const OL& other) {
        VR::operator = (other);
        m_value = other.m_value.Copy();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    OL& OL::operator = (OL&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }
    
    //--------------------------------------------------------------------------------------------------------

    ValidityType OL::Validate() const {
        return ValidityType::Valid;
    }
    
    //--------------------------------------------------------------------------------------------------------

    int32_t OL::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const OL*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool OL::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const OL*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool OL::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const OL*>(other);
        return m_value != typed->m_value;
    }

}