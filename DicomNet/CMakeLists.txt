# Common compiler flags
if (${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    add_compile_options(
        -Wall          # Enable all warnings
        -Wextra
        -pedantic
        -Wcast-align
        -Wcast-qual
        -Wctor-dtor-privacy
        -Wdisabled-optimization
        -Wformat=2
        -Winit-self
        -Wlogical-op
        -Wmissing-declarations
        -Wmissing-include-dirs
        -Wnoexcept
        -Wold-style-cast
        -Woverloaded-virtual
        -Wredundant-decls
        -Wshadow
        -Wstrict-null-sentinel
        -Wstrict-overflow
        -Wundef
        -Wno-missing-field-initializers # Allow implict zero initialization of structs
        -Werror        # Treat warnings as errors
    )
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    add_compile_options(
        -W4            # Enable all meaningful warnings
        -WX            # Treat warnings as errors
        -DDICOMNET_EXPORT_SYMBOLS # Export symbols
        -wd4275        # non dll-interface class 'foo' used as base for dll-interface class 'bar'
        -wd4251        # class 'foo' needs to have dll-interface to be used by clients of class 'bar'
        -D_SILENCE_CXX17_ALLOCATOR_VOID_DEPRECATION_WARNING # warning STL4009: std::allocator<void> is deprecated in C++17
    )
else()
    message(FATAL_ERROR "Unsupported compiler.")
endif()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(DicomNet SHARED
    dicomnet_pch.cpp
    dicom/net/Acceptor.cpp
    dicom/net/AcseHandlers.cpp
    dicom/net/ApplicationEntity.cpp
    dicom/net/Association.cpp
    dicom/net/ArtimTimer.cpp
    dicom/net/DataStorage.cpp
    dicom/net/detail/CommandSetDecoder.cpp
    dicom/net/detail/encode_command_set.cpp
    dicom/net/detail/encode_dimse_message.cpp
    dicom/net/detail/fragment_message_data.cpp
    dicom/net/detail/get_data_dictionary.cpp
    dicom/net/detail/read_data_element.cpp
    dicom/net/detail/write_data_element.cpp
    dicom/net/DimseHandlers.cpp
    dicom/net/ProtocolDataUnits.cpp
    dicom/net/StateMachine.cpp
    dicom/net/Tags.cpp
    dicom/net/Transport.cpp
)

# Conan
include(../conan.cmake)
conan_cmake_run(REQUIRES asio/1.13.0@bincrafters/stable
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing)
conan_set_find_paths()

target_include_directories(DicomNet
    PUBLIC .)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    target_link_libraries(DicomNet
        stdc++fs)
endif()
target_link_libraries(DicomNet
    CONAN_PKG::asio
    Dicom)