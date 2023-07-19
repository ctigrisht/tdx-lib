#include "tdx_datetime.hpp"

#include <cstdint>

namespace tdx_values{
//    tdx_datetime::tdx_datetime(std::int_fast64_t l_value)

    byte_vector tdx_datetime::serialize() {
        if (!value.has_value())
            return {};

        auto type_size = sizeof(std::int_fast64_t);
        std::byte buffer[type_size];

        std::int_fast64_t l_value = value.value();
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

    tdx_datetime tdx_datetime::parse(byte_vector& value) {
        return {};
    }

    tdx_datetime tdx_datetime::now() {
        std::chrono::time_point point = std::chrono::system_clock::now();
        auto ticks = point.time_since_epoch().count();

        return {ticks};
    }
}