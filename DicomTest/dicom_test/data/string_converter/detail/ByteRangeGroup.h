#pragma once

#include "dicom_test/data/string_converter/detail/RangeAssignment.h"

namespace dicom_test::data::string_converter::detail {

    class ByteRangeGroup;
    using ByteRangeGroupPtr = std::shared_ptr<ByteRangeGroup>;

    using StringConverterToUTF8 = std::function<bool (const std::string_view&, std::string&)>;
    using StringConverterFromUTF8 = std::function<bool (const std::string_view&, std::string&)>;

    // A single range of values for a single byte in a byte sequence
    class ByteRangeInfo
    {
    public:
        ByteRangeInfo(
            uint8_t start,
            uint8_t end,
            ByteRangeGroupPtr next00 = nullptr
        );

        bool IsInRange(char c) const { return (uint8_t(c) >= m_start && uint8_t(c) <= m_end); }
        const ByteRangeGroupPtr& Next00() const { return m_next00; }

        bool CheckInvalidByteSequences(
            const ByteRangeGroupPtr& root_group,
            std::string& seq,
            const StringConverterToUTF8& converter
        ) const;

        bool EnumerateValidByteSequences(
            const RangeAssignment& range,
            bool is_first_combination,
            bool is_last_combination,
            std::string& seq,
            uint32_t& unicode_offset,
            const std::function<bool (const std::string&, uint32_t)>& callback
        ) const;
        
    private:
        uint8_t m_start;
        uint8_t m_end;
        ByteRangeGroupPtr m_next00;
    };

    using ByteRangeInfoPtr = std::shared_ptr<ByteRangeInfo>;

    // A group of ranges for a single byte in the byte sequence
    class ByteRangeGroup
    {
    public:
        void Add(uint8_t start, uint8_t end, ByteRangeGroupPtr next00 = nullptr) {
            m_ranges.emplace_back(ByteRangeInfoPtr(new ByteRangeInfo(start, end, next00)));
        }

        bool IsValidSequence(const std::string& seq, size_t offset) const;

        bool CheckInvalidByteSequences(
            const ByteRangeGroupPtr& root_group,
            std::string& seq,
            const StringConverterToUTF8& converter
        ) const;

        bool EnumerateValidByteSequences(
            const RangeAssignment& range,
            bool is_first_combination,
            bool is_last_combination,
            std::string& seq,
            uint32_t& unicode_offset,
            const std::function<bool (const std::string&, uint32_t)>& callback
        ) const;

    private:
        std::vector<ByteRangeInfoPtr> m_ranges;
    };

}