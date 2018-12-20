#pragma once

#include "dicom/data/detail/StringTrimStrategy.h"

namespace dicom::data::detail {
    
    template <
        typename TString,
        typename T,
        typename TConverter,
        typename TTrimStrategy
    >
    class xstring_iterator
    {
    public: // std::iterator
        using iterator_category = std::input_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T*;
        using reference = T&;


    public:
        xstring_iterator(
            const TString* string,
            const std::vector<size_t>* offsets,
            ptrdiff_t index
        ) : m_string(string),
            m_offsets(offsets),
            m_index(index)
        {}

        //----------------------------------------------------------------------------------------------------

        // Value of iterator
        [[nodiscard]] T operator * () const {
#ifdef _DEBUG
            if (m_index < 0 || m_index > ptrdiff_t(m_offsets->size())) {
                throw std::out_of_range("Iterator index is out of range");
            }
#endif
            
            // Get the start offset
            size_t start_offset = 0;
            if (m_index != 0) { start_offset = (*m_offsets)[m_index - 1] + 1; }

            // Get the end offset
            size_t end_offset = m_string->size();
            if (m_index < ptrdiff_t(m_offsets->size())) { end_offset = (*m_offsets)[m_index]; }

            auto view = GetView(*m_string, start_offset, end_offset);

            // Trim as appropriate
            TTrimStrategy::TrimLeft(view);
            TTrimStrategy::TrimRight(view);

            // Convert the value
            return TConverter::Convert(view);
        }

        //----------------------------------------------------------------------------------------------------

        // Prefix increment
        xstring_iterator& operator ++ () {
            ++m_index;
            return *this;
        }

        //----------------------------------------------------------------------------------------------------

        // Postfix increment
        xstring_iterator operator ++ (int) {
            xstring_iterator _this = *this;
            ++m_index;
            return _this;
        }

        //----------------------------------------------------------------------------------------------------

        // Increment arbitrary distance
        xstring_iterator& operator + (int distance) {
            m_index += distance;
            return *this;
        }

        //----------------------------------------------------------------------------------------------------

        // Comparisons
        [[nodiscard]] bool operator == (const xstring_iterator& other) const { ComparisonAssert(other); return (m_index == other.m_index); }
        [[nodiscard]] bool operator != (const xstring_iterator& other) const { ComparisonAssert(other); return (m_index != other.m_index); }
        [[nodiscard]] bool operator <  (const xstring_iterator& other) const { ComparisonAssert(other); return (m_index <  other.m_index); }
        [[nodiscard]] bool operator <= (const xstring_iterator& other) const { ComparisonAssert(other); return (m_index <= other.m_index); }
        [[nodiscard]] bool operator >  (const xstring_iterator& other) const { ComparisonAssert(other); return (m_index >  other.m_index); }
        [[nodiscard]] bool operator >= (const xstring_iterator& other) const { ComparisonAssert(other); return (m_index >= other.m_index); }

    private:
        const TString* m_string;
        const std::vector<size_t>* m_offsets;
        ptrdiff_t m_index;

        void ComparisonAssert(const xstring_iterator& other) const {
#ifdef _DEBUG
            if (m_string->c_str() != other.m_string->c_str()) {
                throw std::invalid_argument("Iterators are for different strings");
            }
            if (m_offsets != other.m_offsets) {
                throw std::invalid_argument("Iterators have different offsets");
            }
#else
            (void)other;
#endif
        }

        //----------------------------------------------------------------------------------------------------

        template <typename TChar>
        static std::basic_string_view<TChar> GetView(
            const std::basic_string<TChar>& str,
            size_t start_offset,
            size_t end_offset
        ) {
            return std::basic_string_view<TChar>(
                str.data() + start_offset,
                end_offset - start_offset
            );
        }
    };

    //--------------------------------------------------------------------------------------------------------

    template <typename T, typename TConverter, typename TTrimStrategy>
    using string_iterator = xstring_iterator<std::string, T, TConverter, TTrimStrategy>;

    //--------------------------------------------------------------------------------------------------------

    template <typename T>
    struct substring_converter {
        static std::basic_string_view<T> Convert(const std::basic_string_view<T>& view) {
            return view;
        }
    };

    template <typename TTrimStrategy>
    using substring_iterator = string_iterator<std::string_view, substring_converter<char>, TTrimStrategy>;

}