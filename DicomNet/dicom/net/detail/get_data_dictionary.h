#pragma once

#include "dicom/DataDictionary.h"

namespace dicom::net::detail {

    const DataDictionaryPtr& get_data_dictionary();

}