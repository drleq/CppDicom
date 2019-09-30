#include "dicomnet_pch.h"
#include "dicom/net/detail/get_data_dictionary.h"

#include "dicom/net/Tags.h"

namespace {

    dicom::DataDictionaryPtr create_data_dictionary() {
        auto dict = std::make_shared<dicom::DataDictionary>();
        dicom::net::tags::populate_data_dictionary(dict);
        return dict;
    }

}

namespace dicom::net::detail {

    const DataDictionaryPtr& get_data_dictionary() {
        static const DataDictionaryPtr s_instance = create_data_dictionary();
        return s_instance;
    }

}