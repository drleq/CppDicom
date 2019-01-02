#pragma once

#include "dicom/data/ComponentGroup.h"
#include "dicom/data/encoded_string.h"
#include "dicom/data/PatientNameGroup.h"
#include "dicom/data/time.h"
#include "dicom/data/uri.h"

namespace CppUnitTestFramework::Ext {

    std::string ToString(dicom::data::ValidityType value);
    std::string ToString(const dicom::data::ComponentGroup& value);
    std::string ToString(const dicom::data::encoded_string& value);
    std::string ToString(const dicom::data::PatientNameGroup& value);
    std::string ToString(const dicom::data::time& value);
    std::string ToString(const dicom::data::uri& value);

    //--------------------------------------------------------------------------------------------------------

    template <typename T>
    std::string ToString(const std::optional<T>& value) {
        if (!value.has_value()) {
            return "?";
        }
        return ToString(value.value());
    }

}