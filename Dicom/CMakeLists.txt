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
        -DDICOM_EXPORT_SYMBOLS # Export symbols
        -wd4275        # non dll-interface class 'foo' used as base for dll-interface class 'bar'
        -wd4251        # class 'foo' needs to have dll-interface to be used by clients of class 'bar'
    )
else()
    message(FATAL_ERROR "Unsupported compiler.")
endif()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(Dicom SHARED
    dicom_pch.cpp
    dicom/data/detail/combine_strings.cpp
    dicom/data/detail/DefaultCharacterRepertoire.cpp
    dicom/data/detail/locate_separators.cpp
    dicom/data/detail/validate_separator_locations.cpp
    dicom/data/string_converter/detail/find_codepoint.cpp
    dicom/data/string_converter/detail/utf8_helpers.cpp
    dicom/data/string_converter/gb18030_converter.cpp
    dicom/data/string_converter/iso_iec_646_converter.cpp
    dicom/data/string_converter/iso_iec_2022_converter.cpp
    dicom/data/string_converter/iso_iec_8859_1_converter.cpp
    dicom/data/string_converter/iso_iec_8859_2_converter.cpp
    dicom/data/string_converter/iso_iec_8859_3_converter.cpp
    dicom/data/string_converter/iso_iec_8859_4_converter.cpp
    dicom/data/string_converter/iso_iec_8859_5_converter.cpp
    dicom/data/string_converter/iso_iec_8859_6_converter.cpp
    dicom/data/string_converter/iso_iec_8859_7_converter.cpp
    dicom/data/string_converter/iso_iec_8859_8_converter.cpp
    dicom/data/string_converter/iso_iec_8859_9_converter.cpp
    dicom/data/string_converter/jis_x_0201_converter.cpp
    dicom/data/string_converter/jis_x_0208_converter.cpp
    dicom/data/string_converter/jis_x_0212_converter.cpp
    dicom/data/string_converter/ks_x_1001_converter.cpp
    dicom/data/string_converter/StringConverter.cpp
    dicom/data/string_converter/tis_620_2533_converter.cpp
    dicom/data/AE.cpp
    dicom/data/AS.cpp
    dicom/data/AT.cpp
    dicom/data/AttributeSet.cpp
    dicom/data/ComponentGroup.cpp
    dicom/data/CS.cpp
    dicom/data/DA.cpp
    dicom/data/date_time.cpp
    dicom/data/date.cpp
    dicom/data/DS.cpp
    dicom/data/DT.cpp
    dicom/data/LT.cpp
    dicom/data/encoded_string.cpp
    dicom/data/FD.cpp
    dicom/data/FL.cpp
    dicom/data/IS.cpp
    dicom/data/LO.cpp
    dicom/data/OB.cpp
    dicom/data/OD.cpp
    dicom/data/OF.cpp
    dicom/data/OL.cpp
    dicom/data/OW.cpp
    dicom/data/PatientNameGroup.cpp
    dicom/data/PN.cpp
    dicom/data/SH.cpp
    dicom/data/SL.cpp
    dicom/data/SQ.cpp
    dicom/data/SS.cpp
    dicom/data/ST.cpp
    dicom/data/StringEncodingType.cpp
    dicom/data/time_offset.cpp
    dicom/data/time.cpp
    dicom/data/TM.cpp
    dicom/data/UC.cpp
    dicom/data/UI.cpp
    dicom/data/UL.cpp
    dicom/data/UN.cpp
    dicom/data/UR.cpp
    dicom/data/uri.cpp
    dicom/data/US.cpp
    dicom/data/UT.cpp
    dicom/data/value_empty.cpp
    dicom/data/value_invalid.cpp
    dicom/data/VR.cpp
    dicom/io/codec/CodecImage.cpp
    dicom/io/codec/ICodec.cpp
    dicom/io/codec/ICodecFactory.cpp
    dicom/io/codec/ICodecImage.cpp
    dicom/io/file/detail/create_deferred_vr.cpp
    dicom/io/file/detail/derive_pixel_data_ranges.cpp
    dicom/io/file/detail/derive_pixel_data_vrtype.cpp
    dicom/io/file/detail/discover_pixel_data_fragments.cpp
    dicom/io/file/detail/InputContext.cpp
    dicom/io/file/detail/OutputContext.cpp
    dicom/io/file/detail/read_attributes.cpp
    dicom/io/file/detail/read_data_element.cpp
    dicom/io/file/detail/read_file_meta_information.cpp
    dicom/io/file/detail/read_pixel_data.cpp
    dicom/io/file/detail/read_sq_item.cpp
    dicom/io/file/detail/read_sq.cpp
    dicom/io/file/detail/read_vr_type_and_length.cpp
    dicom/io/file/detail/read_vr.cpp
    dicom/io/file/detail/verify_header.cpp
    dicom/io/file/detail/write_attributes.cpp
    dicom/io/file/detail/write_data_element.cpp
    dicom/io/file/detail/write_file_meta_information.cpp
    dicom/io/file/detail/write_header.cpp
    dicom/io/file/detail/write_sq_item.cpp
    dicom/io/file/detail/write_sq.cpp
    dicom/io/file/detail/write_vr.cpp
    dicom/io/file/AttributeFilter.cpp
    dicom/io/file/FileInputStream.cpp
    dicom/io/file/FileLoadResult.cpp
    dicom/io/file/FileMetadataSink.cpp
    dicom/io/file/FileMetadataSource.cpp
    dicom/io/file/FileOutputStream.cpp
    dicom/io/file/InputStream.cpp
    dicom/io/file/OutputStream.cpp
    dicom/io/file/PixelDataRange.cpp
    dicom/io/Deferred.cpp
    dicom/io/TransferSyntax.cpp
    dicom/multiframe/frame_index.cpp
    dicom/multiframe/FrameCache.cpp
    dicom/multiframe/PrivateTags.cpp
    dicom/DataDictionary.cpp
    dicom/private_tag.cpp
    dicom/tag.cpp
    dicom/Tags.cpp
    dicom/UIDs.cpp)

target_include_directories(Dicom
    PUBLIC .)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    target_link_libraries(Dicom
        stdc++fs)
endif()