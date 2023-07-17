#include "values_cpp_includes.hpp"

namespace tdx_values{
    byte_vector tdx_null::serialize() {
        throw;
    }

    std::unique_ptr<tdx_value> tdx_null::parse(byte_vector value) {
        throw;
    }
}