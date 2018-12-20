#pragma once

namespace dicom::data { class AttributeSet; }
namespace dicom::io::file::detail { class OutputContext; }

namespace dicom::io::file::detail {

    [[nodiscard]] bool write_attributes(OutputContext* context, const data::AttributeSet* src);

}