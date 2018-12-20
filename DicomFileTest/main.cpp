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

//#define DATASET_TESTS 0

#ifdef DATASET_TESTS
int main(int, const char*[]) {
    using namespace std::filesystem;
    const path DatasetsShare{ "\\\\edidicom\\edidicom\\Company_Data\\Datasets" };

    DataDictionaryPtr data_dictionary(new DataDictionary);
    tags::populate_data_dictionary(data_dictionary);
    FileMetadataSource dicom_source;


    std::ofstream log_file{ "AccessLog.txt", std::ios_base::out | std::ios_base::app };

    const int StartDatasetNumber = 6001;
    const int MaxDatasetNumber = 9200;
    int dataset_number = StartDatasetNumber;
    while (true) {
        if (dataset_number > MaxDatasetNumber) {
            break;
        }

        int range_low = ((dataset_number / 100) * 100) + 1;
        int range_high = range_low + 99;

        std::stringstream range_dir_str;
        range_dir_str << std::setfill('0') << std::setw(5) << range_low << '-' << std::setw(5) << range_high;
        path range_dir = DatasetsShare / range_dir_str.str();

        dataset_number += 100;
        if (!exists(range_dir)) {
            continue;
        }

        directory_iterator range_dir_it{ range_dir };
        directory_iterator range_dir_end;
        for (; range_dir_it != range_dir_end; ++range_dir_it) {
            if (!is_directory(range_dir_it->status())) {
                continue;
            }

            path patient_dir = range_dir_it->path();
            auto patient_dir_length = patient_dir.string().size() + 1; // +1 for separator
            log_file << patient_dir.c_str() << std::endl;
            std::wcout << patient_dir.c_str() << std::endl;

            try {
                recursive_directory_iterator file_it{ patient_dir };
                recursive_directory_iterator file_end_it;

                size_t file_count = 0;
                auto start = std::chrono::high_resolution_clock::now();

                for (; file_it != file_end_it; ++file_it) {
                    if (!is_regular_file(file_it->status()) && !is_symlink(file_it->status())) {
                        continue;
                    }

                    path dicom_file = file_it->path();
                    std::string short_path = dicom_file.string().substr(patient_dir_length);

                    try {
                        auto load_result = dicom_source.Load(dicom_file.c_str(), data_dictionary);
                        if (load_result == nullptr) {
                            log_file << "    Load failed: " << short_path << std::endl;
                        }

                        file_count++;
                    } catch (const std::exception& e) {
                        log_file << "    Exception: " << short_path << std::endl;
                        log_file << "        " << e.what() << std::endl;
                    } catch (...) {
                        log_file << "    Exception: " << short_path << std::endl;
                    }
                }

                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> delta = end - start;
                log_file <<
                    "    " << file_count << " files in " << delta.count() << "ms" <<
                    "  (" << (delta.count() / file_count) << "ms each)" <<
                    std::endl;

            } catch (const std::exception& e) {
                log_file << "    Exception: " << e.what() << std::endl;
            } catch (...) {
                log_file << "    Exception!" << std::endl;
            }
        }
    }
}

#else // #ifdef DATASET_TESTS
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
        FileMetadataSource source(
            nullptr,
            [](const std::string_view*, tag_number) { return AttributeFilterResult::Load; }
        );
        auto load_result = source.Load(input_file, data_dictionary);
        
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
#endif