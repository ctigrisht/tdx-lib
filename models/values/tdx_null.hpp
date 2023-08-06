#pragma once


#include "values_cpp_includes.hpp"

namespace tdx_values {
    static const std::array<stdbyte, 2> NULL_FLAG {
        stdbyte (1), stdbyte (250)
    };

    class tdx_null final : public tdx_value {
    public:
        tdx_null() = default;

        tdx_value_type get_type() final { return tdx_value_type::null; }

        std::uint_least32_t padding_size;

        tdx_result serialize() final;
        static tdx_null parse(byte_vector& value);
    };
}