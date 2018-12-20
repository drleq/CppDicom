cmake_minimum_required(VERSION 3.0.0)
project(Dicom
    VERSION 0.1.0
    DESCRIPTION "Library for efficient handling of DICOM data.")

# include(CTest)
# enable_testing()

add_subdirectory(Dicom)
add_subdirectory(DicomFileTest)
add_subdirectory(DicomTest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
