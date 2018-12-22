#include "dicom_pch.h"
#include "dicom/data/UL.h"

namespace dicom::data {

    UL::UL()
      : UL(buffer<uint32_t>())
    {}

    //--------------------------------------------------------------------------------------------------------

    UL::UL(const buffer<uint32_t>& binary_value)
      : UL(binary_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    UL::UL(buffer<uint32_t>&& binary_value)
      : VR(VRType::UL),
        m_value(std::forward<buffer<uint32_t>>(binary_value))
    {}

    //--------------------------------------------------------------------------------------------------------

    UL::UL(uint32_t value)
      : VR(VRType::UL),
        m_value(1)
    {
        m_value[0] = value;
    }

    //--------------------------------------------------------------------------------------------------------

    UL::UL(const std::vector<uint32_t>& values)
      : VR(VRType::UL),
        m_value(values.size())
    {
        if (!values.empty()) {
            memcpy(m_value, &values[0], m_value.ByteLength());
        }
    }

    //--------------------------------------------------------------------------------------------------------

    UL::UL(std::initializer_list<uint32_t> values)
      : VR(VRType::UL),
        m_value(values.size())
    {
        if (values.size() > 0) {
            memcpy(m_value, values.begin(), m_value.ByteLength());
        }
    }

    //--------------------------------------------------------------------------------------------------------

    UL::UL(const UL& other)
      : VR(other),
        m_value(other.m_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    UL::UL(UL&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}

	//--------------------------------------------------------------------------------------------------------

	UL::~UL() = default;

    //--------------------------------------------------------------------------------------------------------

    UL& UL::operator = (const UL& other) {
        VR::operator = (other);
        m_value = other.m_value.Copy();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    UL& UL::operator = (UL&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType UL::Validate() const {
        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t UL::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const UL*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool UL::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const UL*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool UL::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const UL*>(other);
        return m_value != typed->m_value;
    }

}