#pragma once

#include "values_cpp_includes.hpp"

namespace tdx_values{
    class tdx_int32 final : public tdx_value {
    public:
        tdx_int32() { value = std::nullopt; }

        explicit tdx_int32(std::int_fast32_t l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::int32; }

        bool is_null = true;
        std::optional<std::int_fast32_t> value;

        byte_vector serialize() final;
        static tdx_int32 parse(byte_vector& value);
    };
}