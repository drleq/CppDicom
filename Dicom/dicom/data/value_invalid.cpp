#include "dicom_pch.h"
#include "dicom/data/value_invalid.h"

namespace dicom::data {

    value_invalid_error::value_invalid_error()
      : std::runtime_error("Value could not be parsed")
    {}

}