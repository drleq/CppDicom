#include "dicom_pch.h"
#include "dicom/data/string_converter/detail/utf8_helpers.h"

namespace {
    // Number of trailing bytes, indexed by the first byte
    constexpr uint8_t s_trailing_bytes[256] = {
        // 7-bit code points
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        // Illegal
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        // 11-bit code points
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        // 16-bit code points
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        // 21-bit code points
        3, 3, 3, 3, 3, 3, 3, 3,
        // 26-bit code points
                                4, 4, 4, 4,
        // 31-bit code points
                                            5, 5, 5, 5
    };

    // Encoded value of the first byte, indexed by the first byte
    constexpr uint8_t s_lead_values[256] = {
        // 7-bit code points
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
        0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
        0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
        0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
        0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
        0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
        0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
        0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
        0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
        0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
        0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
        0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
        0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
        0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
        // Illegal
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        // 11-bit code points
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
        0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
        // 16-bit code points
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        // 21-bit code points
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        // 26-bit code points
        0x00, 0x01, 0x02, 0x03,
        // 31-bit code points
                                0x00, 0x01, 0x00, 0x00
    };

    // The number of UTF-8 bytes required to encode a value with high-bit X
    constexpr uint8_t s_bytes_to_write[32] = {
        // 1-7 bit code points
        1, 1, 1, 1, 1, 1, 1,
        // 8-11 bit code points
                             2, 2, 2, 2,
        // 12-16 bit code points
                                         3, 3, 3, 3,
        3,
        // 17-21 bit code points
           4, 4, 4, 4, 4,
        // 22-26 bit code points
                          5, 5, 5, 5, 5,
        // 27-31 bit code points
                                         6, 6, 6, 6
    };

    // The masks used for the first UTF-8 byte based on the number of bytes to write
    // Index 0 is impossible and zeroed out for convenience.
    constexpr uint8_t s_first_byte_masks[] = {
        0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC
    };
}

namespace dicom::data::string_converter::detail {

    size_t utf8_strlen(const std::string_view& str) {
        size_t size = 0;
        auto it = reinterpret_cast<const uint8_t*>(str.data());
        auto end_it = it + str.size();

        while (it < end_it) {
            auto trail_count = s_trailing_bytes[*it];
            it += (trail_count + 1);
            size++;
        }

        return size;
    }

    //--------------------------------------------------------------------------------------------------------

    bool decode_utf8_char(const uint8_t*& next_it, const uint8_t* end_it, char32_t& decoded) {
        // These values are illegal for the first byte of UTF-8
        if (*next_it >= 0x80 && *next_it <= 0xBF) {
            return false;
        }

        // Determine of we have enough remaining input
        auto trail_count = s_trailing_bytes[*next_it];
        if (trail_count > std::distance(next_it, end_it)) {
            return false;
        }

        // Join the character to a single UTF-32 code point
        auto cp_end = next_it + trail_count;
        char32_t c32 = s_lead_values[*next_it++];
        if (trail_count != 0) {
            c32 <<= 6;
            while (next_it != cp_end) {
                c32 |= (*next_it++) & 0x3F;
                c32 <<= 6;
            }
            c32 |= (*next_it++) & 0x3F;
        }

        decoded = c32;
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool encode_utf8_char(char32_t decoded, uint8_t*& next_it, const uint8_t* end_it) {
        uint8_t bytes_to_write = 1;

        // Search for the highest bit
        if (decoded != 0) {
            int high_bit = 31 - __builtin_clz(decoded);
            bytes_to_write = s_bytes_to_write[high_bit];
        }

        // Make sure we have space to do stuff
        if (bytes_to_write > std::distance<const uint8_t*>(next_it, end_it)) {
            return false;
        }

        auto out_ptr = next_it + bytes_to_write;

        // Output the UTF-8 code points
        switch (bytes_to_write) {
        case 6: *(--out_ptr) = 0x80 | static_cast<uint8_t>(decoded & 0x3F); decoded >>= 6;
        case 5: *(--out_ptr) = 0x80 | static_cast<uint8_t>(decoded & 0x3F); decoded >>= 6;
        case 4: *(--out_ptr) = 0x80 | static_cast<uint8_t>(decoded & 0x3F); decoded >>= 6;
        case 3: *(--out_ptr) = 0x80 | static_cast<uint8_t>(decoded & 0x3F); decoded >>= 6;
        case 2: *(--out_ptr) = 0x80 | static_cast<uint8_t>(decoded & 0x3F); decoded >>= 6;
        case 1: *(--out_ptr) = static_cast<uint8_t>(decoded | s_first_byte_masks[bytes_to_write]); break;

        default:
            return false;
        }

        next_it += bytes_to_write;
        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    void make_space(std::string& buffer, ptrdiff_t minimum_increase) {
        constexpr ptrdiff_t MaxIncrease = 1024;

        auto new_size = std::max(
            std::min(
                buffer.size() * 2,
                buffer.size() + MaxIncrease
            ),
            buffer.size() + minimum_increase
        );
        
        buffer.resize(new_size);
    }

    //--------------------------------------------------------------------------------------------------------

    void shrink_utf8(std::string& buffer, ptrdiff_t length) {
        buffer.resize(static_cast<size_t>(length));
    }

}