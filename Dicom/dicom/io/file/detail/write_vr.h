#pragma once

namespace dicom::data { class VR; }
namespace dicom::io::file::detail { class OutputContext; }

namespace dicom::io::file::detail {

    void write_vr(OutputContext* context, const data::VR* attribute);

}