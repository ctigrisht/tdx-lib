#include <memory>
#include "tdx_values.hpp"
#include "../../lib/internal/serializers.hpp"
#include "../string_encoding.hpp"

namespace tdx_values {
    bytes_uptr tdx_null::serialize() {
        throw;
    }

    std::unique_ptr<tdx_value> tdx_null::parse(std::unique_ptr<std::byte[]> value) {
        throw;
    }

    tdx_datetime tdx_datetime::now() {
        std::chrono::time_point point = std::chrono::system_clock::now();
        auto ticks = point.time_since_epoch().count();
    }
}