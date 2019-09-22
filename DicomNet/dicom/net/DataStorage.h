#pragma once

namespace dicom::net {

    using input_buffer = asio::const_buffer;

    using data_buffer = std::vector<uint8_t>;
    using output_buffer = asio::dynamic_vector_buffer<uint8_t, std::allocator<uint8_t>>;

    //--------------------------------------------------------------------------------------------------------

    class DICOMNET_EXPORT IDataStorage
    {
    public:
        virtual ~IDataStorage() = default;
        virtual asio::const_buffer AsBuffer() const = 0;
    };
    using DataStoragePtr = std::shared_ptr<IDataStorage>;

    //--------------------------------------------------------------------------------------------------------

    class UniqueValueDataStorage :
        public IDataStorage
    {
    public:
        UniqueValueDataStorage(data_buffer&& storage);
        virtual ~UniqueValueDataStorage();

        data_buffer Storage;

        asio::const_buffer AsBuffer() const override;
    };

    //--------------------------------------------------------------------------------------------------------

    using SharedDataBuffer = std::shared_ptr<data_buffer>;
    class SharedValueDataStorage :
        public IDataStorage
    {
    public:
        SharedValueDataStorage(data_buffer&& storage);
        SharedValueDataStorage(SharedDataBuffer storage);
        SharedValueDataStorage(SharedDataBuffer storage, size_t offset, size_t length);
        virtual ~SharedValueDataStorage();

        SharedDataBuffer Storage;
        size_t Offset;
        size_t Length;

        asio::const_buffer AsBuffer() const override;
    };

    //--------------------------------------------------------------------------------------------------------

    class SubRangeDataStorage :
        public IDataStorage
    {
    public:
        SubRangeDataStorage(DataStoragePtr storage, size_t offset, size_t length);
        virtual ~SubRangeDataStorage();

        DataStoragePtr Storage;
        size_t Offset;
        size_t Length;

        asio::const_buffer AsBuffer() const override;
    };

    //--------------------------------------------------------------------------------------------------------

    using DataStorageSequence = std::vector<DataStoragePtr>;

}