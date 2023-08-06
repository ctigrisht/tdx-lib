#pragma once

#include "values_cpp_includes.hpp"

namespace tdx_values{
    class tdx_float64 final : public tdx_value {
    public:
        tdx_float64() { value = std::nullopt; }

        explicit tdx_float64(double l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::float64; }

        bool is_null = true;
        std::optional<double> value;

        tdx_result serialize() final;
        static tdx_float64 parse(byte_vector& value);
    };

}