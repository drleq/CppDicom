#pragma once

#include "dicom/data/uri.h"

namespace CppUnitTestFramework::Ext {

    inline std::string ToString(const dicom::data::uri& value) {
        return value.Value();
    }

}