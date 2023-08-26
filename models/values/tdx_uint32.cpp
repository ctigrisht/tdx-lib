#include "tdx_uint32.hpp"

namespace tdx_values{
    tdx_bytes_result tdx_uint32::serialize() {
        if (!value.has_value())
            return (false);

        auto type_size = sizeof(std::uint_fast32_t);
        std::byte buffer[type_size];

        std::uint_fast32_t l_value = value.value();
        auto byte_data = static_cast<std::byte*>(static_cast<void*>(&l_value));
        for (int i = 0; i < type_size; ++i) {
            buffer[i] = byte_data[i];
        }

        if constexpr (std::endian::native == std::endian::big){
            std::byte tmp_arr[type_size];
            for (int i = 0; i < type_size; ++i) {
                auto inverse = type_size - 1 - i;
                tmp_arr[inverse] = byte_data[i];
            }
            for (int i = 0; i < type_size; ++i) {
                buffer[i] = tmp_arr[i];
            }
        }

        auto ret_bytes = byte_vector();
        for (int i = 0; i < type_size; ++i) {
            ret_bytes.push_back(buffer[i]);
        }

        return std::move(ret_bytes);
    }

    tdx_uint32 tdx_uint32::parse(byte_vector &value) {
        auto length = value.size();
        const auto type_size = sizeof( std::uint_fast32_t );

        if (length > type_size)
            throw std::exception();

        std::byte buffer[length];
        for (int i = 0; i < length; ++i) {
            buffer[i] = value[i];
        }

        if constexpr (std::endian::native == std::endian::big){
            std::byte tmp_arr[type_size];
            for (int i = 0; i < type_size; ++i) {
                auto inverse = type_size - 1 - i;
                tmp_arr[inverse] = buffer[i];
            }
            for (int i = 0; i < type_size; ++i) {
                buffer[i] = tmp_arr[i];
            }
        }

        std::uint_fast32_t cast_value;
        memcpy( &cast_value, buffer, type_size);

        return tdx_uint32(cast_value);
    }
}