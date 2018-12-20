#include "dicom_pch.h"
#include "dicom/data/value_empty.h"

namespace dicom::data {

    value_empty_error::value_empty_error()
      : std::runtime_error("Value is empty")
    {}

}