#include "dicom_pch.h"
#include "dicom/data/AS.h"

#include <sstream>
#include <iomanip>

#include "dicom/data/detail/atoi.h"

namespace {
    using namespace dicom::data;

    [[nodiscard]] AS::UnitType char_to_units(char c) {
        switch (c) {
        case 'D': return AS::Days;
        case 'W': return AS::Weeks;
        case 'M': return AS::Months;
        case 'Y': return AS::Years;
        default: return AS::UnitType(-1);
        }
    }

    [[nodiscard]] char units_to_char(AS::UnitType units) {
        switch (units) {
        case AS::Days:   return 'D';
        case AS::Weeks:  return 'W';
        case AS::Months: return 'M';
        case AS::Years:  return 'Y';
        default: return 'X'; // Something purposefully invalid
        }
    }
}

namespace dicom::data {

    AS::AS()
      : AS(std::string())
    {}

    //--------------------------------------------------------------------------------------------------------

    AS::AS(const char* value)
      : AS(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    AS::AS(const std::string_view& value)
      : AS(std::string(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    AS::AS(std::string&& value)
      : VR(VRType::AS),
        m_value(std::forward<std::string>(value))
    {}

    //--------------------------------------------------------------------------------------------------------

    AS::AS(int32_t age, UnitType units)
      : VR(VRType::AS)
    {
        std::ostringstream ss;
        ss << std::setw(3) << std::setfill('0') << age 
           << std::setw(0) << units_to_char(units);
        m_value = ss.str();
    }

    //--------------------------------------------------------------------------------------------------------

    AS::AS(const AS& other) = default;
    AS::AS(AS&& other) = default;

    AS& AS::operator = (const AS& other) = default;
    AS& AS::operator = (AS&& other) = default;

    //--------------------------------------------------------------------------------------------------------

    AS::~AS() = default;

    //--------------------------------------------------------------------------------------------------------

    ValidityType AS::Validate() const {
		/*** Essential checks ***/
        // Value is always 4 characters long
        if (m_value.size() != 4) { return ValidityType::Invalid; }

        // Value must have numeric digits for the first three characters
        if (!std::all_of(m_value.begin(), m_value.begin() + 3, isdigit)) { return ValidityType::Invalid; }
        
        // Value must have a unit character at the end
        if (char_to_units(m_value[3]) == -1) { return ValidityType::Invalid; }


        return ValidityType::Valid;
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t AS::Age() const {
        AssertValidated();
        return detail::unchecked_atoi<int32_t>(m_value.c_str());
    }

    //--------------------------------------------------------------------------------------------------------

    AS::UnitType AS::Units() const {
        AssertValidated();
        return char_to_units(m_value[3]);
    }

    //--------------------------------------------------------------------------------------------------------

    int32_t AS::Compare(const VR* other) const {
        auto result = VR::Compare(other);
        if (result) { return result; }

        auto typed = static_cast<const AS*>(other);
        if (Validity() == ValidityType::Invalid || typed->Validity() == ValidityType::Invalid) {
            return m_value.compare(typed->m_value);
        }

        int32_t diff = Units() - typed->Units();
        if (diff != 0) { return diff; }

        diff = Age() - typed->Age();
        return diff;
    }

    //--------------------------------------------------------------------------------------------------------

    bool AS::operator == (const VR* other) const {
        if (VR::Compare(other) != 0) { return false; }

        auto typed = static_cast<const AS*>(other);
        return (m_value == typed->m_value);
    }

    //--------------------------------------------------------------------------------------------------------

    bool AS::operator != (const VR* other) const {
        if (VR::Compare(other) != 0) { return true; }

        auto typed = static_cast<const AS*>(other);
        return (m_value != typed->m_value);
    }

}