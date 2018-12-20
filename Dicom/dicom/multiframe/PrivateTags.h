#pragma once

#include "dicom/private_tag.h"

namespace dicom::multiframe::private_tags {

    /** MultiFramePrivateCreator, "DICOM MultiFrame", 0x0009 */
    extern const private_tag_creator MultiFramePrivateCreator;
    /** FrameIndexTag, (MultiFramePrivateCreator,01), IS, 1 */
    extern const private_tag FrameIndexTag;

}