#include "tdx_document.hpp"

namespace tdx_models {
    std::variant<byte_vector, std::string> tdx_sub_document::serialize() {
        auto ret_bytes = byte_vector{
            std::byte(0),
            std::byte(5),
        };

        throw;
//        ret_bytes.reserve(2);
    }

    std::variant<tdx_sub_document, std::string> tdx_sub_document::parse(byte_vector &bytes) {
        throw;
    }
}