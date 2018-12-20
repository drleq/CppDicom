# Common compiler flags
add_compile_options(
    -Wall          # Enable all warnings
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_executable(DicomTest
    dicom_test/data/detail/constants.cpp
    dicom_test/data/string_converter/detail/ByteRangeGroup.cpp
    dicom_test/data/string_converter/detail/CharacterMapping.cpp
    dicom_test/data/string_converter/detail/RangeAssignment.cpp
    dicom_test/data/string_converter/CommonFixture.cpp
    dicom_test/data/string_converter/gb2312_converter_test.cpp
    dicom_test/data/string_converter/gb18030_converter_test.cpp
    dicom_test/data/string_converter/iso_iec_646_converter_test.cpp
    dicom_test/data/AETest.cpp
    dicom_test/data/ASTest.cpp
    dicom_test/data/ATTest.cpp
    dicom_test/data/buffer_test.cpp
    dicom_test/data/CSTest.cpp
    dicom_test/data/DATest.cpp
    dicom_test/data/DSTest.cpp
    dicom_test/data/DTTest.cpp
    dicom_test/data/encoded_string_test.cpp
    dicom_test/data/FDTest.cpp
    dicom_test/data/FLTest.cpp
    dicom_test/data/ISTest.cpp
    dicom_test/data/LOTest.cpp
    dicom_test/data/LTTest.cpp
    dicom_test/data/SHTest.cpp
    dicom_test/data/STTest.cpp
    dicom_test/data/uri_test.cpp
    dicom_test/data/UTTest.cpp
    dicom_test/DicomTest.cpp
    dicomtest_pch.cpp)

target_include_directories(DicomTest
    PUBLIC .)

target_link_libraries(DicomTest
    Dicom)