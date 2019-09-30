#pragma once

namespace dicom::io::part10::detail { class InputContext; }
namespace dicom::data { class VR; }
#include "dicom/tag.h"

namespace dicom::net::detail {

    [[nodiscard]] bool read_data_element(
        io::part10::detail::InputContext& ctx,
        tag_number* tag,
        std::unique_ptr<data::VR>* attribute
    );

}