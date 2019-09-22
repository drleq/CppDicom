#include "dicomnet_pch.h"
#include "dicom/net/DataStorage.h"

namespace dicom::net {

    UniqueValueDataStorage::UniqueValueDataStorage(data_buffer&& storage)
      : Storage(std::forward<data_buffer>(storage))
    {}

    //--------------------------------------------------------------------------------------------------------

    UniqueValueDataStorage::~UniqueValueDataStorage() = default;

    //--------------------------------------------------------------------------------------------------------

    asio::const_buffer UniqueValueDataStorage::AsBuffer() const {
        return asio::const_buffer(Storage.data(), Storage.size());
    }

    //--------------------------------------------------------------------------------------------------------

    SharedValueDataStorage::SharedValueDataStorage(data_buffer&& storage)
      : SharedValueDataStorage(std::make_shared<data_buffer>(std::forward<data_buffer>(storage)))
    {}

    //--------------------------------------------------------------------------------------------------------

    SharedValueDataStorage::SharedValueDataStorage(SharedDataBuffer storage)
      : SharedValueDataStorage(storage, 0, storage->size())
    {}

    //--------------------------------------------------------------------------------------------------------

    SharedValueDataStorage::SharedValueDataStorage(SharedDataBuffer storage, size_t offset, size_t length)
      : Storage(std::move(storage)),
        Offset(offset),
        Length(length)
    {}

    //--------------------------------------------------------------------------------------------------------

    SharedValueDataStorage::~SharedValueDataStorage() = default;

    //--------------------------------------------------------------------------------------------------------

    asio::const_buffer SharedValueDataStorage::AsBuffer() const {
        return asio::const_buffer(Storage->data() + Offset, Length);
    }

    //--------------------------------------------------------------------------------------------------------

    SubRangeDataStorage::SubRangeDataStorage(DataStoragePtr storage, size_t offset, size_t length)
      : Storage(std::move(storage)),
        Offset(offset),
        Length(length)
    {}

    //--------------------------------------------------------------------------------------------------------

    SubRangeDataStorage::~SubRangeDataStorage() = default;

    //--------------------------------------------------------------------------------------------------------

    asio::const_buffer SubRangeDataStorage::AsBuffer() const {
        auto data = reinterpret_cast<const uint8_t*>(Storage->AsBuffer().data());
        return asio::buffer(data + Offset, Length);
    }

}