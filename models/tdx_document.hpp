#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <variant>

#include "values/tdx_value.hpp"
#include "tdx_property.hpp"
#include "tdx_link.hpp"
// using namespace std;

namespace tdx_models{
    class tdx_document
    {
    private:
        /* data */
    public:
        std::optional<std::uint16_t> schema_id = std::nullopt; // if null, then a free document

        std::string header;
        std::unordered_map<std::string, tdx_property> values;
        std::vector<tdx_link> links;

        std::variant<byte_vector, std::string> serialize();
        static std::variant<tdx_document, std::string> parse(byte_vector& bytes);
    };

//    tdx_sub_document::tdx_sub_document(/* args */)
//    {
//
//    }
//
//    tdx_sub_document::~tdx_sub_document()
//    {
//
//    }
    
}