#pragma once

#include "dicom/data/encoded_string.h"
#include "dicom/data/time.h"
#include "dicom/data/uri.h"

namespace CppUnitTestFramework::Ext {

    std::string ToString(dicom::data::ValidityType value);
    std::string ToString(const dicom::data::encoded_string& value);
    std::string ToString(const dicom::data::time& value);
    std::string ToString(const dicom::data::uri& value);

}