#include "dicom_pch.h"
#include "dicom/data/OW.h"

namespace dicom::data {

    OW::OW()
      : OW(buffer<int16_t>())
    {}

    //--------------------------------------------------------------------------------------------------------

    OW::OW(const buffer<int16_t>& binary_value)
      : OW(binary_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

	OW::OW(buffer<int16_t>&& binary_value)
	  : VR(VRType::OW),
        m_value(std::forward<buffer<int16_t>>(binary_value))
	{}

    //--------------------------------------------------------------------------------------------------------

    OW::OW(const OW& other)
      : VR(other),
        m_value(other.m_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    OW::OW(OW&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}
    
	//--------------------------------------------------------------------------------------------------------

    OW::~OW() = default;

    //--------------------------------------------------------------------------------------------------------

    OW& OW::operator = (const OW& other) {
        VR::operator = (other);
        m_value = other.m_value.Copy();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    OW& OW::operator = (OW&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }
    
    //--------------------------------------------------------------------------------------------------------

    ValidityType OW::Validate() const {
        return ValidityType::Valid;
    }
    
    //--------------------------------------------------------------------------------------------------------

    int32_t OW::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const OW*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool OW::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const OW*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool OW::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const OW*>(other);
        return m_value != typed->m_value;
    }

}