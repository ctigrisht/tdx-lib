#include "parsers.hpp"
#include <string.h>

namespace internal_serializers {
    int32_t parse_int32(std::span<std::byte> &bytes) {
        std::int32_t cast_value;
        std::byte data_bytes[bytes.size()];

//        data_bytes[0] = bytes[0];
//        data_bytes[1] = bytes[1];
//        data_bytes[2] = bytes[2];
//        data_bytes[3] = bytes[3];

        auto type_size = sizeof(int32_t);

        memcpy(&cast_value, bytes.data(), type_size); // TODO SIGILL // TODO big endian

        return cast_value;
    }
}