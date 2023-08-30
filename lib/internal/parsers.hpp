#pragma once

#include <array>
#include <cstdint>
#include <span>

namespace internal_serializers{
    int32_t parse_int32(std::span<std::byte>& bytes);
}