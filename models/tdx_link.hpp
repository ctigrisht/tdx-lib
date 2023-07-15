#pragma once

#include <string>
#include <optional>
#include "values/tdx_value.hpp"
#include "tdx_property.hpp"

namespace tdx_models
{
    class tdx_link
    {
    private:
    public:
        std::uint64_t primary_collection_id;
        std::uint64_t sticky_collection_id;

        bool is_null = true;
        bool is_relation_static = false;
        std::optional<std::uint64_t> relation_id = std::nullopt;
        std::optional<std::string> relation_name = std::nullopt;

        tdx_property linked_property;
//        std::unordered_map<std::string, >
    };
}