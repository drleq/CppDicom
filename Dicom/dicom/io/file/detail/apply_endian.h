#pragma once

#include "dicom/detail/intrinsic.h"

namespace dicom::io::file::detail {

    // Base template parameterized on the byte width of the value to convert.
    // By default no functions are defined to force a compiler error.
    template <int Width>
    struct apply_endian {};

    //--------------------------------------------------------------------------------------------------------

    // Single byte binary sequences do not require any conversion
    template <>
    struct apply_endian<sizeof(uint8_t)>
    {
        static void Apply(void*, size_t) {
            // Nothing to do.
        }
    };

    //--------------------------------------------------------------------------------------------------------

    // Two byte binary sequences
    template <>
    struct apply_endian<sizeof(uint16_t)>
    {
        static void Apply(void* binary, size_t length) {
            auto data = (uint16_t*)binary;
            auto data_end = data + length;
            while (data != data_end) { *data = dicom::detail::byte_swap16(*data); ++data; }
        }
    };

    //--------------------------------------------------------------------------------------------------------

    // Four byte binary sequences
    template <>
    struct apply_endian<sizeof(uint32_t)>
    {
        static void Apply(void* binary, size_t length) {
            auto data = (uint32_t*)binary;
            auto data_end = data + length;
            while (data != data_end) { *data = dicom::detail::byte_swap32(*data); ++data; }
        }
    };

    //--------------------------------------------------------------------------------------------------------

    // Eight byte binary sequences
    template <>
    struct apply_endian<sizeof(uint64_t)>
    {
        static void Apply(void* binary, size_t length) {
            auto data = (uint64_t*)binary;
            auto data_end = data + length;
            while (data != data_end) { *data = dicom::detail::byte_swap64(*data); ++data; }
        }
    };

}