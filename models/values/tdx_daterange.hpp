#pragma once

#include "values_cpp_includes.hpp"

#include <chrono>

namespace tdx_values {
    class tdx_daterange final : public tdx_value {
    public:
        tdx_daterange() {
            value = std::nullopt;
        }

        explicit tdx_daterange(std::array<int64_t, 2> utc_values) {
            if (utc_values[1] < utc_values[0])
                throw std::runtime_error("The first element in the range should be smaller than the last");
            value = utc_values;
        }

        explicit tdx_daterange(int64_t l_value) {
            auto utc_now = std::chrono::utc_clock::now();
            int64_t time_now = utc_now.time_since_epoch().count();
            if (l_value > time_now)
                value = {time_now, l_value};
            else value = {l_value, time_now};
        }

        tdx_value_type get_type() final { return tdx_value_type::datetime; }

        std::optional<std::array<int64_t, 2>> value = std::nullopt;

        tdx_bytes_result serialize() final;

        static tdx_daterange parse(std::span<stdbyte> &value);
    };
}