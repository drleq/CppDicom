#include "dicom_pch.h"
#include "dicom/data/UR.h"

#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/detail/string_trim.h"

namespace dicom::data {

    UR::UR()
      : UR(std::string())
    {}

    //--------------------------------------------------------------------------------------------------------

    UR::UR(const uri& value)
      : UR(uri(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    UR::UR(uri&& value)
      : VR(VRType::UR),
        m_value(std::forward<uri>(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    UR::UR(const UR& other)
      : VR(other),
        m_value(other.m_value)
    {}

    //--------------------------------------------------------------------------------------------------------

    UR::UR(UR&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}

    //--------------------------------------------------------------------------------------------------------

    UR::~UR() = default;

    //--------------------------------------------------------------------------------------------------------

    UR& UR::operator = (const UR& other) {
        VR::operator = (other);
        m_value = other.m_value;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    UR& UR::operator = (UR&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType UR::Validate() const {
        return m_value.Validity();
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t UR::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const UR*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool UR::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const UR*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool UR::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const UR*>(other);
        return m_value != typed->m_value;
    }

}