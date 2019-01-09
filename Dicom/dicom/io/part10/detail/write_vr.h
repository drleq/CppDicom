#pragma once

namespace dicom::data { class VR; }
namespace dicom::io::part10::detail { class OutputContext; }

namespace dicom::io::part10::detail {

    DICOM_EXPORT void write_vr(OutputContext* context, const data::VR* attribute);

}