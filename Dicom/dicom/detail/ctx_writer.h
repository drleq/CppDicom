#pragma once

#include "dicom/data/AttributeSet.h"

namespace dicom::detail {

    /** \brief A wrapper providing mutable access to a specific attribute in an \ref AttributeSet.
     *
     * This class acts as a wrapper for an \ref AttributeSet, allowing strongly typed write access to
     * a specific attribute. Unlike \ref elem_writer{T}, this class can be used with attributes where the
     * type is dependent on other information.
     * 
     * \see ctx_reader{T1,T2}
     * \see elem_writer{T}
     * \see sq_writer{T}
     * \see range_writer{T}
     */
    template <typename T1, typename T2>
    class ctx_writer
    {
    public:
        ctx_writer() : m_attribute_set(nullptr), m_tag(-1) {}
        ctx_writer(data::AttributeSet* as, tag_number tag) : m_attribute_set(as), m_tag(tag) {}

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] explicit operator bool () const {
            auto attrib =  m_attribute_set->Get(m_tag);
            return (attrib != nullptr) && (attrib->Validity() != dicom::data::ValidityType::Invalid);
        }

        [[nodiscard]] operator const T1* () const { return m_attribute_set->Get<T1>(m_tag); }
        [[nodiscard]] operator const T2* () const { return m_attribute_set->Get<T2>(m_tag); }

        [[nodiscard]] const T1* First() const { return m_attribute_set->Get<T1>(m_tag); }
        [[nodiscard]] const T2* Second() const { return m_attribute_set->Get<T2>(m_tag); }

        //----------------------------------------------------------------------------------------------------

        ctx_writer<T1, T2>& operator = (T1* new_attribute00) {
            if (new_attribute00 != nullptr) { m_attribute_set->Add(m_tag, new_attribute00); }
            else { m_attribute_set->Remove(m_tag); }
            return *this;
        }

        ctx_writer<T1, T2>& operator = (T2* new_attribute00) {
            if (new_attribute00 != nullptr) { m_attribute_set->Add(m_tag, new_attribute00); }
            else { m_attribute_set->Remove(m_tag); }
            return *this;
        }

        //----------------------------------------------------------------------------------------------------

        void CopyFrom(const data::AttributeSet* other) {
            auto other_vr = other->Get(m_tag);
            if (other_vr) { m_attribute_set->Add(m_tag, other_vr->Copy()); }
        }

    private:
        data::AttributeSet* m_attribute_set;
        tag_number m_tag;
    };

}