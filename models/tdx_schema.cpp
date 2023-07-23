#include "tdx_schema.hpp"

namespace tdx_models{
    std::variant<byte_vector, std::string> tdx_schema::serialize() {
        throw;
    }

    std::variant<tdx_schema, std::string> tdx_schema::parse(byte_vector &bytes) {

        throw;
    }
}