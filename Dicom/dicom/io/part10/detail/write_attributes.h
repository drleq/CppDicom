#pragma once

namespace dicom::data { class AttributeSet; }
namespace dicom::io::part10::detail { class OutputContext; }

namespace dicom::io::part10::detail {

    DICOM_EXPORT [[nodiscard]] bool write_attributes(OutputContext* context, const data::AttributeSet* src);

}