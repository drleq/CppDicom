#pragma once

namespace dicom::data {

    enum class ValidityType : uint8_t
    {
        Uninitialized = uint8_t(-1),
        Deinitialized = uint8_t(-2),
        Valid         = 1,
        Acceptable    = 2,
        Invalid       = 3
    };

}