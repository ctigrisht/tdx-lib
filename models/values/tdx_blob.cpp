#include "tdx_blob.hpp"

namespace tdx_values {
    std::array<stdbyte, 4> serialize_uint32(std::uint32_t value);

    std::uint32_t parse_uint32(std::array<stdbyte, 4> bytes);

    tdx_blob tdx_blob::from_copy(byte_vector l_value) {
        tdx_blob tdx_val{};
        tdx_val.is_null = false;
        tdx_val.value = std::move(l_value);
        return std::move(tdx_val);
    }

    tdx_result tdx_blob::serialize() {
        if (value->data() == nullptr)
            return {};

        std::uint32_t data_size = value->size();
        auto size_bytes = serialize_uint32(data_size);

        byte_vector ret_bytes{};

        ret_bytes.insert(ret_bytes.end(), size_bytes.begin(), size_bytes.end());
        ret_bytes.insert(ret_bytes.end(), std::make_move_iterator(value.value().begin()),
                         std::make_move_iterator(value.value().end()));

        return std::move(ret_bytes);
    }

    tdx_blob tdx_blob::parse(byte_vector &value) {
        std::array<stdbyte, sizeof(std::uint32_t)> data_size_bytes{};
        auto ds_ptr = value.begin() + sizeof(std::uint32_t);
        std::copy(value.begin(), ds_ptr, data_size_bytes.begin());

        auto data_size = parse_uint32(data_size_bytes);

        byte_vector data_bytes{data_size};
        std::move(ds_ptr, ds_ptr + data_size, data_bytes.begin());
        return tdx_blob(data_bytes);
    }

    std::array<stdbyte, 4> serialize_uint32(std::uint32_t value) {
        std::array<stdbyte, 4> buffer{};

        if (std::endian::native == std::endian::big)
            throw "LE only";

        buffer[0] = static_cast<stdbyte>(value >> 0);
        buffer[1] = static_cast<stdbyte>(value >> 8);
        buffer[2] = static_cast<stdbyte >(value >> 8 * 2);
        buffer[3] = static_cast<stdbyte >(value >> 8 * 3);

        return buffer;
    }

    std::uint32_t parse_uint32(std::array<stdbyte, 4> bytes) {
        if (std::endian::native == std::endian::big)
            throw "LE only";

        std::uint32_t ret_val = 0;
        auto *val_ref = reinterpret_cast<stdbyte *>(&ret_val);

        for (int i = 0; i < sizeof(std::uint32_t); ++i)
            val_ref[i] = bytes[i];

        return ret_val;
    }
}