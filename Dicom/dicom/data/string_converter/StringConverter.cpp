#include "dicom_pch.h"
#include "dicom/data/string_converter/StringConverter.h"

#include "dicom/data/detail/DefaultCharacterRepertoire.h"

// Single byte character set conversions
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
#include "dicom/data/string_converter/tis_620_2533_converter.h"

// Multi-byte character set conversions
#include "dicom/data/string_converter/jis_x_0208_converter.h"
#include "dicom/data/string_converter/jis_x_0212_converter.h"
#include "dicom/data/string_converter/ks_x_1001_converter.h"
#include "dicom/data/string_converter/gb18030_converter.h"

// Code extension based conversion
#include "dicom/data/string_converter/iso_iec_2022_converter.h"

using namespace dicom::data;
using namespace std;
using namespace std::literals::string_view_literals;

namespace {
    [[nodiscard]] bool is_code_extension_encoding(StringEncodingType string_encoding) {
        switch (string_encoding) {
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
        case StringEncodingType::CodeExtension_JIS_X_0208:
        case StringEncodingType::CodeExtension_JIS_X_0212:
        case StringEncodingType::CodeExtension_TIS_620_2533:
        case StringEncodingType::CodeExtension_KS_X_1001:
        case StringEncodingType::CodeExtension_GB_2312:
            return true;

        default:
            return false;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] StringEncodingType as_code_extension_encoding(StringEncodingType string_encoding) {
        switch (string_encoding) {
        case StringEncodingType::ISO_IEC_646:    return StringEncodingType::CodeExtension_ISO_IEC_646;
        case StringEncodingType::ISO_IEC_8859_1: return StringEncodingType::CodeExtension_ISO_IEC_8859_1;
        case StringEncodingType::ISO_IEC_8859_2: return StringEncodingType::CodeExtension_ISO_IEC_8859_2;
        case StringEncodingType::ISO_IEC_8859_3: return StringEncodingType::CodeExtension_ISO_IEC_8859_3;
        case StringEncodingType::ISO_IEC_8859_4: return StringEncodingType::CodeExtension_ISO_IEC_8859_4;
        case StringEncodingType::ISO_IEC_8859_5: return StringEncodingType::CodeExtension_ISO_IEC_8859_5;
        case StringEncodingType::ISO_IEC_8859_6: return StringEncodingType::CodeExtension_ISO_IEC_8859_6;
        case StringEncodingType::ISO_IEC_8859_7: return StringEncodingType::CodeExtension_ISO_IEC_8859_7;
        case StringEncodingType::ISO_IEC_8859_8: return StringEncodingType::CodeExtension_ISO_IEC_8859_8;
        case StringEncodingType::ISO_IEC_8859_9: return StringEncodingType::CodeExtension_ISO_IEC_8859_9;
        case StringEncodingType::JIS_X_0201:     return StringEncodingType::CodeExtension_JIS_X_0201;
        case StringEncodingType::TIS_620_2533:   return StringEncodingType::CodeExtension_TIS_620_2533;

        default:
            // UTF-8, GB18030 and GBK have been filtered out already. [string_encoding] will be a code extension.
            return string_encoding;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    const map<string_view, StringEncodingType> s_character_sets = {
        {""sv,           StringEncodingType::ISO_IEC_646   }, // ASCII
        {"ISO_IR 100"sv, StringEncodingType::ISO_IEC_8859_1}, // Latin-1
        {"ISO_IR 101"sv, StringEncodingType::ISO_IEC_8859_2}, // Latin-2
        {"ISO_IR 108"sv, StringEncodingType::ISO_IEC_8859_3}, // Latin-3
        {"ISO_IR 110"sv, StringEncodingType::ISO_IEC_8859_4}, // Latin-4
        {"ISO_IR 144"sv, StringEncodingType::ISO_IEC_8859_5}, // Cyrillic
        {"ISO_IR 127"sv, StringEncodingType::ISO_IEC_8859_6}, // Arabic
        {"ISO_IR 126"sv, StringEncodingType::ISO_IEC_8859_7}, // Greek
        {"ISO_IR 138"sv, StringEncodingType::ISO_IEC_8859_8}, // Hebrew
        {"ISO_IR 148"sv, StringEncodingType::ISO_IEC_8859_9}, // Latin-5 (Turkish)
        {"ISO_IR 13"sv,  StringEncodingType::JIS_X_0201    }, // Japanese (Romaji + Katakana)
        {"ISO_IR 166"sv, StringEncodingType::TIS_620_2533  }, // Thai
        {"ISO_IR 192"sv, StringEncodingType::UTF8          }, // UTF-8
        {"GB18030"sv,    StringEncodingType::GB_18030      }, // Chinese
        {"GBK"sv,        StringEncodingType::GBK           }, // Chinese GBK

        {"ISO 2022 IR 6"sv,   StringEncodingType::CodeExtension_ISO_IEC_646   }, // ASCII
        {"ISO 2022 IR 100"sv, StringEncodingType::CodeExtension_ISO_IEC_8859_1}, // Latin-1
        {"ISO 2022 IR 101"sv, StringEncodingType::CodeExtension_ISO_IEC_8859_2}, // Latin-2
        {"ISO 2022 IR 109"sv, StringEncodingType::CodeExtension_ISO_IEC_8859_3}, // Latin-3
        {"ISO 2022 IR 110"sv, StringEncodingType::CodeExtension_ISO_IEC_8859_4}, // Latin-4
        {"ISO 2022 IR 144"sv, StringEncodingType::CodeExtension_ISO_IEC_8859_5}, // Cyrillic
        {"ISO 2022 IR 127"sv, StringEncodingType::CodeExtension_ISO_IEC_8859_6}, // Arabic
        {"ISO 2022 IR 126"sv, StringEncodingType::CodeExtension_ISO_IEC_8859_7}, // Greek
        {"ISO 2022 IR 138"sv, StringEncodingType::CodeExtension_ISO_IEC_8859_8}, // Hebrew
        {"ISO 2022 IR 148"sv, StringEncodingType::CodeExtension_ISO_IEC_8859_9}, // Latin-5 (Turkish)
        {"ISO 2022 IR 13"sv,  StringEncodingType::CodeExtension_JIS_X_0201    }, // Japanese (Romaji + Katakana)
        {"ISO 2022 IR 166"sv, StringEncodingType::CodeExtension_TIS_620_2533  }, // Thai
        {"ISO 2022 IR 87"sv,  StringEncodingType::CodeExtension_JIS_X_0208    }, // Japanese (Kanji)
        {"ISO 2022 IR 159"sv, StringEncodingType::CodeExtension_JIS_X_0212    }, // Japanese (Kanji supplemental)
        {"ISO 2022 IR 149"sv, StringEncodingType::CodeExtension_KS_X_1001     }, // Korean (Hangul + Hanja)
        {"ISO 2022 IR 58"sv,  StringEncodingType::CodeExtension_GB_2312       }  // Chinese (GB 2312)
    };

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool convert_from_utf8_internal(
        StringEncodingType string_encoding,
        const string& utf_8,
        string& encoded
    ) {
        using namespace dicom::data::string_converter;

        bool ok;
        string tmp;
        switch (string_encoding) {
        case StringEncodingType::ISO_IEC_646:    ok = utf8_to_iso_iec_646(utf_8, tmp); break;
        case StringEncodingType::ISO_IEC_8859_1: ok = utf8_to_iso_iec_8859_1(utf_8, tmp); break;
        case StringEncodingType::ISO_IEC_8859_2: ok = utf8_to_iso_iec_8859_2(utf_8, tmp); break;
        case StringEncodingType::ISO_IEC_8859_3: ok = utf8_to_iso_iec_8859_3(utf_8, tmp); break;
        case StringEncodingType::ISO_IEC_8859_4: ok = utf8_to_iso_iec_8859_4(utf_8, tmp); break;
        case StringEncodingType::ISO_IEC_8859_5: ok = utf8_to_iso_iec_8859_5(utf_8, tmp); break;
        case StringEncodingType::ISO_IEC_8859_6: ok = utf8_to_iso_iec_8859_6(utf_8, tmp); break;
        case StringEncodingType::ISO_IEC_8859_7: ok = utf8_to_iso_iec_8859_7(utf_8, tmp); break;
        case StringEncodingType::ISO_IEC_8859_8: ok = utf8_to_iso_iec_8859_8(utf_8, tmp); break;
        case StringEncodingType::ISO_IEC_8859_9: ok = utf8_to_iso_iec_8859_9(utf_8, tmp); break;
        case StringEncodingType::JIS_X_0201:     ok = utf8_to_jis_x_0201(utf_8, tmp); break;
        case StringEncodingType::TIS_620_2533:   ok = utf8_to_tis_620_2533(utf_8, tmp); break;
        case StringEncodingType::UTF8:           ok = true; tmp = utf_8; break;
        case StringEncodingType::GB_18030:       ok = utf8_to_gb_18030(utf_8, tmp); break;
        case StringEncodingType::GBK:            ok = utf8_to_gbk(utf_8, tmp); break;

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
            ok = utf8_to_iso_iec_2022(utf_8, tmp, string_encoding);
            break;

        case StringEncodingType::Unknown:
        default:
            // Unknown string encoding. Conversion is not possible.
            return false;
        }

        if (ok) {
            encoded = move(tmp);
        }
        return ok;
    }
}

namespace dicom::data::string_converter {

    StringEncodingType convert_to_string_encoding(const vector<string_view>& character_sets) {
        if (character_sets.empty()) { return StringEncodingType::Unknown; }

        vector<StringEncodingType> encodings;
        for (auto& character_set : character_sets) {
            auto it = s_character_sets.find(character_set);
            if (it == s_character_sets.end()) {
                // Unknown character set.
                return StringEncodingType::Unknown;
            }

            if (find(encodings.begin(), encodings.end(), it->second) == encodings.end()) {
                encodings.push_back(it->second);
            }
        }

        // Special case UTF8, GB18030 and GBK as they cannot participate in code extensions
        if (find(encodings.begin(), encodings.end(), StringEncodingType::UTF8) != encodings.end()) {
            return StringEncodingType::UTF8;
        }
        if (find(encodings.begin(), encodings.end(), StringEncodingType::GB_18030) != encodings.end()) {
            return StringEncodingType::GB_18030;
        }
        if (find(encodings.begin(), encodings.end(), StringEncodingType::GBK) != encodings.end()) {
            return StringEncodingType::GBK;
        }

        // If there is only one encoding then simply use it.
        if (encodings.size() == 1) {
            return *encodings.begin();
        }

        // If code extensions are used then take the first encoding as starting point.
        bool any_code_extensions = any_of(encodings.begin(), encodings.end(), is_code_extension_encoding);
        if (any_code_extensions) {
            // Force the encoding to use code extensions for safety.
            return as_code_extension_encoding(*encodings.begin());
        }

        // We have multiple encodings but they don't use code extensions. We cannot be sure of which
        // is correct.
        return StringEncodingType::Unknown;
    }

    //--------------------------------------------------------------------------------------------------------

    bool convert_from_string_encoding(StringEncodingType encoding, vector<string_view>& character_sets) {
        // Find the name of the character set relating to the encoding.
        auto it = find_if(
            s_character_sets.begin(),
            s_character_sets.end(),
            [&](const auto& kvp) { return kvp.second == encoding; }
        );
        if (it == s_character_sets.end()) { return false; }

        if (!character_sets.empty() && character_sets.front() == it->first) {
            // The first entry matches the target encoding. Keep the contents as they may contain more
            // accurate information than we could infer.
            return true;
        }

        // Update the character sets vector with only the target encoding.
        character_sets.clear();
        character_sets.push_back(it->first);
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool convert_to_utf8(
        StringEncodingType string_encoding,
        const std::string_view& encoded_source,
        string& utf8_dest
    ) {
        using namespace string_converter;

        switch (string_encoding) {
        case StringEncodingType::ISO_IEC_646:    return iso_iec_646_to_utf8(encoded_source, utf8_dest);
        case StringEncodingType::ISO_IEC_8859_1: return iso_iec_8859_1_to_utf8(encoded_source, utf8_dest);
        case StringEncodingType::ISO_IEC_8859_2: return iso_iec_8859_2_to_utf8(encoded_source, utf8_dest);
        case StringEncodingType::ISO_IEC_8859_3: return iso_iec_8859_3_to_utf8(encoded_source, utf8_dest);
        case StringEncodingType::ISO_IEC_8859_4: return iso_iec_8859_4_to_utf8(encoded_source, utf8_dest);
        case StringEncodingType::ISO_IEC_8859_5: return iso_iec_8859_5_to_utf8(encoded_source, utf8_dest);
        case StringEncodingType::ISO_IEC_8859_6: return iso_iec_8859_6_to_utf8(encoded_source, utf8_dest);
        case StringEncodingType::ISO_IEC_8859_7: return iso_iec_8859_7_to_utf8(encoded_source, utf8_dest);
        case StringEncodingType::ISO_IEC_8859_8: return iso_iec_8859_8_to_utf8(encoded_source, utf8_dest);
        case StringEncodingType::ISO_IEC_8859_9: return iso_iec_8859_9_to_utf8(encoded_source, utf8_dest);
        case StringEncodingType::JIS_X_0201:     return jis_x_0201_to_utf8(encoded_source, utf8_dest);
        case StringEncodingType::TIS_620_2533:   return tis_620_2533_to_utf8(encoded_source, utf8_dest);
        case StringEncodingType::UTF8:           utf8_dest = encoded_source; return true;
        case StringEncodingType::GB_18030:       return gb_18030_to_utf8(encoded_source, utf8_dest);
        case StringEncodingType::GBK:            return gbk_to_utf8(encoded_source, utf8_dest);

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
            return iso_iec_2022_to_utf8(encoded_source, utf8_dest, string_encoding);

        case StringEncodingType::Unknown:
        default:
            // Unknown string encoding. Conversion is not possible.
            return false;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    bool convert_from_utf8(
        StringEncodingType string_encoding,
        const string& utf8_source,
        buffer<char>& encoded_dest
    ) {
        std::string tmp;
        if (!convert_from_utf8_internal(string_encoding, utf8_source, tmp)) {
            return false;
        }

        buffer<char> buf(tmp.size());
        memcpy(buf, tmp.data(), tmp.size());
        encoded_dest = move(buf);
        return true;
    }

}