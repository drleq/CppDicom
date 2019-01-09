#pragma once

namespace dicom::data { class SQ; }
namespace dicom::io::part10::detail { class InputContext; }

namespace dicom::io::part10::detail {

    DICOM_EXPORT [[nodiscard]] std::unique_ptr<data::SQ> read_sq(InputContext& context, std::streamsize length);

}