#include "dicom_pch.h"
#include "dicom/multiframe/PrivateTags.h"

namespace dicom::multiframe::private_tags {

    const private_tag_creator MultiFramePrivateCreator = { "DICOM MultiFrame", 0x0009 };
    const private_tag FrameIndexTag = { &MultiFramePrivateCreator, 0x01, {1, 1}, data::VRType::IS, false };

}