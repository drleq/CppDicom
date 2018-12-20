#pragma once

#include "dicom/data/AttributeSet.h"

namespace dicom::detail {

    /** \brief A wrapper providing mutable access to a specific attribute in an \ref AttributeSet.
     *
     * This class acts as a wrapper for an \ref AttributeSet, allowing strongly typed write access to
     * a specific attribute.
     * 
     * \see elem_reader{T}
     * \see ctx_writer{T1,T2}
     * \see sq_writer{T}
     * \see range_writer{T}
     */
    template <typename T>
    class elem_writer
    {
    public:
        elem_writer() : m_attribute_set(nullptr), m_tag(-1) {}
        elem_writer(data::AttributeSet* as, tag_number tag) : m_attribute_set(as), m_tag(tag) {}

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] explicit operator bool () const {
            auto attrib = m_attribute_set->Get(m_tag);
            return (attrib != nullptr) && (attrib->Validity() != dicom::data::ValidityType::Invalid);
        }
        
        [[nodiscard]] operator const T* () const { return m_attribute_set->Get<T>(m_tag); }
        [[nodiscard]] const T* operator -> () const { return m_attribute_set->Get<T>(m_tag); }

        //----------------------------------------------------------------------------------------------------

        elem_writer<T>& operator = (T* new_attribute00) {
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