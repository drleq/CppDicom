#include "dicomtest_pch.h"
#include "dicom_test/data/string_converter/detail/RangeAssignment.h"

namespace dicom_test::data::string_converter::detail {

    RangeAssignment::RangeAssignment(
        const std::string& start_byte_sequence,
        const std::string& end_byte_sequence,
        uint32_t start_unicode,
        uint32_t end_unicode
    ) : m_start_byte_sequence(start_byte_sequence),
        m_end_byte_sequence(end_byte_sequence),
        m_start_unicode(start_unicode),
        m_end_unicode(end_unicode)
    {}

}