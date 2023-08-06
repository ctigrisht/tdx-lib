#pragma once

#include "values_cpp_includes.hpp"

namespace tdx_values{

    class tdx_int64 final : public tdx_value {
    public:
        tdx_int64() { value = std::nullopt; }

        explicit tdx_int64(std::int_fast64_t l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::int64; }

        bool is_null = true;
        std::optional<std::int_fast64_t> value;

        tdx_result serialize() final;
        static tdx_int64 parse(byte_vector& value);
    };
}