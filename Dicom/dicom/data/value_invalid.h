#pragma once

namespace dicom::data {

    class DICOM_EXPORT value_invalid_error : public std::runtime_error
    {
    public:
        value_invalid_error();
    };

}