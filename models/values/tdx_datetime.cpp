#include "values_cpp_includes.hpp"

namespace tdx_values{
    tdx_datetime tdx_datetime::now() {
        std::chrono::time_point point = std::chrono::system_clock::now();
        auto ticks = point.time_since_epoch().count();
    }
}