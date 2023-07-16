#include "tdx_values.hpp"
#include "../../lib/internal/serializers.hpp"

namespace tdx_values{
    bytes_uptr tdx_null::serialize() {
        throw;
    }

    bytes_uptr tdx_string::serialize() {
        internal_serializers::serialize_string(*this);
    }

    tdx_datetime tdx_datetime::now() {
        std::chrono::time_point point = std::chrono::system_clock::now();
        auto ticks = point.time_since_epoch().count();
    }
}