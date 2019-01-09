#pragma once

namespace dicom::data { class SQ; }
namespace dicom::io::part10::detail { class OutputContext; }

namespace dicom::io::part10::detail {

    DICOM_EXPORT void write_sq(OutputContext* context, const data::SQ* sq, bool unknown_length);

}