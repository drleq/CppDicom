#include "dicom_pch.h"
#include "dicom/data/SL.h"

namespace dicom::data {

    SL::SL()
      : SL(buffer<int32_t>())
    {}

    //--------------------------------------------------------------------------------------------------------

    SL::SL(const buffer<int32_t>& binary_value)
      : SL(binary_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    SL::SL(buffer<int32_t>&& binary_value)
      : VR(VRType::SL),
        m_value(std::forward<buffer<int32_t>>(binary_value))
    {}

    //--------------------------------------------------------------------------------------------------------

    SL::SL(int32_t value)
      : VR(VRType::SL),
        m_value(1)
    {
        m_value[0] = value;
    }

    //--------------------------------------------------------------------------------------------------------

    SL::SL(const std::vector<int32_t>& values)
      : VR(VRType::SL),
        m_value(values.size())
    {
        if (!values.empty()) {
            memcpy(m_value, &values[0], m_value.ByteLength());
        }
    }

    //--------------------------------------------------------------------------------------------------------

    SL::SL(std::initializer_list<int32_t> values)
      : VR(VRType::SL),
        m_value(values.size())
    {
        if (values.size() != 0) {
            int32_t* ptr = m_value;
            for (auto it = values.begin(); it != values.end(); ++it, ++ptr) {
                *ptr = *it;
            }
        }
    }

    //--------------------------------------------------------------------------------------------------------

    SL::SL(const SL& other)
      : VR(other),
        m_value(other.m_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    SL::SL(SL&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}

	//--------------------------------------------------------------------------------------------------------

    SL::~SL() = default;

    //--------------------------------------------------------------------------------------------------------

    SL& SL::operator = (const SL& other) {
        VR::operator = (other);
        m_value = other.m_value.Copy();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    SL& SL::operator = (SL&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType SL::Validate() const {
        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t SL::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const SL*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool SL::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const SL*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool SL::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const SL*>(other);
        return m_value != typed->m_value;
    }

}