#pragma once

#include <array>
#include <cstdint>
#include <span>
#include "result.hpp"
#include <vector>

namespace internal_serializers{
    int32_t parse_int32(std::span<std::byte>& bytes);
    uint16_t parse_uint16(std::array<std::byte, 2> bytes);
    vr::result<std::string, uint32_t> parse_native_string(std::span<std::byte>& bytes);
}