#pragma once

namespace dicom::data::detail {
	
    template <typename TInt>
    TInt unchecked_atoi(const std::string_view& str) {
        if (str.empty()) {
            return 0;
        }

        bool neg = false;
        auto s = str.data();

        if constexpr (std::is_signed_v<TInt>) {
            // Signed integer expected.
            neg = (*s == '-');
        }
        if (neg || *s == '+') { s++; }

        TInt i = 0;
        while (isdigit(*s) && (s < str.end())) {
            i = (i * 10) + (*s++ - '0');
        }

        if constexpr (std::is_signed_v<TInt>) {
            return neg ? -i : i;
        } else {
            return i;
        }
    }

    //--------------------------------------------------------------------------------------------------------
    
    // For signed types
    template <typename TInt>
    TInt checked_atoi(const std::string_view& str) {
        if (str.empty()) {
            errno = EINVAL;
            return 0;
        }

        constexpr int MaxPositiveValue = std::numeric_limits<TInt>::max();
        constexpr int MinNegativeValue = std::numeric_limits<TInt>::min();

        auto end_ptr = str.data() + str.size();
        auto s = str.data();
        bool neg = false;
        TInt i = 0;
        
        if constexpr (std::is_signed_v<TInt>) {
            neg = (*s == '-');
        }
        if (neg || *s == '+') { s++; }

        if constexpr (std::is_signed_v<TInt>) {
            if (neg) {
                while (isdigit(*s) && (s < str.end())) {
                    if (i < (MinNegativeValue / 10)) {
                        // Overflow.
                        errno = EINVAL;
                        return 0;
                    }
                    i *= 10;

                    TInt c = *s++ - '0';
                    if (i < (MinNegativeValue + c)) {
                        // Overflow.
                        errno = EINVAL;
                        return 0;
                    }
                    i -= c;
                }
            }
        } 

        if (!neg) {
            while (isdigit(*s) && (s < str.end())) {
                if (i > (MaxPositiveValue / 10)) {
                    // Overflow.
                    errno = EINVAL;
                    return 0;
                }
                i *= 10;

                TInt c = *s++ - '0';
                if (i > (MaxPositiveValue - c)) {
                    // Overflow.
                    errno = EINVAL;
                    return 0;
                }
                i += c;
            }
        }

        if (s != end_ptr) { errno = EINVAL; }
        return i;
    }

}