#pragma once

namespace dicom::data::string_converter::detail {

    // Get UTF-8 character count (not code-point count). Assumes [str] has a valid encoding.
    DICOM_EXPORT [[nodiscard]] size_t utf8_strlen(const std::string_view& str);

    //--------------------------------------------------------------------------------------------------------

    DICOM_EXPORT [[nodiscard]] bool decode_utf8_char(const uint8_t*& next_it, const uint8_t* end_it, char32_t& decoded);
    DICOM_EXPORT [[nodiscard]] bool encode_utf8_char(char32_t decoded, uint8_t*& next_it, const uint8_t* end_it);
    DICOM_EXPORT void make_space(std::string& buffer, ptrdiff_t minimum_increase);
    DICOM_EXPORT void shrink_utf8(std::string& buffer, ptrdiff_t length);

    //--------------------------------------------------------------------------------------------------------

    template <typename Callback>
    bool encoded_to_utf8(
        const std::string_view& encoded_source,
        std::string& utf8_dest,
        Callback encoded_to_utf32_callback     // bool (const uint8_t*& next_it, const uint8_t* end_it, char32_t& decoded)
    ) {
        constexpr ptrdiff_t MaxUtf8Length = 6;

        auto src_ptr = reinterpret_cast<const uint8_t*>(encoded_source.data());
        auto src_end = src_ptr + encoded_source.size();

        utf8_dest.resize(encoded_source.size());
        auto dest_ptr = reinterpret_cast<uint8_t*>(utf8_dest.data());
        auto dest_end = dest_ptr + utf8_dest.size();

        while (src_ptr < src_end) {
            char32_t c;
            if (!encoded_to_utf32_callback(src_ptr, src_end, c)) {
                return false;
            }

            if (MaxUtf8Length > std::distance(dest_ptr, dest_end)) {
                auto dest_begin = reinterpret_cast<uint8_t*>(utf8_dest.data());
                auto offset = std::distance(dest_begin, dest_ptr);
                make_space(utf8_dest, MaxUtf8Length);

                dest_begin = reinterpret_cast<uint8_t*>(utf8_dest.data());
                dest_ptr = dest_begin + offset;
                dest_end = dest_begin + utf8_dest.size();
            }

            if (!encode_utf8_char(c, dest_ptr, dest_end)) {
                return false;
            }
        }

        auto dest_begin = reinterpret_cast<uint8_t*>(utf8_dest.data());
        auto final_length = std::distance(dest_begin, dest_ptr);
        shrink_utf8(utf8_dest, final_length);

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    template <ptrdiff_t MaxCodePointLength, typename Callback>
    bool utf8_to_8bit_encoded(
        const std::string_view& utf8_source,
        std::string& encoded_dest,
        Callback utf32_to_encoded_callback  // bool (char32_t decoded, uint8_t*& next_it)
    ) {
        auto src_ptr = reinterpret_cast<const uint8_t*>(utf8_source.data());
        auto src_end = src_ptr + utf8_source.size();

        auto dest_ptr = reinterpret_cast<uint8_t*>(encoded_dest.data());
        auto dest_end = dest_ptr + encoded_dest.size();

        while (src_ptr < src_end) {
            char32_t c;
            if (!decode_utf8_char(src_ptr, src_end, c)) {
                return false;
            }

            if (MaxCodePointLength > std::distance(dest_ptr, dest_end)) {
                auto dest_begin = reinterpret_cast<uint8_t*>(encoded_dest.data());
                auto offset = std::distance(dest_begin, dest_ptr);
                make_space(encoded_dest, MaxCodePointLength);

                dest_begin = reinterpret_cast<uint8_t*>(encoded_dest.data());
                dest_ptr = dest_begin + offset;
                dest_end = dest_begin + encoded_dest.size();
            }

            if (!utf32_to_encoded_callback(c, dest_ptr)) {
                return false;
            }
        }

        auto dest_begin = reinterpret_cast<uint8_t*>(encoded_dest.data());
        auto final_length = std::distance(dest_begin, dest_ptr);
        shrink_utf8(encoded_dest, final_length);

        return true;
    }

}