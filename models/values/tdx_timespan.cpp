#include "tdx_timespan.hpp"

namespace tdx_values{
    tdx_result tdx_timespan::serialize() {
        if (!value.has_value())
            return {};

        auto type_size = sizeof(std::int64_t);
        std::array<stdbyte, sizeof (std::int64_t)> buffer{};

        auto int_value = value.value();

        buffer[0] = static_cast<stdbyte>(int_value >> 8 * 0);
        buffer[1] = static_cast<stdbyte>(int_value >> 8 * 1);
        buffer[2] = static_cast<stdbyte>(int_value >> 8 * 2);
        buffer[3] = static_cast<stdbyte>(int_value >> 8 * 3);
        buffer[4] = static_cast<stdbyte>(int_value >> 8 * 4);
        buffer[5] = static_cast<stdbyte>(int_value >> 8 * 5);
        buffer[6] = static_cast<stdbyte>(int_value >> 8 * 6);
        buffer[7] = static_cast<stdbyte>(int_value >> 8 * 7);

//        auto byte_data = static_cast<std::byte *>(static_cast<void *>(&value));

        if constexpr (std::endian::native == std::endian::big) {
            std::byte tmp_arr[type_size];
            for (int i = 0; i < type_size; ++i) {
                auto inverse = type_size - 1 - i;
                tmp_arr[inverse] = buffer[i];
            }
            for (int i = 0; i < type_size; ++i) {
                buffer[i] = tmp_arr[i];
            }
        }

        return byte_vector {buffer.begin(), buffer.end()};
    }

    tdx_timespan tdx_timespan::parse(std::array<stdbyte, sizeof(std::int64_t)> &value) {
        std::int64_t tmp_val = 0;
        auto* tmp_ref = reinterpret_cast<std::byte*>(&tmp_val);

        if (std::endian::native == std::endian::big)
            throw "not implemented";

        for (int i = 0; i < sizeof(std::int64_t); ++i)
            tmp_ref[i] = value[i];

        return tdx_timespan(tmp_val);
    }
}