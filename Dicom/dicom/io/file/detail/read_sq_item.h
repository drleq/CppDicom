#pragma once

#include "dicom/data/SQ.h"
namespace dicom::io::file::detail { class InputContext; }

namespace dicom::io::file::detail {

    [[nodiscard]] data::SQ::item_type read_sq_item(InputContext& context, std::streamsize length);

}