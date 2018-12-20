#include "dicom_pch.h"
#include "dicom/data/VR.h"

namespace dicom::data {

    VR::VR(VRType type)
      : m_type(type),
        m_validity(ValidityType::Uninitialized)
    {}

    //--------------------------------------------------------------------------------------------------------

    VR::VR(const VR& other)
      : m_type(other.m_type),
        m_validity(other.m_validity)        
    {}

    //--------------------------------------------------------------------------------------------------------

    VR::VR(VR&& other)
      : m_type(other.m_type),
        m_validity(other.m_validity)
    {
        other.m_validity = ValidityType::Deinitialized;
    }

    //--------------------------------------------------------------------------------------------------------

    VR& VR::operator = (const VR& other) {
        m_validity = other.m_validity;
        m_type = other.m_type;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    VR& VR::operator = (VR&& other) {
        m_validity = other.m_validity;
        m_type = other.m_type;
        other.m_validity = ValidityType::Deinitialized;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t VR::Compare(const VR* other) const { return int32_t(m_type) - int32_t(other->m_type); }

    //--------------------------------------------------------------------------------------------------------

    bool VR::operator == (const VR* other) const { return Compare(other) == 0; }
    bool VR::operator != (const VR* other) const { return Compare(other) != 0; }
    bool VR::operator <  (const VR* other) const { return Compare(other) <  0; }
    bool VR::operator <= (const VR* other) const { return Compare(other) <= 0; }
    bool VR::operator >  (const VR* other) const { return Compare(other) >  0; }
    bool VR::operator >= (const VR* other) const { return Compare(other) >= 0; }
	
}