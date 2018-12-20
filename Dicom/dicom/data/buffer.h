#pragma once

namespace dicom::data {

    template <typename T>
    class buffer
    {
    public:
        buffer(const buffer<T>&) = delete;
        buffer<T>& operator = (const buffer<T>&) = delete;

        //----------------------------------------------------------------------------------------------------
        
        buffer()
          : m_owns_buffer(false),
            m_length(0),
            m_buffer(nullptr)
        {}

        //----------------------------------------------------------------------------------------------------

        buffer(size_t length)
	      : m_length(length)
		{
            if (length != 0) {
                m_buffer = (T*)std::malloc(ByteLength());
                m_owns_buffer = true;
            } else {
                m_buffer = nullptr;
                m_owns_buffer = false;
            }
        }

        //----------------------------------------------------------------------------------------------------

		buffer(buffer<T>&& src)
		  : m_owns_buffer(src.m_owns_buffer),
            m_length(src.m_length),
            m_buffer(src.m_buffer)
		{
            src.m_owns_buffer = false;
			src.m_length = 0;
            src.m_buffer = nullptr;
		}

        //----------------------------------------------------------------------------------------------------

        buffer(T* buf, size_t length)
          : m_owns_buffer(false),
            m_length(length),
            m_buffer(buf)
        {}

        //----------------------------------------------------------------------------------------------------

        template <typename U>
        explicit buffer(buffer<U>&& other) {
            // One item type must fit perfectly within the other.
            static_assert(
                sizeof(T) >= sizeof(U) ?
                    (sizeof(T) % sizeof(U)) == 0 :
                    (sizeof(U) % sizeof(T)) == 0,
                "Buffer items are incompatible sizes"
            );

            m_owns_buffer = other.m_owns_buffer;
            m_length = other.ByteLength() / sizeof(T);
            m_buffer = reinterpret_cast<T*>(other.m_buffer);
            other.m_owns_buffer = false;
            other.m_length = 0;
            other.m_buffer = nullptr;
        }

        //----------------------------------------------------------------------------------------------------

        ~buffer() {
			if (m_owns_buffer) { std::free(m_buffer); }
        }

        //----------------------------------------------------------------------------------------------------

        buffer<T>& operator = (buffer<T>&& other) {
            if (m_owns_buffer) { std::free(m_buffer); }
            m_owns_buffer = other.m_owns_buffer;
            m_length = other.m_length;
            m_buffer = other.m_buffer;
            other.m_owns_buffer = false;
            other.m_length = 0;
            other.m_buffer = nullptr;
            return *this;
        }

        //----------------------------------------------------------------------------------------------------

		[[nodiscard]] size_t Length() const { return m_length; }
        [[nodiscard]] size_t ByteLength() const { return m_length * sizeof(T); }
        [[nodiscard]] bool Empty() const { return (m_length == 0); }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] T* Get() const { return m_buffer; }
        [[nodiscard]] operator T* () const { return m_buffer; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] int32_t Compare(const buffer<T>& other) const {
            bool empty = Empty();
            bool other_empty = other.Empty();
            if (empty && other_empty) { return 0; }
            if (empty != other_empty) { return empty ? -1 : 1; }

            auto cmp_len = std::min(m_length, other.m_length);
            auto ptr = m_buffer;
            auto other_ptr = other.m_buffer;
            for (size_t i = 0; i < cmp_len; ++i, ++ptr, ++other_ptr) {
                if (*ptr < *other_ptr) { return -1; }
                if (*ptr > *other_ptr) { return  1; }
            }

            if (m_length != other.m_length) {
                return (m_length < other.m_length) ? -1 : 1;
            }
            return 0;
        }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] bool operator == (const buffer<T>& other) const {
            if (m_length != other.m_length) { return false; }
            return memcmp(m_buffer, other.m_buffer, m_length * sizeof(T)) == 0;
        }

        [[nodiscard]] bool operator != (const buffer<T>& other) const { return !(*this == other); }
        [[nodiscard]] bool operator <  (const buffer<T>& other) const { return Compare(other) <  0; }
        [[nodiscard]] bool operator <= (const buffer<T>& other) const { return Compare(other) <= 0; }
        [[nodiscard]] bool operator >  (const buffer<T>& other) const { return Compare(other) >  0; }
        [[nodiscard]] bool operator >= (const buffer<T>& other) const { return Compare(other) >= 0; }

        //----------------------------------------------------------------------------------------------------

        [[nodiscard]] buffer<T> Copy() const {
            buffer<T> copy(m_length);
            memcpy(copy.m_buffer, m_buffer, ByteLength());
            return copy;
        }

    private:        
        bool m_owns_buffer;
		size_t m_length;
        T* m_buffer;

        // All specializations are friends.
        template <typename U> friend class buffer;
    };

}