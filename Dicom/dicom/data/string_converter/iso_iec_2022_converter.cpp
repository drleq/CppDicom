#include "dicom_pch.h"
#include "dicom/data/string_converter/iso_iec_2022_converter.h"

#include "dicom/data/string_converter/iso_iec_646_converter.h"
#include "dicom/data/string_converter/iso_iec_8859_1_converter.h"
#include "dicom/data/string_converter/iso_iec_8859_2_converter.h"
#include "dicom/data/string_converter/iso_iec_8859_3_converter.h"
#include "dicom/data/string_converter/iso_iec_8859_4_converter.h"
#include "dicom/data/string_converter/iso_iec_8859_5_converter.h"
#include "dicom/data/string_converter/iso_iec_8859_6_converter.h"
#include "dicom/data/string_converter/iso_iec_8859_7_converter.h"
#include "dicom/data/string_converter/iso_iec_8859_8_converter.h"
#include "dicom/data/string_converter/iso_iec_8859_9_converter.h"
#include "dicom/data/string_converter/jis_x_0201_converter.h"
#include "dicom/data/string_converter/jis_x_0208_converter.h"
#include "dicom/data/string_converter/jis_x_0212_converter.h"
#include "dicom/data/string_converter/ks_x_1001_converter.h"
#include "dicom/data/string_converter/tis_620_2533_converter.h"
#include "dicom/data/string_converter/gb18030_converter.h" // For GB2312

using namespace dicom::data;
using namespace std;

namespace {
    using namespace dicom::data::string_converter;

    //--------------------------------------------------------------------------------------------------------

    const map<StringEncodingType, const char*> s_extension_sequences = {
        { StringEncodingType::CodeExtension_ISO_IEC_646,    "\x1B\x28\x42" },
        { StringEncodingType::CodeExtension_ISO_IEC_8859_1, "\x1B\x2D\x41" },
        { StringEncodingType::CodeExtension_ISO_IEC_8859_2, "\x1B\x2D\x42" },
        { StringEncodingType::CodeExtension_ISO_IEC_8859_3, "\x1B\x2D\x43" },
        { StringEncodingType::CodeExtension_ISO_IEC_8859_4, "\x1B\x2D\x44" },
        { StringEncodingType::CodeExtension_ISO_IEC_8859_5, "\x1B\x2D\x4C" },
        { StringEncodingType::CodeExtension_ISO_IEC_8859_6, "\x1B\x2D\x47" },
        { StringEncodingType::CodeExtension_ISO_IEC_8859_7, "\x1B\x2D\x46" },
        { StringEncodingType::CodeExtension_ISO_IEC_8859_8, "\x1B\x2D\x48" },
        { StringEncodingType::CodeExtension_ISO_IEC_8859_9, "\x1B\x2D\x4D" },
        { StringEncodingType::CodeExtension_JIS_X_0201,     "\x1B\x29\x49" },
        { StringEncodingType::CodeExtension_JIS_X_0208,     "\x1B\x24\x42" },
        { StringEncodingType::CodeExtension_TIS_620_2533,   "\x1B\x2D\x54" },
        { StringEncodingType::CodeExtension_JIS_X_0212,     "\x1B\x24\x28\x44" },
        { StringEncodingType::CodeExtension_KS_X_1001,      "\x1B\x24\x29\x43" },
        { StringEncodingType::CodeExtension_GB_2312,        "\x1B\x24\x29\x41" }
    };

    //--------------------------------------------------------------------------------------------------------

    using Converter = bool (*)(const string_view&, string&);

