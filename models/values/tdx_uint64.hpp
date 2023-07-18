#pragma once

#include "values_cpp_includes.hpp"

namespace tdx_values{
    class tdx_uint64 final : public tdx_value {
    public:
        tdx_uint64() { value = std::nullopt; }

        explicit tdx_uint64(std::uint_fast64_t l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::uint64; }

        bool is_null = true;
        std::optional<std::uint_fast64_t> value;

        byte_vector serialize() final;
        static tdx_uint64 parse(byte_vector& value);
    };
}