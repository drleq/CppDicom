#include "dicom_pch.h"
#include "dicom/data/detail/combine_strings.h"

#include "dicom/data/detail/DefaultCharacterRepertoire.h"
#include "dicom/data/encoded_string.h"
#include "dicom/data/string_converter/iso_iec_2022_converter.h" // for get_code_extension_bytes()

using namespace std;
using namespace dicom::data;
using namespace dicom::data::detail;

namespace {

    struct temp_buffer
    {
        temp_buffer(size_t initial_size)
          : m_buffer(initial_size),
            m_bytes_remaining(initial_size)
        {}

        void Append(const buffer<char>& buf) {
            Append(buf, buf.ByteLength());
        }

        void Append(const std::string_view& data) {
            Append(data.data(), data.size());
        }

        void Append(const char* data, size_t length) {
            if (m_bytes_remaining < length) {
                size_t old_size = m_buffer.ByteLength();
                size_t new_size = m_buffer.ByteLength() + max<size_t>(length, 4096);

                buffer<char> new_buffer(new_size);
                memcpy(new_buffer, m_buffer, old_size);
                m_buffer = move(new_buffer);
                m_bytes_remaining += (new_size - old_size);
            }

            memcpy(
                m_buffer + m_buffer.ByteLength() - m_bytes_remaining,
                data,
                length
            );
            m_bytes_remaining -= length;
        }

        [[nodiscard]] buffer<char>&& Trim() {
            if (m_bytes_remaining != 0) {
                size_t new_size = m_buffer.ByteLength() - m_bytes_remaining;
                buffer<char> new_buffer(new_size);
                memcpy(new_buffer, m_buffer, new_size);
                m_buffer = move(new_buffer);
            }

            return move(m_buffer);
        }

    private:
        buffer<char> m_buffer;
        size_t m_bytes_remaining;
    };

    //--------------------------------------------------------------------------------------------------------

    // Join unencoded strings with MutliplicityChar.
    template <typename Iter>
    void combine_strings_internal(Iter begin, Iter end, string* dest) {
        if (begin == end) {
            *dest = string();
            return;
        }

        // Compute the combined length of the value string
        size_t value_length = 0;
        for (auto it = begin; it != end; ++it) {
            value_length += it->size() + 1;
        }
        --value_length;

        // Construct the combined value
        string tmp;
        tmp.reserve(value_length);
        for (auto it = begin; it != end; ++it) {
            tmp += *it;
            if (tmp.size() < value_length) {
                tmp += MultiplicityChar;
            }
        }

        *dest = move(tmp);
    }

    //--------------------------------------------------------------------------------------------------------

