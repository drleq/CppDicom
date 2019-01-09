#include "dicomfiletest_pch.h"

#include "dicom/dicom.h"
#include "dicom/DataDictionary.h"
#include "dicom/Tags.h"

#include "dicom/multiframe/PrivateTags.h"

#include "dicom/io/TransferSyntax.h"
#include "dicom/io/file/FileMetadataSource.h"
#include "dicom/io/file/FileMetadataSink.h"
#include "dicom/multiframe/FrameCache.h"

#include <chrono>
#include <iostream>
#include <filesystem>

#include <fstream>
#include <sstream>
#include <iomanip>

using namespace dicom;
using namespace dicom::io;
using namespace dicom::io::file;

const int LoopCount = 1000;

int main(int argc, const char* argv[]) {
    using namespace std::chrono;

    if (argc != 2) {
        std::cout << "Usage: DicomFileTest <input_file>" << std::endl;
        return -1;
    }

    const char* input_file = argv[1];

    auto data_dictionary = std::make_shared<DataDictionary>();
    tags::populate_data_dictionary(data_dictionary);

    auto start = high_resolution_clock::now();
    for (int i = 0; i < LoopCount; ++i) {
        auto load_result = FileMetadataSource::Load(
            input_file,
            data_dictionary,
            nullptr,
            [](const std::string_view*, tag_number) { return AttributeFilterResult::Load; }
        );
        
        [[maybe_unused]] auto frame_count = load_result->FrameCount();
        // for (size_t j = 0; j < frame_count; ++j) {
        //     load_result->GetPixelData(j);
        // }
    }
    auto end = high_resolution_clock::now();
    duration<float, std::milli> delta = end - start;

    std::cout << "File Delta: " << delta.count() << "ms" << std::endl;
    std::cout << "File PerLoad: " << (delta.count() / LoopCount) << "ms" << std::endl;

    return 0;
}