#pragma once

namespace dicom::data {

    class DICOM_EXPORT value_empty_error : public std::runtime_error
    {
    public:
        value_empty_error();
    };

}