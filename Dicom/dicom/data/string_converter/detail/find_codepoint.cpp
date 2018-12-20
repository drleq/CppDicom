#include "dicom_pch.h"
#include "dicom/data/string_converter/detail/find_codepoint.h"

#include <emmintrin.h>

namespace dicom::data::string_converter::detail {

    const uint16_t* find_codepoint00(const uint16_t* ptr, const uint16_t* end_ptr, uint16_t cp) {
        auto cp_128 = _mm_set1_epi16(cp);
        auto ptr_128 = reinterpret_cast<const __m128i*>(ptr);

        // Search in batches of 8 code points.
        auto loop_count = std::distance(ptr, end_ptr) / 8;
        while (loop_count-- != 0) {
            auto mask = _mm_cmpeq_epi16(*ptr_128, cp_128);
            int result = _mm_movemask_epi8(mask);
            if (result == 0) {
                ++ptr_128;
                continue;
            }

            int index = (__builtin_ffs(result) - 1) / 2;

            return reinterpret_cast<const uint16_t*>(ptr_128) + index;
        }

        // Manually search whatever is left over.
        ptr = reinterpret_cast<const uint16_t*>(ptr_128);
        while (ptr != end_ptr) {
            if (*ptr == cp) { return ptr; }
            ++ptr;
        }

        return nullptr;
    }

}