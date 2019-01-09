#pragma once

#include "dicom/data/SQ.h"
namespace dicom::io::part10::detail { class InputContext; }

namespace dicom::io::part10::detail {

    DICOM_EXPORT [[nodiscard]] data::SQ::item_type read_sq_item(InputContext& context, std::streamsize length);

}