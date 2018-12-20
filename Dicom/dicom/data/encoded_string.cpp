#include "dicom_pch.h"
#include "dicom/data/encoded_string.h"

#include "dicom/data/string_converter/StringConverter.h"

using namespace std;

namespace dicom::data {

    string_invalid_error::string_invalid_error()
      : std::runtime_error("String does not match encoding")
    {}

    //--------------------------------------------------------------------------------------------------------

    encoded_string::encoded_string()
      : m_encoding(StringEncodingType::ISO_IEC_646),
        m_validity(ValidityType::Valid)
    {}

    //--------------------------------------------------------------------------------------------------------

    encoded_string::encoded_string(buffer<char>&& value, StringEncodingType encoding)
      : m_value(forward<buffer<char>>(value)),
        m_encoding(encoding)
    {
        string_view buffer_view(m_value, m_value.ByteLength());
        string parsed;
        if (string_converter::convert_to_utf8(encoding, buffer_view, parsed)) {
            m_parsed = move(parsed);
            m_validity = ValidityType::Valid;
        } else {
            m_validity = ValidityType::Invalid;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    encoded_string::encoded_string(const char* utf8_value)
      : encoded_string(string(utf8_value), StringEncodingType::UTF8)
    {}

    //--------------------------------------------------------------------------------------------------------

    encoded_string::encoded_string(const char* utf8_value, StringEncodingType encoding)
      : encoded_string(string(utf8_value), encoding)
    {}

    //--------------------------------------------------------------------------------------------------------

    encoded_string::encoded_string(const string_view& utf8_value)
      : encoded_string(string(utf8_value), StringEncodingType::UTF8)
    {}

    //--------------------------------------------------------------------------------------------------------

    encoded_string::encoded_string(const string_view& utf8_value, StringEncodingType encoding)
      : encoded_string(string(utf8_value), encoding)
    {}

    //--------------------------------------------------------------------------------------------------------

    encoded_string::encoded_string(string&& utf8_value)
      : encoded_string(forward<string>(utf8_value), StringEncodingType::UTF8)
    {}

    //--------------------------------------------------------------------------------------------------------

    encoded_string::encoded_string(string&& utf8_value, StringEncodingType encoding) {
        buffer<char> raw;
        if (string_converter::convert_from_utf8(encoding, utf8_value, raw)) {
            m_value = move(raw);
            m_parsed = forward<string>(utf8_value);
            m_validity = ValidityType::Valid;
        }
        else {
            // m_value is left uninitialized. This is good or bad depending on how you look at it.
            m_validity = ValidityType::Invalid;
        }

        m_encoding = encoding;
    }

    //--------------------------------------------------------------------------------------------------------

    encoded_string::encoded_string(const encoded_string& other)
        : m_value(other.m_value.Copy()),
        m_encoding(other.m_encoding),
        m_parsed(other.m_parsed),
        m_validity(other.m_validity)
    {}

    //--------------------------------------------------------------------------------------------------------

    encoded_string::encoded_string(encoded_string&& other)
        : m_value(move(other.m_value)),
        m_encoding(other.m_encoding),
        m_parsed(move(other.m_parsed)),
        m_validity(other.m_validity)
    {
        other.m_validity = ValidityType::Deinitialized;
    }

    //--------------------------------------------------------------------------------------------------------

    encoded_string::~encoded_string() = default;

    //--------------------------------------------------------------------------------------------------------

    encoded_string& encoded_string::operator = (const encoded_string& other) {
        m_value = other.m_value.Copy();
        m_encoding = other.m_encoding;
        m_parsed = other.m_parsed;
        m_validity = other.m_validity;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    encoded_string& encoded_string::operator = (encoded_string&& other) {
        m_value = move(other.m_value);
        m_encoding = other.m_encoding;
        m_parsed = move(other.m_parsed);
        m_validity = other.m_validity;
        other.m_validity = ValidityType::Deinitialized;
        return *this;
    }

    //--------------------------------------------------------------------------------------------------------

    int encoded_string::Compare(const encoded_string& other) const {
        // If both are valid then compare the parsed values.
        if (m_validity == ValidityType::Valid && other.m_validity == ValidityType::Valid) {
            return m_parsed.compare(other.m_parsed);
        }

        // One of the strings is invalid. They must share the same encoding.
        if (m_encoding != other.m_encoding) {
            return (m_encoding < other.m_encoding) ? -1 : 1;
        }

        // Compare the raw data.
        return m_value.Compare(other.m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool encoded_string::operator == (const encoded_string& other) const {
        if (m_validity != other.m_validity || m_encoding != other.m_encoding) {
            return false;
        }

        return m_value == other.m_value;
    }

    //--------------------------------------------------------------------------------------------------------

    bool encoded_string::operator != (const encoded_string& other) const {
        return !(*this == other);
    }

}