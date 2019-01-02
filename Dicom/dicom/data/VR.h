#pragma once

#include "dicom/data/ValidityType.h"
#include "dicom/data/value_empty.h"
#include "dicom/data/value_invalid.h"
#include "dicom/data/VRType.h"

namespace dicom::data {

    class DICOM_EXPORT VR
    {
    public:
        virtual ~VR() = default;

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] VRType Type() const { return m_type; }

        [[nodiscard]] ValidityType Validity() const {
            EnsureValidated();
            return m_validity;
        }

        [[nodiscard]] bool IsValid() const {
            EnsureValidated();
            return (m_validity == ValidityType::Valid || m_validity == ValidityType::Acceptable);
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] virtual int32_t Compare(const VR* other) const;

        [[nodiscard]] virtual bool operator == (const VR* other) const;
        [[nodiscard]] virtual bool operator != (const VR* other) const;
        [[nodiscard]] virtual bool operator <  (const VR* other) const;
        [[nodiscard]] virtual bool operator <= (const VR* other) const;
        [[nodiscard]] virtual bool operator >  (const VR* other) const;
        [[nodiscard]] virtual bool operator >= (const VR* other) const;

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] virtual bool Empty() const = 0;
        [[nodiscard]] virtual std::unique_ptr<VR> Copy() const = 0;

    protected:
        VR(VRType type);
        VR(const VR& other);
        VR(VR&& other);

        VR& operator = (const VR& other);
        VR& operator = (VR&& other);

        //----------------------------------------------------------------------------------------------------

        virtual ValidityType Validate() const = 0;

        void EnsureValidated() const {
            if (m_validity == ValidityType::Uninitialized) {
                m_validity = Validate();
            }
        }

        void AssertValidated() const {
            EnsureValidated();
            if (m_validity != ValidityType::Acceptable && m_validity != ValidityType::Valid) {
                throw value_invalid_error();
            }
        }

        void AssertNotEmpty() const {
            if (Empty()) {
                throw value_empty_error();
            }
        }

    private:
        VRType m_type;
        mutable ValidityType m_validity;
    };

}