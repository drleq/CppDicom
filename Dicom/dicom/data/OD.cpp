#include "dicom_pch.h"
#include "dicom/data/OD.h"

namespace dicom::data {

    OD::OD()
      : OD(buffer<double>())
    {}

    //--------------------------------------------------------------------------------------------------------

    OD::OD(const buffer<double>& binary_value)
      : OD(binary_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

	OD::OD(buffer<double>&& binary_value)
	  : VR(VRType::OD),
        m_value(std::forward<buffer<double>>(binary_value))
	{}

    //--------------------------------------------------------------------------------------------------------

    OD::OD(const OD& other)
      : VR(other),
        m_value(other.m_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    OD::OD(OD&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}

	//--------------------------------------------------------------------------------------------------------

    OD::~OD() = default;

    //--------------------------------------------------------------------------------------------------------

    OD& OD::operator = (const OD& other) {
        VR::operator = (other);
        m_value = other.m_value.Copy();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    OD& OD::operator = (OD&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType OD::Validate() const {
        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t OD::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const OD*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool OD::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const OD*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool OD::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const OD*>(other);
        return m_value != typed->m_value;
    }

}