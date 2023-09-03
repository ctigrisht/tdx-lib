#pragma once

#include <variant>

#include "tdx_document.hpp"
#include "tdx_schema.hpp"

namespace tdx_models{
    class tdx_document_set{
    public:
        std::optional<std::unordered_map<std::uint16_t, tdx_schema>> schemas = std::nullopt; // if null, all documents are free documents
        std::vector<tdx_sub_document> documents = {};

        std::variant<byte_vector, std::string> serialize();

        static std::variant<tdx_document_set, std::string> parse(byte_vector& bytes);
    };
}