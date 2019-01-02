#pragma once

namespace dicom::data { class SQ; }
namespace dicom::io::file::detail { class InputContext; }

namespace dicom::io::file::detail {

    DICOM_EXPORT [[nodiscard]] std::unique_ptr<data::SQ> read_sq(InputContext& context, std::streamsize length);

}