#pragma once

namespace dicom::io::part10::detail { class OutputContext; }
namespace dicom::data { class VR; }
#include "dicom/tag.h"

namespace dicom::net::detail {

    void write_data_element(
        io::part10::detail::OutputContext& ctx,
        const tag_number& tag,
        const data::VR* attribute
    );

}