    // Most escape sequences are only two bytes long.
    const map<uint16_t, Converter> s_two_byte_converters {
        // DICOM
        { static_cast<uint16_t>(0x4228), iso_iec_646_to_utf8 },    // ASCII
        { static_cast<uint16_t>(0x412D), iso_iec_8859_1_to_utf8 }, // Latin-1
        { static_cast<uint16_t>(0x422D), iso_iec_8859_2_to_utf8 }, // Latin-2
        { static_cast<uint16_t>(0x432D), iso_iec_8859_3_to_utf8 }, // Latin-3
        { static_cast<uint16_t>(0x442D), iso_iec_8859_4_to_utf8 }, // Latin-4
        { static_cast<uint16_t>(0x4C2D), iso_iec_8859_5_to_utf8 }, // Cyrillic
        { static_cast<uint16_t>(0x472D), iso_iec_8859_6_to_utf8 }, // Arabic
        { static_cast<uint16_t>(0x462D), iso_iec_8859_7_to_utf8 }, // Greek
        { static_cast<uint16_t>(0x482D), iso_iec_8859_8_to_utf8 }, // Hebrew
        { static_cast<uint16_t>(0x4D2D), iso_iec_8859_9_to_utf8 }, // Latin-5 (Turkish)
        { static_cast<uint16_t>(0x4929), jis_x_0201_to_utf8 },     // Japanese (Romaji + Katakana)
        { static_cast<uint16_t>(0x4224), jis_x_0208_to_utf8 },     // Japanese (Kanji)
        { static_cast<uint16_t>(0x542D), tis_620_2533_to_utf8 },   // Thai

        // ISO-2022-JP
        //{ static_cast<uint16_t>(0x4228), iso_iec_646_to_utf8 },    // ASCII
        { static_cast<uint16_t>(0x4A28), jis_x_0201_to_utf8 },     // Japanese (Romaji + Katakana)
        { static_cast<uint16_t>(0x4024), jis_x_0208_to_utf8 },     // Japanese (Kanji)
        //{ static_cast<uint16_t>(0x4224), jis_x_0208_to_utf8 },     // Japanese (Kanji)

        // ISO-2022-JP-2
        { static_cast<uint16_t>(0x412E), iso_iec_8859_1_to_utf8 }, // Latin-1
        { static_cast<uint16_t>(0x462E), iso_iec_8859_7_to_utf8 }, // Greek

        // ISO-2022-JP-3
        { static_cast<uint16_t>(0x4928), jis_x_0201_to_utf8 }      // Japanese (Romaji + Katakana)
    };

    const map<uint16_t, Converter> s_three_byte_converters {
        // ISO-2022-JP-1
        { static_cast<uint16_t>(0x4428), jis_x_0212_to_utf8 },     // Japanese (Kanji supp.)

        // ISO-2022-JP-2
        { static_cast<uint16_t>(0x4328), ks_x_1001_to_utf8 },      // Korean (Hangul + Hanja)

        // ISO-2022-KR
        { static_cast<uint16_t>(0x4329), ks_x_1001_to_utf8 },      // Korean (Hangul + Hanja)

        // ISO-2022-CN
        { static_cast<uint16_t>(0x4129), gb_2312_to_utf8 }         // Chinese
    };

    //--------------------------------------------------------------------------------------------------------

    const map<uint16_t, StringEncodingType> s_two_byte_string_encodings = {
        // DICOM
        { static_cast<uint16_t>(0x4228), StringEncodingType::CodeExtension_ISO_IEC_646 },    // ASCII
        { static_cast<uint16_t>(0x412D), StringEncodingType::CodeExtension_ISO_IEC_8859_1 }, // Latin-1
        { static_cast<uint16_t>(0x422D), StringEncodingType::CodeExtension_ISO_IEC_8859_2 }, // Latin-2
        { static_cast<uint16_t>(0x432D), StringEncodingType::CodeExtension_ISO_IEC_8859_3 }, // Latin-3
        { static_cast<uint16_t>(0x442D), StringEncodingType::CodeExtension_ISO_IEC_8859_4 }, // Latin-4
        { static_cast<uint16_t>(0x4C2D), StringEncodingType::CodeExtension_ISO_IEC_8859_5 }, // Cyrillic
        { static_cast<uint16_t>(0x472D), StringEncodingType::CodeExtension_ISO_IEC_8859_6 }, // Arabic
        { static_cast<uint16_t>(0x462D), StringEncodingType::CodeExtension_ISO_IEC_8859_7 }, // Greek
        { static_cast<uint16_t>(0x482D), StringEncodingType::CodeExtension_ISO_IEC_8859_8 }, // Hebrew
        { static_cast<uint16_t>(0x4D2D), StringEncodingType::CodeExtension_ISO_IEC_8859_9 }, // Latin-5 (Turkish)
        { static_cast<uint16_t>(0x4929), StringEncodingType::CodeExtension_JIS_X_0201 },     // Japanese (Romaji + Katakana)
        { static_cast<uint16_t>(0x4224), StringEncodingType::CodeExtension_JIS_X_0208 },     // Japanese (Kanji)
        { static_cast<uint16_t>(0x542D), StringEncodingType::CodeExtension_TIS_620_2533 },   // Thai

        // ISO-2022-JP
        //{ static_cast<uint16_t>(0x4228), StringEncodingType::CodeExtension_ISO_IEC_646},    // ASCII
        { static_cast<uint16_t>(0x4A28), StringEncodingType::CodeExtension_JIS_X_0201 },     // Japanese (Romaji + Katakana)
        { static_cast<uint16_t>(0x4024), StringEncodingType::CodeExtension_JIS_X_0208 },     // Japanese (Kanji)
        //{ static_cast<uint16_t>(0x4224), StringEncodingType::CodeExtension_JIS_X_0208},     // Japanese (Kanji)

        // ISO-2022-JP-2
        { static_cast<uint16_t>(0x412E), StringEncodingType::CodeExtension_ISO_IEC_8859_1 }, // Latin-1
        { static_cast<uint16_t>(0x462E), StringEncodingType::CodeExtension_ISO_IEC_8859_7 }, // Greek

        // ISO-2022-JP-3
        { static_cast<uint16_t>(0x4928), StringEncodingType::CodeExtension_JIS_X_0201 }      // Japanese (Romaji + Katakana)
    };

