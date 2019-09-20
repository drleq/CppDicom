#include "dicom_pch.h"
#include "dicom/io/part10/MemoryInputStream.h"

namespace dicom::io::part10 {

    MemoryInputStream::MemoryInputStream(std::shared_ptr<MemoryInputView> view)
      : m_view(std::move(view)),
        m_offset(0)
    {
        Initialize(m_view->Length);
    }

    //--------------------------------------------------------------------------------------------------------

    MemoryInputStream::~MemoryInputStream() = default;

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] ReOpenStreamFunction MemoryInputStream::CreateReOpenFunction() const {
        return [view=m_view]() -> InputStreamPtr {
            return std::make_shared<MemoryInputStream>(view);
        };
    }

}