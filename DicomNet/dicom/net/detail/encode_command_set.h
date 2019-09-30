#pragma once

namespace dicom::data { class AttributeSet; }
#include "dicom/net/DataStorage.h"

namespace dicom::net::detail {

    DataStoragePtr encode_command_set(const data::AttributeSet& command_set);

}