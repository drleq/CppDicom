#include "dicom_pch.h"
#include "dicom/data/FL.h"

namespace dicom::data {

    FL::FL()
      : FL(buffer<float>())
    {}

    //--------------------------------------------------------------------------------------------------------

    FL::FL(const buffer<float>& binary_value)
      : FL(binary_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    FL::FL(buffer<float>&& binary_value)
      : VR(VRType::FL),
        m_value(std::forward<buffer<float>>(binary_value))
    {}

    //--------------------------------------------------------------------------------------------------------

    FL::FL(float value)
      : VR(VRType::FL),
        m_value(1)
    {
        *m_value = value;
    }

    //--------------------------------------------------------------------------------------------------------

    FL::FL(const std::vector<float>& values)
      : VR(VRType::FL),
        m_value(values.size())
    {
        if (!values.empty()) {
            memcpy(m_value, &values[0], m_value.ByteLength());
        }
    }

    //--------------------------------------------------------------------------------------------------------

    FL::FL(std::initializer_list<float> values)
      : VR(VRType::FL),
        m_value(values.size())
    {
        if (values.size() != 0) {
            float* ptr = m_value;
            for (auto it = values.begin(); it != values.end(); ++it, ++ptr) {
                *ptr = *it;
            }
        }
    }

    //--------------------------------------------------------------------------------------------------------

    FL::FL(const FL& other)
      : VR(other),
        m_value(other.m_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    FL::FL(FL&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}

	//--------------------------------------------------------------------------------------------------------

    FL::~FL() = default;

    //--------------------------------------------------------------------------------------------------------

    FL& FL::operator = (const FL& other) {
        VR::operator = (other);
        m_value = other.m_value.Copy();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    FL& FL::operator = (FL&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType FL::Validate() const {
        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t FL::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const FL*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool FL::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const FL*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool FL::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const FL*>(other);
        return m_value != typed->m_value;
    }

}