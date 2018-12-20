#pragma once

#include "dicom/data/AttributeSet.h"

namespace dicom::detail {

    /** \brief A wrapper providing read-only access to a specific attribute in an \ref AttributeSet.
     *
     * This class acts as a wrapper for an \ref AttributeSet, allowing strongly typed read-only access to
     * a specific attribute. Unlike \ref elem_reader{T}, this class can be used with attributes where the
     * type is dependent on other information.
     * 
     * \see ctx_writer{T1,T2}
     * \see elem_reader{T}
     * \see sq_reader{T}
     * \see range_reader{T}
     */
    template <typename T1, typename T2>
    class ctx_reader
    {
    public:
        ctx_reader() : m_attribute_set(nullptr), m_tag(-1) {}
        ctx_reader(const data::AttributeSet* as, tag_number tag) : m_attribute_set(as), m_tag(tag) {}

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] explicit operator bool () const {
            auto attrib =  m_attribute_set->Get(m_tag);
            return (attrib != nullptr) && (attrib->Validity() != dicom::data::ValidityType::Invalid);
        }

        [[nodiscard]] operator const T1* () const { return m_attribute_set->Get<T1>(m_tag); }
        [[nodiscard]] operator const T2* () const { return m_attribute_set->Get<T2>(m_tag); }

        [[nodiscard]] const T1* First() const { return m_attribute_set->Get<T1>(m_tag); }
        [[nodiscard]] const T2* Second() const { return m_attribute_set->Get<T2>(m_tag); }

    private:
        const data::AttributeSet* m_attribute_set;
        tag_number m_tag;
    };

}