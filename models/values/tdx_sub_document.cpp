#include "tdx_sub_document.hpp"
#include "../tdx_property.hpp"

namespace tdx_values {
    tdx_sub_document::tdx_sub_document(std::unordered_map<std::string, std::unique_ptr<tdx_property, tdx_property_deleter>> l_value) {
        value = std::move(l_value);
    }

    tdx_bytes_result tdx_sub_document::serialize() {
        return (false);
    }

    tdx_sub_document tdx_sub_document::parse(byte_vector &value) {
        return {};
    }
}