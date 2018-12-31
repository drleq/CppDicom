#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/VR.h"

namespace dicom::data {

    class DICOM_EXPORT FD : public VR
    {
    public:
        using value_type = double;
        using buffer_type = buffer<double>;

        //----------------------------------------------------------------------------------------------------

        FD();
        FD(const buffer<double>& binary_value);
        FD(buffer<double>&& binary_value);
        FD(double value);
        FD(const std::vector<double>& values);
        FD(std::initializer_list<double> values);
        FD(const FD& other);
        FD(FD&& other);
        virtual ~FD();

        FD& operator = (const FD& other);
        FD& operator = (FD&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return m_value.Empty(); }
        [[nodiscard]] std::unique_ptr<VR> Copy() const override final { return std::make_unique<FD>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const buffer<double>& Value() const { return m_value; }
        [[nodiscard]] double First() const { return m_value[0]; }
        [[nodiscard]] size_t Length() const { return m_value.Length(); }
        [[nodiscard]] size_t ByteLength() const { return m_value.ByteLength(); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const VR* other) const override final;

        [[nodiscard]] bool operator == (const VR* other) const override final;
        [[nodiscard]] bool operator != (const VR* other) const override final;

    protected:
        ValidityType Validate() const override final;
		
    private:
        buffer<double> m_value;
    };

}