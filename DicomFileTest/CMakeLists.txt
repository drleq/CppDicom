# Common compiler flags
add_compile_options(
    -Wall          # Enable all warnings
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_executable(DicomFileTest
    dicomfiletest_pch.cpp
    main.cpp)

target_include_directories(DicomFileTest
    PUBLIC .)

target_link_libraries(DicomFileTest
    Dicom)