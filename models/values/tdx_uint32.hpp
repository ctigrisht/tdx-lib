#pragma once

#include "values_cpp_includes.hpp"

namespace tdx_values{
    class tdx_uint32 final : public tdx_value {
    public:
        tdx_uint32() { value = std::nullopt; }

        explicit tdx_uint32(std::uint_fast32_t l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::uint32; }

        bool is_null = true;
        std::optional<std::uint_fast32_t> value;

        tdx_bytes_result serialize() final;
        static tdx_uint32 parse(byte_vector& value);
    };

}