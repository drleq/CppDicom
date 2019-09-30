#include "dicom_pch.h"
#include "dicom/data/OV.h"

namespace dicom::data {

    OV::OV()
      : OV(buffer<int64_t>())
    {}

    //--------------------------------------------------------------------------------------------------------

    OV::OV(const buffer<int64_t>& binary_value)
      : OV(binary_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    OV::OV(buffer<int64_t>&& binary_value)
	  : VR(VRType::OV),
        m_value(std::forward<buffer<int64_t>>(binary_value))
	{}

    //--------------------------------------------------------------------------------------------------------

    OV::OV(const OV& other)
      : VR(other),
        m_value(other.m_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    OV::OV(OV&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}
    
	//--------------------------------------------------------------------------------------------------------

    OV::~OV() = default;

    //--------------------------------------------------------------------------------------------------------

    OV& OV::operator = (const OV& other) {
        VR::operator = (other);
        m_value = other.m_value.Copy();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    OV& OV::operator = (OV&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }
    
    //--------------------------------------------------------------------------------------------------------

    ValidityType OV::Validate() const {
        return ValidityType::Valid;
    }
    
    //--------------------------------------------------------------------------------------------------------

    int32_t OV::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const OV*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool OV::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const OV*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool OV::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const OV*>(other);
        return m_value != typed->m_value;
    }

}