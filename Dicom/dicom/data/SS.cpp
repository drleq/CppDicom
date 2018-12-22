#include "dicom_pch.h"
#include "dicom/data/SS.h"

namespace dicom::data {

    SS::SS()
      : SS(buffer<int16_t>())
    {}

    //--------------------------------------------------------------------------------------------------------

    SS::SS(const buffer<int16_t>& binary_value)
      : SS(binary_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    SS::SS(buffer<int16_t>&& binary_value)
      : VR(VRType::SS),
        m_value(std::forward<buffer<int16_t>>(binary_value))
    {}

    //--------------------------------------------------------------------------------------------------------

    SS::SS(int16_t value)
      : VR(VRType::SS),
        m_value(1)
    {
        m_value[0] = value;
    }

    //--------------------------------------------------------------------------------------------------------

    SS::SS(const std::vector<int16_t>& values) 
      : VR(VRType::SS),
        m_value(values.size())
    {
        if (!values.empty()) {
            memcpy(m_value, &values[0], m_value.ByteLength());
        }
    }

    //--------------------------------------------------------------------------------------------------------

    SS::SS(std::initializer_list<int16_t> values)
      : VR(VRType::SS),
        m_value(values.size())
    {
        if (values.size() != 0) {
            memcpy(m_value, values.begin(), m_value.ByteLength());
        }
    }

    //--------------------------------------------------------------------------------------------------------

    SS::SS(const SS& other)
      : VR(other),
        m_value(other.m_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    SS::SS(SS&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}

	//--------------------------------------------------------------------------------------------------------

    SS::~SS() = default;

    //--------------------------------------------------------------------------------------------------------

    SS& SS::operator = (const SS& other) {
        VR::operator = (other);
        m_value = other.m_value.Copy();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    SS& SS::operator = (SS&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType SS::Validate() const {
        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t SS::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const SS*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool SS::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const SS*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool SS::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const SS*>(other);
        return m_value != typed->m_value;
    }

}