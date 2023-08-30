#include "parsers.hpp"
#include <memory>

namespace internal_serializers {
    int32_t parse_int32(std::span<std::byte> &bytes) {
        std::int_fast32_t cast_value;
        memcpy(&cast_value, bytes.data(), sizeof(int32_t));
    }
}