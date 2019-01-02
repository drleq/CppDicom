# Common compiler flags
if (${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    add_compile_options(
        -Wall          # Enable all warnings
        -Werror        # Treat warnings as errors
    )
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    add_compile_options(
        -W4            # Enable all meaningful warnings
        -WX            # Treat warnings as errors
        -wd4275        # non dll-interface class 'foo' used as base for dll-interface class 'bar'
        -wd4251        # class 'foo' needs to have dll-interface to be used by clients of class 'bar'
    )
else()
    message(FATAL_ERROR "Unsupported compiler.")
endif()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(DicomTest
    dicom_test/data/detail/constants.cpp
    dicom_test/data/string_converter/detail/ByteRangeGroup.cpp
    dicom_test/data/string_converter/detail/CharacterMapping.cpp
    dicom_test/data/string_converter/detail/RangeAssignment.cpp
    dicom_test/data/string_converter/CommonFixture.cpp
    dicom_test/data/string_converter/gb2312_converter_test.cpp
    dicom_test/data/string_converter/gb18030_converter_test.cpp
    dicom_test/data/string_converter/iso_iec_8859_1_converter_test.cpp
    dicom_test/data/string_converter/iso_iec_8859_2_converter_test.cpp
    dicom_test/data/string_converter/iso_iec_8859_3_converter_test.cpp
    dicom_test/data/string_converter/iso_iec_8859_4_converter_test.cpp
    dicom_test/data/string_converter/iso_iec_8859_5_converter_test.cpp
    dicom_test/data/string_converter/iso_iec_8859_6_converter_test.cpp
    dicom_test/data/string_converter/iso_iec_8859_7_converter_test.cpp
    dicom_test/data/string_converter/iso_iec_8859_8_converter_test.cpp
    dicom_test/data/string_converter/iso_iec_8859_9_converter_test.cpp
    dicom_test/data/string_converter/jis_x_0201_converter_test.cpp
    dicom_test/data/string_converter/jis_x_0208_converter_test.cpp
    dicom_test/data/string_converter/jis_x_0212_converter_test.cpp
    dicom_test/data/string_converter/ks_x_1001_converter_test.cpp
    dicom_test/data/string_converter/tis_620_2533_converter_test.cpp
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
    dicom_test/data/UITest.cpp
    dicom_test/data/ULTest.cpp
    dicom_test/data/UNTest.cpp
    dicom_test/data/uri_test.cpp
    dicom_test/data/URTest.cpp
    dicom_test/data/USTest.cpp
    dicom_test/data/UTTest.cpp
    dicom_test/DicomTest.cpp
    dicomtest_pch.cpp)

target_include_directories(DicomTest
    PUBLIC .)

target_link_libraries(DicomTest
    Dicom)