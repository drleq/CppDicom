#include "dicomfiletest_pch.h"

#include "dicom/dicom.h"
#include "dicom/DataDictionary.h"
#include "dicom/Tags.h"

#include "dicom/multiframe/PrivateTags.h"

#include "dicom/io/TransferSyntax.h"
#include "dicom/io/part10/FileInputStream.h"
#include "dicom/io/part10/Part10Reader.h"
#include "dicom/io/part10/Part10Writer.h"
#include "dicom/io/part19/Part19Writer.h"
#include "dicom/multiframe/FrameCache.h"

#include <chrono>
#include <iostream>
#include <filesystem>

#include <fstream>
#include <sstream>
#include <iomanip>

using namespace dicom;
using namespace dicom::io;
using namespace dicom::io::part10;

const int LoopCount = 1;

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
        auto stream = std::make_shared<FileInputStream>(input_file);
        auto load_result = Part10Reader::Read(
            stream,
            data_dictionary,
            nullptr,
            [](const std::string_view*, tag_number) { return AttributeFilterResult::Load; }
        );
        
        [[maybe_unused]] auto frame_count = load_result->FrameCount();
        // for (size_t j = 0; j < frame_count; ++j) {
        //     load_result->GetPixelData(j);
        // }

        part19::Part19Writer::Write(
            "test.xml",
            load_result->Metadata()
        );
    }
    auto end = high_resolution_clock::now();
    duration<float, std::milli> delta = end - start;

    std::cout << "File Delta: " << delta.count() << "ms" << std::endl;
    std::cout << "File PerLoad: " << (delta.count() / LoopCount) << "ms" << std::endl;

    return 0;
}