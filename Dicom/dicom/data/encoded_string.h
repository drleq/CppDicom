#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/StringEncodingType.h"
#include "dicom/data/ValidityType.h"

namespace dicom::data {

    class DICOM_EXPORT string_invalid_error : public std::runtime_error
    {
    public:
        string_invalid_error();
    };

    class DICOM_EXPORT encoded_string
    {
    public:
        // Raw constructor
        encoded_string();
        encoded_string(buffer<char>&& value, StringEncodingType encoding);
        encoded_string(
            buffer<char>&& value,
            StringEncodingType encoding,
            bool strip_single_padding_char
        );

        encoded_string(const char* utf8_value);
        encoded_string(const char* utf8_value, StringEncodingType encoding);
        encoded_string(const std::string_view& utf8_value);
        encoded_string(const std::string_view& utf8_value, StringEncodingType encoding);
        encoded_string(std::string&& utf8_value);
        encoded_string(std::string&& utf8_value, StringEncodingType encoding);

        encoded_string(const encoded_string& other);
        encoded_string(encoded_string&& other);

        ~encoded_string();

        //----------------------------------------------------------------------------------------------------

        encoded_string& operator = (const encoded_string& other);
        encoded_string& operator = (encoded_string&& other);

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const { return m_value.Empty(); }
        [[nodiscard]] const buffer<char>& Value() const { return m_value; }
        [[nodiscard]] StringEncodingType Encoding() const { return m_encoding; }
        [[nodiscard]] const std::string& Parsed() const { return m_parsed; }
        [[nodiscard]] ValidityType Validity() const { return m_validity; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const encoded_string& other) const;

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool operator == (const encoded_string& other) const;
        [[nodiscard]] bool operator != (const encoded_string& other) const;

    private:
        buffer<char> m_value;
        StringEncodingType m_encoding;
        std::string m_parsed;
        ValidityType m_validity;
    };

}