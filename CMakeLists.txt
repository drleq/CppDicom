cmake_minimum_required(VERSION 3.0.0)
project(Dicom
    VERSION 0.1.0
    DESCRIPTION "Library for efficient handling of DICOM data.")

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

# include(CTest)
# enable_testing()

add_subdirectory(Dicom)
add_subdirectory(DicomFileTest)
add_subdirectory(DicomTest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
