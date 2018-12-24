#pragma once

#include "dicom/data/encoded_string.h"
#include "dicom/data/uri.h"

namespace CppUnitTestFramework::Ext {

    std::string ToString(dicom::data::ValidityType value);
    std::string ToString(const dicom::data::uri& value);
    std::string ToString(const dicom::data::encoded_string& value);

}