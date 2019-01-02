#pragma once

#include <stdint.h>

#ifdef __GNUG__
#include <x86intrin.h>

namespace dicom::detail {
    inline int32_t bit_scan_forward32(uint32_t value) {
        if (value != 0) {
            return __builtin_ffs(value) - 1;
        } else {
            return -1;
        }
    }

    inline int32_t bit_scan_forward64(uint64_t value) {
        if (value != 0) {
            return __builtin_ffsll(value) - 1;
        } else {
            return -1;
        }
    }

    inline int32_t bit_scan_reverse32(uint32_t value) {
        if (value != 0) {
            return 31 - __builtin_clz(value);
        } else {
            return -1;
        }
    }

    inline int32_t bit_scan_reverse64(uint64_t value) {
        if (value != 0) {
            return 63 - __builtin_clzll(value);
        } else {
            return -1;
        }
    }

    inline uint16_t byte_swap16(uint16_t value) {
        return __builtin_bswap16(value);
    }
    inline uint32_t byte_swap32(uint32_t value) {
        return __builtin_bswap32(value);
    }
    inline uint64_t byte_swap64(uint64_t value) {
        return __builtin_bswap64(value);
    }

    inline uint32_t rotate_left32(uint32_t value, uint8_t distance) {
        return __rold(value, distance);
    }
}
#endif

#ifdef _MSC_VER
#include <intrin.h>

namespace dicom::detail {
    inline int32_t bit_scan_forward32(uint32_t value) {
        unsigned long index;
        if (_BitScanForward(&index, value)) {
            return static_cast<int32_t>(index);
        } else {
            return -1;
        }
    }

    inline int32_t bit_scan_forward64(uint64_t value) {
        unsigned long index;
        if (_BitScanForward64(&index, value)) {
            return static_cast<int32_t>(index);
        } else {
            return -1;
        }
    }

    inline int32_t bit_scan_reverse32(uint32_t value) {
        unsigned long index;
        if (_BitScanReverse(&index, value)) {
            return static_cast<int32_t>(index);
        } else {
            return -1;
        }
    }

    inline int32_t bit_scan_reverse64(uint64_t value) {
        unsigned long index;
        if (_BitScanReverse64(&index, value)) {
            return static_cast<int32_t>(index);
        } else {
            return -1;
        }
    }

    inline uint16_t byte_swap16(uint16_t value) {
        return _byteswap_ushort(value);
    }
    inline uint32_t byte_swap32(uint32_t value) {
        return _byteswap_ulong(value);
    }
    inline uint64_t byte_swap64(uint64_t value) {
        return _byteswap_uint64(value);
    }

    inline uint32_t rotate_left32(uint32_t value, uint8_t distance) {
        return _rotl(value, distance);
    }
}
#endif
