#include "tdx_float32.hpp"

namespace tdx_values{
    byte_vector tdx_float32::serialize() {
        auto type_size = sizeof(float);
        std::byte buffer[type_size];

        float l_value = value.value();
        auto byte_data = static_cast<std::byte*>(static_cast<void*>(&value));
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

    tdx_float32 tdx_float32::parse(byte_vector &value) {
        auto length = value.size();
        const auto type_size = sizeof( float );

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

        float cast_value;
        memcpy( &cast_value, buffer, type_size);

        return tdx_float32(cast_value);
    }
}