    // Join encoded strings without code extensions using MultiplicityChar
    template <typename Iter>
    [[nodiscard]] bool combine_encoded_strings_internal_basic(
        Iter begin, Iter end,
        char separator_character,
        StringEncodingType dest_encoding,
        encoded_string* dest
    ) {
        // Estimate the overall length of [dest]
        size_t estimated_length = 0;
        for (auto it = begin; it != end; ++it) {
            estimated_length += it->Value().ByteLength() + 1;
        }
        --estimated_length;

        // Create the temporary buffer
        temp_buffer tmp(estimated_length);

        for (auto it = begin; it != end;) {
            if (it->Encoding() == dest_encoding) {
                // Encoding matches. Just write out the value regardless of validity.
                tmp.Append(it->Value());
            } else {
                // Conversion required.
                if (it->Validity() != ValidityType::Valid) { return false; }

                encoded_string recoded(it->Parsed(), dest_encoding);
                if (recoded.Validity() != ValidityType::Valid) { return false; }

                tmp.Append(recoded.Value());
            }
            
            ++it;
            if (it != end) {
                tmp.Append(&separator_character, 1);
            }
        }

        *dest = encoded_string(tmp.Trim(), dest_encoding);
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    // Join encoded strings with code extensions using MultiplicityChar
    template <typename Iter>
    [[nodiscard]] bool combine_encoded_strings_internal_code_extensions(
        Iter begin, Iter end,
        char separator_character,
        StringEncodingType dest_encoding,
        encoded_string* dest
    ) {
        // Escape to ASCII
        std::string_view default_extension;
        if (!string_converter::get_code_extension_bytes(StringEncodingType::CodeExtension_ISO_IEC_646, &default_extension)) {
            return false;
        }

        // Escape to [target_encoding]
        std::string_view dest_extension;
        if (!string_converter::get_code_extension_bytes(dest_encoding, &dest_extension)) {
            return false;
        }

        // Estimate the overall length of [dest]
        size_t delimiter_length = default_extension.size() + 1 + dest_extension.size();
        size_t estimated_length = 0;
        for (auto it = begin; it != end; ++it) {
            estimated_length += it->Value().ByteLength() + delimiter_length;
        }
        estimated_length -= delimiter_length;

        // Create the temporary buffer
        temp_buffer tmp(estimated_length);

        for (auto it = begin; it != end;) {
            // Always escape the value (even the first one) for maximum compatability with decoders.
            tmp.Append(dest_extension);
            tmp.Append(it->Value());
            
            ++it;
            if (it != end) {
                // Escape to ASCII to write the MultiplicityChar
                tmp.Append(default_extension);
                tmp.Append(&separator_character, 1);
            }
        }

        *dest = encoded_string(tmp.Trim(), dest_encoding);
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    template <typename Iter>
    [[nodiscard]] bool combine_encoded_strings_internal(
        Iter begin, Iter end,
        char separator_character,
        encoded_string* dest
    ) {
        if (begin == end) {
            *dest = encoded_string();
            return true;
        }

        StringEncodingType target_encoding = begin->Encoding();
        bool consistent_encoding = all_of(
            begin,
            end,
            [&](const encoded_string& str) { return str.Encoding() == target_encoding; }
        );
        if (!consistent_encoding) {
            // We have multiple different encodings in the string. Switch to UTF-8 for simplicity.
            target_encoding = StringEncodingType::UTF8;
        }


        switch (target_encoding) {
        case StringEncodingType::ISO_IEC_646:
        case StringEncodingType::ISO_IEC_8859_1:
        case StringEncodingType::ISO_IEC_8859_2:
        case StringEncodingType::ISO_IEC_8859_3:
        case StringEncodingType::ISO_IEC_8859_4:
        case StringEncodingType::ISO_IEC_8859_5:
        case StringEncodingType::ISO_IEC_8859_6:
        case StringEncodingType::ISO_IEC_8859_7:
        case StringEncodingType::ISO_IEC_8859_8:
        case StringEncodingType::ISO_IEC_8859_9:
        case StringEncodingType::JIS_X_0201:
        case StringEncodingType::TIS_620_2533:
        case StringEncodingType::UTF8:
        case StringEncodingType::GB_18030:
        case StringEncodingType::GBK:
        case StringEncodingType::GB_2312:
            return combine_encoded_strings_internal_basic(begin, end, separator_character, target_encoding, dest);

        case StringEncodingType::CodeExtension_ISO_IEC_646:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_1:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_2:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_3:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_4:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_5:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_6:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_7:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_8:
        case StringEncodingType::CodeExtension_ISO_IEC_8859_9:
        case StringEncodingType::CodeExtension_JIS_X_0201:
        case StringEncodingType::CodeExtension_TIS_620_2533:
        case StringEncodingType::CodeExtension_JIS_X_0208:
        case StringEncodingType::CodeExtension_JIS_X_0212:
        case StringEncodingType::CodeExtension_KS_X_1001:
        case StringEncodingType::CodeExtension_GB_2312:
            return combine_encoded_strings_internal_code_extensions(begin, end, separator_character, target_encoding, dest);

        case StringEncodingType::Unknown:
        default:
            return false;
        }
    }
}

namespace dicom::data::detail {

    void combine_strings(const vector<string>& parts, string* dest) {
        combine_strings_internal(parts.begin(), parts.end(), dest);
    }

    //--------------------------------------------------------------------------------------------------------

    void combine_strings(initializer_list<string> parts, string* dest) {
        combine_strings_internal(parts.begin(), parts.end(), dest);
    }

    //--------------------------------------------------------------------------------------------------------

    void combine_strings(const vector<string_view>& parts, string* dest) {
        combine_strings_internal(parts.begin(), parts.end(), dest);
    }

    //--------------------------------------------------------------------------------------------------------

    void combine_strings(initializer_list<string_view> parts, string* dest) {
        combine_strings_internal(parts.begin(), parts.end(), dest);
    }

    //--------------------------------------------------------------------------------------------------------

    bool combine_strings(const vector<encoded_string>& parts, encoded_string* dest) {
        return combine_encoded_strings_internal(
            parts.begin(), parts.end(),
            MultiplicityChar,
            dest
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool combine_strings(initializer_list<encoded_string> parts, encoded_string* dest) {
        return combine_encoded_strings_internal(
            parts.begin(), parts.end(),
            MultiplicityChar,
            dest
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool combine_strings(const vector<encoded_string>& parts, char separator_character, encoded_string* dest) {
        return combine_encoded_strings_internal(
            parts.begin(), parts.end(),
            separator_character,
            dest
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool combine_strings(initializer_list<encoded_string> parts, char separator_character, encoded_string* dest) {
        return combine_encoded_strings_internal(
            parts.begin(), parts.end(),
            separator_character,
            dest
        );
    }

}