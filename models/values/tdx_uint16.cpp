#include "tdx_uint16.hpp"

#include <bit>

namespace tdx_values{
    byte_vector tdx_uint16::serialize() {
        auto type_size = sizeof(std::uint_fast16_t);
        std::byte bytes[type_size];

        std::uint_fast16_t value = this->value.value();
        auto byte_data = static_cast<std::byte*>(static_cast<void*>(&value));
        for (int i = 0; i < type_size; ++i) {
            bytes[i] = byte_data[i];
        }

        if constexpr (std::endian::native == std::endian::big){
            auto tmp = bytes[0];
            bytes[0] = bytes[1];
            bytes[1] = tmp;
        }

        auto ret_bytes = byte_vector();
        for (int i = 0; i < type_size; ++i) {
            ret_bytes.push_back(bytes[i]);
        }

        return std::move(ret_bytes);
    }

    tdx_uint16 tdx_uint16::parse(byte_vector& value) {
        auto length = value.size();

        std::byte buffer[length];
        for (int i = 0; i < length; ++i) {
            buffer[i] = value[i];
        }

        if constexpr (std::endian::native == std::endian::big){
            auto tmp = buffer[0];
            buffer[0] = buffer[1];
            buffer[1] = buffer[0];
        }

        std::int_fast16_t cast_value;
        memcpy( &cast_value, buffer, sizeof( std::int_fast16_t ) );

        return tdx_uint16(cast_value);
    }
}