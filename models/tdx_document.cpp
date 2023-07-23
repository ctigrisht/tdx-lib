#include "tdx_document.hpp"

namespace tdx_models {
    std::variant<byte_vector, std::string> tdx_document::serialize() {
        auto ret_bytes = byte_vector{
            std::byte(0),
            std::byte(5),
        };
//        ret_bytes.reserve(2);


    }

    std::variant<tdx_document, std::string> tdx_document::parse(byte_vector &bytes) {
        throw;
    }
}