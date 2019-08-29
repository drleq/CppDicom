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
        -wd4275        # non dll-interface class 'foo' used as base for dll-interface class 'bar'
        -wd4251        # class 'foo' needs to have dll-interface to be used by clients of class 'bar'
        -D_SILENCE_CXX17_ALLOCATOR_VOID_DEPRECATION_WARNING # warning STL4009: std::allocator<void> is deprecated in C++17
    )
else()
    message(FATAL_ERROR "Unsupported compiler.")
endif()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(DicomNetTestbed
    dicomnettestbed_pch.cpp
    main.cpp)

target_include_directories(DicomNetTestbed
    PUBLIC .)

target_link_libraries(DicomNetTestbed
    Dicom
    DicomNet)