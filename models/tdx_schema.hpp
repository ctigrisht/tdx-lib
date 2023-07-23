#pragma once

#include <unordered_map>
#include <variant>

#include "includes.hpp"

namespace tdx_models{
    class tdx_property_constraint{
    public:
        std::uint16_t id;
        std::string name;

        tdx_values::tdx_value_type data_type;
        std::uint32_t array_max_size; // 0 for unlimited
    };

    class tdx_constrained_link{
    public:
        std::uint16_t id;
        std::string name;
    };

    class tdx_schema{
    public:
        std::uint16_t id;
        std::uint32_t table_id;

        std::string schema_name;

        std::unordered_map<std::string, tdx_property_constraint> constraint_map = {};
        std::unordered_map<std::string, tdx_constrained_link> constrained_links = {};

        std::variant<byte_vector, std::string> serialize();
        static std::variant<tdx_schema, std::string> parse(byte_vector& bytes);
    };
}