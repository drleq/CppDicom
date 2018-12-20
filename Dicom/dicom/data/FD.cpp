#include "dicom_pch.h"
#include "dicom/data/FD.h"

namespace dicom::data {

    FD::FD()
      : FD(buffer<double>())
    {}

    //--------------------------------------------------------------------------------------------------------

    FD::FD(const buffer<double>& binary_value)
      : FD(binary_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    FD::FD(buffer<double>&& binary_value)
      : VR(VRType::FD),
        m_value(std::forward<buffer<double>>(binary_value))
    {}

    //--------------------------------------------------------------------------------------------------------

    FD::FD(double value)
      : VR(VRType::FD),
        m_value(1)
    {
        *m_value = value;
    }

    //--------------------------------------------------------------------------------------------------------

    FD::FD(const std::vector<double>& values)
      : VR(VRType::FD),
        m_value(values.size())
    {
        if (!values.empty()) {
            memcpy(m_value, &values[0], m_value.ByteLength());
        }
    }

    //--------------------------------------------------------------------------------------------------------

    FD::FD(std::initializer_list<double> values)
      : VR(VRType::FD),
        m_value(values.size())
    {
        if (values.size() != 0) {
            double* ptr = m_value;
            for (auto it = values.begin(); it != values.end(); ++it, ++ptr) {
                *ptr = *it;
            }
        }
    }

    //--------------------------------------------------------------------------------------------------------

    FD::FD(const FD& other)
      : VR(other),
        m_value(other.m_value.Copy())
    {}

    //--------------------------------------------------------------------------------------------------------

    FD::FD(FD&& other)
      : VR(std::forward<VR>(other)),
        m_value(std::move(other.m_value))
    {}

	//--------------------------------------------------------------------------------------------------------

	FD::~FD() = default;

    //--------------------------------------------------------------------------------------------------------

    FD& FD::operator = (const FD& other) {
        VR::operator = (other);
        m_value = other.m_value.Copy();
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    FD& FD::operator = (FD&& other) {
        VR::operator = (std::forward<VR>(other));
        m_value = std::move(other.m_value);
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    ValidityType FD::Validate() const {
        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t FD::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const FD*>(other);
        return m_value.Compare(typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool FD::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const FD*>(other);
        return m_value == typed->m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool FD::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const FD*>(other);
        return m_value != typed->m_value;
    }

}