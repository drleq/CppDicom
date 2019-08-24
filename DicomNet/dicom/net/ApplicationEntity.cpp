#include "dicomnet_pch.h"
#include "dicom/net/ApplicationEntity.h"

namespace dicom::net {

    ApplicationEntity::ApplicationEntity(std::string title)
      : m_title(std::move(title))
    {}

    //--------------------------------------------------------------------------------------------------------

    ApplicationEntity::~ApplicationEntity() = default;

}