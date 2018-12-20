#pragma once

namespace dicom::data::detail {

    struct string_to_double {
        [[nodiscard]] static double Convert(const std::string_view& str) {
            if (str.empty()) {
                errno = EINVAL;
                return 0.0;
            }

            const char* end_ptr = str.data() + str.size();
            char* local_end_ptr = const_cast<char*>(end_ptr);

            double value = std::strtod(str.data(), &local_end_ptr);

            if (local_end_ptr != end_ptr) { errno = EINVAL; }
            return value;
        }
    };

}