    const map<uint16_t, StringEncodingType> s_three_byte_string_encodings = {
        // ISO-2022-JP-1
        { static_cast<uint16_t>(0x4428), StringEncodingType::CodeExtension_JIS_X_0212 },     // Japanese (Kanji supp.)

        // ISO-2022-JP-2
        { static_cast<uint16_t>(0x4328), StringEncodingType::CodeExtension_KS_X_1001 },      // Korean (Hangul + Hanja)

        // ISO-2022-KR
        { static_cast<uint16_t>(0x4329), StringEncodingType::CodeExtension_KS_X_1001 },      // Korean (Hangul + Hanja)

        // ISO-2022-CN
        { static_cast<uint16_t>(0x4129), StringEncodingType::CodeExtension_GB_2312 }         // Chinese
    };

    //--------------------------------------------------------------------------------------------------------

    Converter get_initial_decoder(StringEncodingType string_encoding) {
        switch (string_encoding) {
        case StringEncodingType::CodeExtension_ISO_IEC_646:    return iso_iec_646_to_utf8;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_1: return iso_iec_8859_1_to_utf8;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_2: return iso_iec_8859_2_to_utf8;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_3: return iso_iec_8859_3_to_utf8;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_4: return iso_iec_8859_4_to_utf8;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_5: return iso_iec_8859_5_to_utf8;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_6: return iso_iec_8859_6_to_utf8;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_7: return iso_iec_8859_7_to_utf8;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_8: return iso_iec_8859_8_to_utf8;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_9: return iso_iec_8859_9_to_utf8;
        case StringEncodingType::CodeExtension_JIS_X_0201:     return jis_x_0201_to_utf8;
        case StringEncodingType::CodeExtension_JIS_X_0208:     return jis_x_0208_to_utf8;
        case StringEncodingType::CodeExtension_JIS_X_0212:     return jis_x_0212_to_utf8;
        case StringEncodingType::CodeExtension_TIS_620_2533:   return tis_620_2533_to_utf8;
        case StringEncodingType::CodeExtension_KS_X_1001:      return ks_x_1001_to_utf8;
        case StringEncodingType::CodeExtension_GB_2312:        return gb_2312_to_utf8;
        default:
            // Unknown string encoding. Nothing we can do.
            return nullptr;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    Converter get_initial_encoder(StringEncodingType string_encoding) {
        switch (string_encoding) {
        case StringEncodingType::CodeExtension_ISO_IEC_646:    return utf8_to_iso_iec_646;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_1: return utf8_to_iso_iec_8859_1;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_2: return utf8_to_iso_iec_8859_2;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_3: return utf8_to_iso_iec_8859_3;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_4: return utf8_to_iso_iec_8859_4;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_5: return utf8_to_iso_iec_8859_5;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_6: return utf8_to_iso_iec_8859_6;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_7: return utf8_to_iso_iec_8859_7;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_8: return utf8_to_iso_iec_8859_8;
        case StringEncodingType::CodeExtension_ISO_IEC_8859_9: return utf8_to_iso_iec_8859_9;
        case StringEncodingType::CodeExtension_JIS_X_0201:     return utf8_to_jis_x_0201;
        case StringEncodingType::CodeExtension_JIS_X_0208:     return utf8_to_jis_x_0208;
        case StringEncodingType::CodeExtension_JIS_X_0212:     return utf8_to_jis_x_0212;
        case StringEncodingType::CodeExtension_TIS_620_2533:   return utf8_to_tis_620_2533;
        case StringEncodingType::CodeExtension_KS_X_1001:      return utf8_to_ks_x_1001;
        case StringEncodingType::CodeExtension_GB_2312:        return utf8_to_gb_2312;
        default:
            // Unknown string encoding. Nothing we can do.
            return nullptr;
        }
    }
}

namespace dicom::data::string_converter {

    bool iso_iec_2022_to_utf8(
        const string_view& encoded_source,
        string& utf8_dest,
        StringEncodingType string_encoding
    ) {
        // ISO/IEC 2022 is a meta character set, using escape sequences to switch between different
        // character mappings. In DICOM, the initial character mapping is defined by the SpecificCharacterSet
        // attribute but can switch to others at any point in the string.
        Converter decoder = get_initial_decoder(string_encoding);

        // We have no idea how many characters [dest] will contain when we're done. However, it will
        // often be less than the count of input bytes we are provided with. We can shrink the allocation
        // afterwards.
        utf8_dest.reserve(encoded_source.size());

        auto s_ptr = encoded_source.data();
        auto s_end = encoded_source.data() + encoded_source.size();
        while (s_ptr < s_end) {
            // Find the next ESC character and convert the range
            auto next_escape = find(s_ptr, s_end, 0x1B);
            if (next_escape != s_ptr) {
                string sub_str;
                bool ok = decoder(string_view(s_ptr, distance(s_ptr, next_escape)), sub_str);
                if (!ok) { return false; }
                utf8_dest += sub_str;
            }

            if (next_escape == s_end) { break; }
            s_ptr = next_escape + 1;

            // Check for a two byte escape sequence
            auto escape_sequence = *reinterpret_cast<const uint16_t*>(s_ptr);
            auto it = s_two_byte_converters.find(escape_sequence);
            if (it != s_two_byte_converters.end()) {
                decoder = it->second;
                s_ptr += 2;
                continue;
            }

            // Check for a three byte escape sequence
            if (s_ptr[0] == 0x24) {
                escape_sequence = *reinterpret_cast<const uint16_t*>(s_ptr+1);
                it = s_three_byte_converters.find(escape_sequence);
                if (it != s_three_byte_converters.end()) {
                    decoder = it->second;
                    s_ptr += 3;
                    continue;
                }
            }

            // We have failed to match the escape sequence and cannot safely decode the string.
            return false;
        }

        // Reduce the capacity to the number of code points actually used
        utf8_dest.resize(utf8_dest.size());
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool utf8_to_iso_iec_2022(
        const string_view& utf8_source,
        std::string& encoded_dest,
        StringEncodingType string_encoding
    ) {
        // A character in UTF-8 can map map to multiple possible character mappings. While it is possible to
        // accurately encode the string through trial and error there are no guarantees on efficiency, either
        // in encoding speed or the space required for the encoded form. Because of this we should attempt to
        // encode only with the initial encoder.
        Converter encoder = get_initial_encoder(string_encoding);
        return encoder(utf8_source, encoded_dest);
    }

    //--------------------------------------------------------------------------------------------------------

    bool get_code_extension_bytes(
        StringEncodingType string_encoding,
        std::string_view* extension_bytes
    ) {
        auto it = s_extension_sequences.find(string_encoding);
        if (it == s_extension_sequences.end()) { return false; }

        *extension_bytes = std::string_view(
            it->second,
            strlen(it->second)
        );
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool extract_string_encodings(
        const string_view& string,
        set<StringEncodingType>& string_encodings
    ) {
        auto s_ptr = string.data();
        auto s_end = string.data() + string.size();
        while (s_ptr < s_end) {
            // Find the next ESC character
            auto next_escape = find(s_ptr, s_end, 0x1B);
            if (next_escape == s_end) { break; }
            s_ptr = next_escape + 1;

            // Check for a two byte escape sequence
            auto escape_sequence = *reinterpret_cast<const uint16_t*>(s_ptr);
            auto it = s_two_byte_string_encodings.find(escape_sequence);
            if (it != s_two_byte_string_encodings.end()) {
                string_encodings.insert(it->second);
                s_ptr += 2;
                continue;
            }

            // Check for a three byte escape sequence
            if (s_ptr[0] == 0x24) {
                escape_sequence = *reinterpret_cast<const uint16_t*>(s_ptr+1);
                it = s_three_byte_string_encodings.find(escape_sequence);
                if (it != s_three_byte_string_encodings.end()) {
                    string_encodings.insert(it->second);
                    s_ptr += 3;
                    continue;
                }
            }

            // We have failed to match the escape sequence and cannot safely decode the string.
            return false;
        }

        return true;
    }

}