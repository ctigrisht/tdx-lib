#include "parsers.hpp"
#include "../../models/shared_types.hpp"
#include <string.h>
#include <algorithm>

namespace internal_serializers {
    int32_t parse_int32(std::span<std::byte> &bytes) {
        std::int32_t cast_value;
//        std::byte data_bytes[bytes.size()];

//        data_bytes[0] = bytes[0];
//        data_bytes[1] = bytes[1];
//        data_bytes[2] = bytes[2];
//        data_bytes[3] = bytes[3];

        auto type_size = sizeof(int32_t);

        memcpy(&cast_value, bytes.data(), type_size); // TODO SIGILL // TODO big endian

        return cast_value;
    }

    uint16_t parse_uint16(std::array<std::byte, 2> bytes){
        std::uint16_t cast_value;
        memcpy(&cast_value, bytes.data(), sizeof(uint16_t));
        return cast_value;
    }

    vr::result<std::string, uint32_t> parse_native_string(std::span<std::byte>& bytes){
        auto length = bytes.size();

        char characters[length];
        for (int i = 0; i < length; i++)
            characters[i] = char(bytes[i]);

        return {std::string (characters, length)};
    }
}