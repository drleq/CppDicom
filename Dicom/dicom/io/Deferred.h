#pragma once

#include "dicom/data/VR.h"

namespace dicom::io {

    constexpr data::ValidityType ValidityDeferred = data::ValidityType(-100);

    using LoadDeferredVRCallback = std::function<std::unique_ptr<data::VR> ()>;

    class Deferred :
        public data::VR
    {
    public:
        Deferred(LoadDeferredVRCallback load_vr_callback);
        Deferred(const Deferred& other);
        Deferred(Deferred&& other);
        virtual ~Deferred();

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool Empty() const override final { return !m_loaded_vr || m_loaded_vr->Empty(); }
        [[nodiscard]] std::unique_ptr<data::VR> Copy() const override final { return std::make_unique<Deferred>(*this); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const data::VR* other) const override final;

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool IsLoaded() const { return (bool)m_loaded_vr; }
        bool Load();
        void Unload();

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] const data::VR* Get() const { return m_loaded_vr.get(); }

        template <typename T>
        [[nodiscard]] const T* Get() const {
            auto vr = Deferred::Get();
            return dynamic_cast<const T*>(vr);
        }

    protected:
        data::ValidityType Validate() const;

    private:
        LoadDeferredVRCallback m_load_vr_callback;
        std::unique_ptr<data::VR> m_loaded_vr;
    };

}