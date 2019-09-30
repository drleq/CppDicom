#include "dicom_pch.h"
#include "dicom/data/UV.h"

namespace dicom::data {

    UV::UV()
      : UV(buffer<uint64_t>())
    {}

    //--------------------------------------------------------------------------------------------------------

    UV::UV(const buffer<uint64_t>& binary_value)
      : UV(binary_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    UV::UV(buffer<uint64_t>&& binary_value)
      : VR(VRType::UV),
        m_value(std::forward<buffer<uint64_t>>(binary_value))
    {}

    //--------------------------------------------------------------------------------------------------------

    UV::UV(uint64_t value)
      : VR(VRType::UV),
        m_value(1)
    {
        m_value[0] = value;
    }

    //--------------------------------------------------------------------------------------------------------

    UV::UV(const std::vector<uint64_t>& values)
      : VR(VRType::UV),
        m_value(values.size())
    {
        if (!values.empty()) {
            memcpy(m_value, &values[0], m_value.ByteLength());
        }
    }

    //--------------------------------------------------------------------------------------------------------

    UV::UV(std::initializer_list<uint64_t> values)
      : VR(VRType::UV),
        m_value(values.size())
    {
        if (values.size() > 0) {
            memcpy(m_value, values.begin(), m_value.ByteLength());
        }
    }

    //--------------------------------------------------------------------------------------------------------

    UV::UV(const UV& other)
      : VR(other),
        m_value(other.m_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    UV::UV(UV&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}

	//--------------------------------------------------------------------------------------------------------

	UV::~UV() = default;

    //--------------------------------------------------------------------------------------------------------

    UV& UV::operator = (const UV& other) {
        VR::operator = (other);
        m_value = other.m_value.Copy();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    UV& UV::operator = (UV&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType UV::Validate() const {
        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t UV::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const UV*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool UV::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const UV*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool UV::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const UV*>(other);
        return m_value != typed->m_value;
    }

}