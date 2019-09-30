#include "dicom_pch.h"
#include "dicom/data/SV.h"

namespace dicom::data {

    SV::SV()
      : SV(buffer<int64_t>())
    {}

    //--------------------------------------------------------------------------------------------------------

    SV::SV(const buffer<int64_t>& binary_value)
      : SV(binary_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    SV::SV(buffer<int64_t>&& binary_value)
      : VR(VRType::SV),
        m_value(std::forward<buffer<int64_t>>(binary_value))
    {}

    //--------------------------------------------------------------------------------------------------------

    SV::SV(int64_t value)
      : VR(VRType::SV),
        m_value(1)
    {
        m_value[0] = value;
    }

    //--------------------------------------------------------------------------------------------------------

    SV::SV(const std::vector<int64_t>& values)
      : VR(VRType::SV),
        m_value(values.size())
    {
        if (!values.empty()) {
            memcpy(m_value, &values[0], m_value.ByteLength());
        }
    }

    //--------------------------------------------------------------------------------------------------------

    SV::SV(std::initializer_list<int64_t> values)
      : VR(VRType::SV),
        m_value(values.size())
    {
        if (values.size() != 0) {
            memcpy(m_value, values.begin(), m_value.ByteLength());
        }
    }

    //--------------------------------------------------------------------------------------------------------

    SV::SV(const SV& other)
      : VR(other),
        m_value(other.m_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    SV::SV(SV&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}

	//--------------------------------------------------------------------------------------------------------

    SV::~SV() = default;

    //--------------------------------------------------------------------------------------------------------

    SV& SV::operator = (const SV& other) {
        VR::operator = (other);
        m_value = other.m_value.Copy();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    SV& SV::operator = (SV&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType SV::Validate() const {
        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t SV::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const SV*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool SV::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const SV*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool SV::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const SV*>(other);
        return m_value != typed->m_value;
    }

}