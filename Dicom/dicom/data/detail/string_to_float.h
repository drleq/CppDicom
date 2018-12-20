#pragma once

namespace dicom::data::detail {

    struct string_to_float {
        [[nodiscard]] static float Convert(const std::string_view& str) {
            if (str.empty()) {
                errno = EINVAL;
                return 0.0f;
            }

            const char* end_ptr = str.data() + str.size();
            char* local_end_ptr = const_cast<char*>(end_ptr);

            float value = std::strtof(str.data(), &local_end_ptr);

            if (local_end_ptr != end_ptr) { errno = EINVAL; }
            return value;
        }
    };

}