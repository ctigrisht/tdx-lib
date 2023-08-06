#pragma once

#include "values_cpp_includes.hpp"

namespace tdx_values{
    class tdx_float32 final : public tdx_value {
    public:
        tdx_float32() { value = std::nullopt; }

        explicit tdx_float32(float l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::float32; }

        bool is_null = true;
        std::optional<float> value;

        tdx_result serialize() final;
        static tdx_float32 parse(byte_vector& value);
    };
}