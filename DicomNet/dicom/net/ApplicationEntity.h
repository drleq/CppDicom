#pragma once

namespace dicom::net {

    class DICOMNET_EXPORT ApplicationEntity {
    public:
        ApplicationEntity(std::string title);
        virtual ~ApplicationEntity();

        const std::string& Title() const { return m_title; }

    private:
        std::string m_title;
    };

}