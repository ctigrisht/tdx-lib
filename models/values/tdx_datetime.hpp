#pragma once

#include "values_cpp_includes.hpp"

namespace tdx_values{
    class tdx_datetime final : public tdx_value {
    public:
        tdx_datetime() {
            value = std::nullopt;
        }

        tdx_datetime(std::chrono::time_point<std::chrono::system_clock> l_value) {
            value = l_value.time_since_epoch().count();
        }

        tdx_datetime(std::int_fast64_t l_value){
            value = l_value;
        }

        tdx_value_type get_type() final { return tdx_value_type::datetime; }

        bool is_null = true;
        std::optional<std::int_fast64_t> value;


        byte_vector serialize() final;
        static tdx_datetime parse(byte_vector& value);
        static tdx_datetime now();
    };
}