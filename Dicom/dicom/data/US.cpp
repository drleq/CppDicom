#include "dicom_pch.h"
#include "dicom/data/US.h"

namespace dicom::data {

    US::US()
      : US(buffer<uint16_t>())
    {}

    //--------------------------------------------------------------------------------------------------------

    US::US(const buffer<uint16_t>& binary_value)
      : US(binary_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    US::US(buffer<uint16_t>&& binary_value)
      : VR(VRType::US),
        m_value(std::forward<buffer<uint16_t>>(binary_value))
    {}
    
    //--------------------------------------------------------------------------------------------------------

    US::US(uint16_t value)
      : VR(VRType::US),
        m_value(1)
    {
        *m_value = value;
    }

    //--------------------------------------------------------------------------------------------------------

    US::US(const std::vector<uint16_t>& values)
      : VR(VRType::US),
        m_value(values.size())
    {
        if (!values.empty()) {
            memcpy(m_value, &values[0], m_value.ByteLength());
        }
    }

    //--------------------------------------------------------------------------------------------------------

    US::US(std::initializer_list<uint16_t> values)
      : VR(VRType::US),
        m_value(values.size())
    {
        if (values.size() != 0) {
            uint16_t* ptr = m_value;
            for (auto it = values.begin(); it != values.end(); ++it, ++ptr) {
                *ptr = *it;
            }
        }
    }

    //--------------------------------------------------------------------------------------------------------

    US::US(const US& other)
      : VR(other),
        m_value(other.m_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    US::US(US&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}

	//--------------------------------------------------------------------------------------------------------

	US::~US() = default;

    //--------------------------------------------------------------------------------------------------------

    US& US::operator = (const US& other) {
        VR::operator = (other);
        m_value = other.m_value.Copy();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    US& US::operator = (US&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType US::Validate() const {
        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t US::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const US*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool US::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const US*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool US::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const US*>(other);
        return m_value != typed->m_value;
    }

}