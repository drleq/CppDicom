#include "dicomtest_pch.h"
#include "dicom_test/data/string_converter/CommonFixture.h"

namespace dicom_test::data::string_converter {

    std::string CommonFixture::s_mapping_file;
    detail::CharacterMappingPtr CommonFixture::s_mapping;

}