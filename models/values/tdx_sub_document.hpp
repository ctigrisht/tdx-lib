#pragma once

#include "values_cpp_includes.hpp"
#include <unordered_map>
#include "../typedefs/tdx_property.hpp"
#include "tdx_value.hpp"
#include "../tdx_property_deleter.hpp"

using namespace tdx_models;

typedef std::unordered_map<std::string, std::unique_ptr<tdx_property, tdx_property_deleter>> tdx_prop_map;

namespace tdx_values{

    class tdx_sub_document final : public tdx_value {
    public:
        tdx_sub_document(){ }
        tdx_sub_document(tdx_prop_map l_value);
        tdx_sub_document(std::unordered_map<std::string, tdx_values::tdx_value> l_value);

        std::optional<std::unordered_map<std::string, std::unique_ptr<tdx_property, tdx_property_deleter>>> value;
        bool is_free = true;

        tdx_value_type get_type() final { return tdx_value_type::document; }

        tdx_bytes_result serialize() final;
        static tdx_sub_document parse(byte_vector& value);

        bool contains_key(std::string& key);
        vr::result<bool, tdx_models::tdx_property> try_get_key(std::string& key);
    };
}