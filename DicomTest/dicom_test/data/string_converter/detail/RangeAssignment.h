#pragma once

namespace dicom_test::data::string_converter::detail {

    class RangeAssignment
    {
    public:
        RangeAssignment(
            const std::string& start_byte_sequence,
            const std::string& end_byte_sequence,
            uint32_t start_unicode,
            uint32_t end_unicode
        );

        const std::string& StartByteSequence() const { return m_start_byte_sequence; }
        const std::string& EndByteSequence() const { return m_end_byte_sequence; }
        uint32_t StartUnicode() const { return m_start_unicode; }
        uint32_t EndUnicode() const { return m_end_unicode; }

    private:
        std::string m_start_byte_sequence;
        std::string m_end_byte_sequence;
        uint32_t m_start_unicode;
        uint32_t m_end_unicode;
    };

}