#pragma once

#include "values_cpp_includes.hpp"

namespace tdx_values{
    class tdx_int16 final : public tdx_value {
    public:
        tdx_int16() {
            value = std::nullopt;
        }

        explicit tdx_int16(std::int_fast16_t l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::int16; }

        bool is_null = true;
        std::optional<std::int_fast16_t> value;

        tdx_bytes_result serialize() final;
        static tdx_int16 parse(byte_vector& value);
    };
}