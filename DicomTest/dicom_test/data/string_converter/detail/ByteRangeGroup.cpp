#include "dicomtest_pch.h"
#include "dicom_test/data/string_converter/detail/ByteRangeGroup.h"

namespace dicom_test::data::string_converter::detail {

    ByteRangeInfo::ByteRangeInfo(
        uint8_t start,
        uint8_t end,
        ByteRangeGroupPtr next00
    ) : m_start(start),
        m_end(end),
        m_next00(next00)
    {}

    //--------------------------------------------------------------------------------------------------------
    
    bool ByteRangeInfo::CheckInvalidByteSequences(
        const ByteRangeGroupPtr& root_group,
        std::string& seq,
        const StringConverterToUTF8& converter
    ) const {
        seq.resize(seq.size() + 1);
        auto& last_char = seq[seq.size() - 1];

        if (m_next00 == nullptr) {
            // This is the final byte in the sequence. Perform the tests.
            std::string tmp;
            for (uint8_t b = 0; b < m_start; b++) {
                last_char = b;
                if (root_group->IsValidSequence(seq, 0)) {
                    continue;
                }
                if (converter(seq, tmp)) {
                    return false;
                }
            }
            for (uint16_t b = m_end + 1; b <= 0xFF; b++) {
                last_char = uint8_t(b);
                if (root_group->IsValidSequence(seq, 0)) {
                    continue;
                }
                if (converter(seq, tmp)) {
                    return false;
                }
            }
        } else {
            // This isn't the final byte in the sequence. Keep descending.
            for (uint8_t b = 0; b < m_start; b++) {
                last_char = b;
                if (root_group->IsValidSequence(seq, 0)) {
                    continue;
                }
                if (!m_next00->CheckInvalidByteSequences(root_group, seq, converter)) {
                    return false;
                }
            }
            for (uint16_t b = m_end + 1; b <= 0xFF; b++) {
                last_char = uint8_t(b);
                if (root_group->IsValidSequence(seq, 0)) {
                    continue;
                }
                if (!m_next00->CheckInvalidByteSequences(root_group, seq, converter)) {
                    return false;
                }
            }
        }

        seq.resize(seq.size() - 1);
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool ByteRangeInfo::EnumerateValidByteSequences(
        const RangeAssignment& range,
        bool is_first_combination,
        bool is_last_combination,
        std::string& seq,
        uint32_t& unicode_offset,
        const std::function<bool (const std::string&, uint32_t)>& callback
    ) const {
        uint8_t start = m_start;
        uint8_t end   = m_end;
        if (is_first_combination) {
            start = range.StartByteSequence()[seq.size()];
            if (start < m_start || start > m_end) {
                return true;
            }
        }
        if (is_last_combination) {
            end = range.EndByteSequence()[seq.size()];
            if (end < m_start || end > m_end) {
                return true;
            }
        }

        seq.resize(seq.size() + 1);
        auto& last_char = seq[seq.size() - 1];

        if (m_next00 == nullptr) {
            if (seq.size() < range.StartByteSequence().size()) {
                // We don't have enough sequence bytes to check anything.
                seq.resize(seq.size() - 1);
                return true;
            }

            // This is the final byte in the sequence. Perform the enumeration.
            for (uint16_t b = start; b <= end; b++) {
                last_char = uint8_t(b);
                if (!callback(seq, range.StartUnicode() + unicode_offset++)) {
                    return false;
                }
            }
        } else {
            // This isn't the final byte in the sequence. Keep descending.
            for (uint16_t b = start; b <= end; b++) {
                last_char = uint8_t(b);
                auto ok = m_next00->EnumerateValidByteSequences(
                    range,
                    is_first_combination && (b == start),
                    is_last_combination && (b == end),
                    seq,
                    unicode_offset,
                    callback
                );
                if (!ok) { return false; }
            }
        }

        seq.resize(seq.size() - 1);
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool ByteRangeGroup::IsValidSequence(const std::string& seq, size_t offset) const {
        char c = seq[offset];

        for (auto& range : m_ranges) {
            if (range->IsInRange(c)) {
                offset++;

                auto next00 = range->Next00();
                if (next00 != nullptr) {
                    if (offset == seq.size()) { return false; }
                    return next00->IsValidSequence(seq, offset);
                }
                return (offset == seq.size());
            }
        }
        return false;
    }

    //--------------------------------------------------------------------------------------------------------

    bool ByteRangeGroup::CheckInvalidByteSequences(
        const ByteRangeGroupPtr& root_group,
        std::string& seq,
        const StringConverterToUTF8& converter
    ) const {
        for (auto& range : m_ranges) {
            if (!range->CheckInvalidByteSequences(root_group, seq, converter)) {
                return false;
            }
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool ByteRangeGroup::EnumerateValidByteSequences(
        const RangeAssignment& range,
        bool is_first_combination,
        bool is_last_combination,
        std::string& seq,
        uint32_t& unicode_offset,
        const std::function<bool (const std::string&, uint32_t)>& callback
    ) const {
        for (auto& r : m_ranges) {
            auto ok = r->EnumerateValidByteSequences(
                range,
                is_first_combination,
                is_last_combination,
                seq,
                unicode_offset,
                callback
            );
            if (!ok) { return false; }
        }
        return true;
    }

}