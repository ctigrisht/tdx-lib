#pragma once

#include "values_cpp_includes.hpp"
#include <chrono>

namespace tdx_values{
    static const std::string DEFAULT_TIME_ZONE_CODE = "utc";

    class tdx_datetime final : public tdx_value {
    public:
        tdx_datetime() {
            value = std::nullopt;
        }

        explicit tdx_datetime(std::chrono::time_point<std::chrono::system_clock> l_value) {
            value = l_value.time_since_epoch().count();
            time_zone = "utc";
            is_null = false;
        }

        explicit tdx_datetime(std::int_fast64_t l_value){
            value = l_value;
            time_zone = "utc";
            is_null = false;
        }


        tdx_datetime(std::chrono::time_point<std::chrono::system_clock> l_value_sc, std::string l_time_zone) {
            value = l_value_sc.time_since_epoch().count();
            time_zone = std::move(l_time_zone);
            is_null = false;
        }

        tdx_datetime(std::int_fast64_t l_value, std::string l_time_zone){
            value = l_value;
            time_zone = std::move(l_time_zone);
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::datetime; }

        bool is_null = true;
        std::optional<std::int_fast64_t> value;
        std::optional<std::string> time_zone = DEFAULT_TIME_ZONE_CODE;


        tdx_bytes_result serialize() final;
        static tdx_datetime parse(byte_vector& value);
        static tdx_datetime now();
    };
}