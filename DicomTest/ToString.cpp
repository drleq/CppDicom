#include "dicomtest_pch.h"
#include "ToString.h"

#include <sstream>

using namespace dicom::data;

namespace CppUnitTestFramework::Ext {

    std::string ToString(ValidityType value) {
        switch (value) {
        case ValidityType::Valid:         return "Valid";
        case ValidityType::Acceptable:    return "Acceptable";
        case ValidityType::Invalid:       return "Invalid";
        case ValidityType::Uninitialized: return "Uninitialized";
        case ValidityType::Deinitialized: return "Deinitialized";
        default:
            std::ostringstream ss;
            ss << "[ValidityType] " << static_cast<std::underlying_type_t<ValidityType>>(value);
            return ss.str();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    std::string ToString(const encoded_string& value) {
        if (value.Validity() == ValidityType::Valid) {
            return value.Parsed();
        } else {
            return "*" + ToString(value.Validity()) + "*";
        }
    }

    //--------------------------------------------------------------------------------------------------------

    std::string ToString(const dicom::data::time& value) {
        if (!value.IsValid()) {
            return "*Invalid*";
        } else {
            return value.AsString();
        }
    }

    //--------------------------------------------------------------------------------------------------------

    std::string ToString(const uri& value) {
        return value.Value();
    }

}