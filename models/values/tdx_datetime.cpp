#include "values_cpp_includes.hpp"

#include <cstdint>

namespace tdx_values{
//    tdx_datetime::tdx_datetime(std::int_fast64_t l_value)

    byte_vector tdx_datetime::serialize() {
        return {};
    }

    tdx_datetime tdx_datetime::parse(byte_vector& value) {
        return {};
    }

    tdx_datetime tdx_datetime::now() {
        std::chrono::time_point point = std::chrono::system_clock::now();
        auto ticks = point.time_since_epoch().count();

        return {ticks};
    }
}