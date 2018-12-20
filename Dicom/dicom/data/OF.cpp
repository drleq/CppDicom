#include "dicom_pch.h"
#include "dicom/data/OF.h"

namespace dicom::data {

    OF::OF()
      : OF(buffer<float>())
    {}

    //--------------------------------------------------------------------------------------------------------

    OF::OF(const buffer<float>& binary_value)
      : OF(binary_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

	OF::OF(buffer<float>&& binary_value)
	  : VR(VRType::OF),
        m_value(std::forward<buffer<float>>(binary_value))
	{}

    //--------------------------------------------------------------------------------------------------------

    OF::OF(const OF& other)
      : VR(other),
        m_value(other.m_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    OF::OF(OF&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}

	//--------------------------------------------------------------------------------------------------------

    OF::~OF() = default;

    //--------------------------------------------------------------------------------------------------------

    OF& OF::operator = (const OF& other) {
        VR::operator = (other);
        m_value = other.m_value.Copy();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    OF& OF::operator = (OF&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType OF::Validate() const {
        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t OF::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const OF*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool OF::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const OF*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool OF::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const OF*>(other);
        return m_value != typed->m_value;
    }

}