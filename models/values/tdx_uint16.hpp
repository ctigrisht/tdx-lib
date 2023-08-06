#pragma once

#include "values_cpp_includes.hpp"

namespace tdx_values{
    class tdx_uint16 final : public tdx_value {
    public:
        tdx_uint16() { value = std::nullopt; }

        explicit tdx_uint16(std::uint_fast16_t l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::uint16; }

        bool is_null = true;
        std::optional<std::uint_fast16_t> value;

        tdx_result serialize() final;
        static tdx_uint16 parse(byte_vector& value);
    };
}
