#pragma once

namespace dicom::data { class AttributeSet; }

namespace dicom::data {

    enum class StringEncodingType : uint8_t {
        // Normal encodings
        ISO_IEC_646,    // 7-bit ASCII
        ISO_IEC_8859_1, // Latin-1 (8-bit ASCII)
        ISO_IEC_8859_2, // Latin-2
        ISO_IEC_8859_3, // Latin-3
        ISO_IEC_8859_4, // Latin-4
        ISO_IEC_8859_5, // Cyrillic
        ISO_IEC_8859_6, // Arabic
        ISO_IEC_8859_7, // Greek
        ISO_IEC_8859_8, // Hebrew
        ISO_IEC_8859_9, // Latin-5 (Turkish)
        JIS_X_0201,     // Japanese (Romaji + Katakana)
        TIS_620_2533,   // Thai
        UTF8,           // UTF-8
        GB_18030,       // Chinese
        GBK,            // Chinese GBK
        GB_2312,        // Chinese GB2312

        // DICOM code extension variants
        CodeExtension_ISO_IEC_646,    // 7-bit ASCII
        CodeExtension_ISO_IEC_8859_1, // Latin-1 (8-bit ASCII)
        CodeExtension_ISO_IEC_8859_2, // Latin-2
        CodeExtension_ISO_IEC_8859_3, // Latin-3
        CodeExtension_ISO_IEC_8859_4, // Latin-4
        CodeExtension_ISO_IEC_8859_5, // Cyrillic
        CodeExtension_ISO_IEC_8859_6, // Arabic
        CodeExtension_ISO_IEC_8859_7, // Greek
        CodeExtension_ISO_IEC_8859_8, // Hebrew
        CodeExtension_ISO_IEC_8859_9, // Latin-5 (Turkish)
        CodeExtension_JIS_X_0201,     // Japanese (Romaji + Katakana)
        CodeExtension_JIS_X_0208,     // Japanese (Kanji)
        CodeExtension_JIS_X_0212,     // Japanese (Kanji supplemental)
        CodeExtension_TIS_620_2533,   // Thai
        CodeExtension_KS_X_1001,      // Korean (Hangul + Hanja)
        CodeExtension_GB_2312,        // Chinese (GB2312)

        Unknown                       // The character set could not be determined
    };

    //---------------------------------------------------------------------------------------------

    DICOM_EXPORT [[nodiscard]] bool extract_string_encodings(
        const AttributeSet& as,
        std::set<StringEncodingType>& string_encodings
    );

}