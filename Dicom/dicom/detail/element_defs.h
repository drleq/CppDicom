#pragma once

//#include "dicom/dicom.h"
#include "dicom/detail/ctx_reader.h"
#include "dicom/detail/ctx_writer.h"
#include "dicom/detail/elem_reader.h"
#include "dicom/detail/elem_writer.h"
#include "dicom/detail/private_elem_reader.h"

namespace dicom {

    using detail::elem_reader;
    using detail::elem_writer;
    using detail::ctx_reader;
    using detail::ctx_writer;
    using detail::private_elem_reader;

}
