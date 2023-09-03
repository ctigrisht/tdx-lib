#pragma once

#include "values_cpp_includes.hpp"
#include <unordered_map>
#include "../typedefs/tdx_property_for_document.hpp"
#include "tdx_value.hpp"

//#include "../typedefs/tdx_property.hpp"

namespace tdx_values{

    class tdx_document final : public tdx_value {
    public:
        tdx_document(){ }
        tdx_document(std::unordered_map<std::string, tdx_models::tdx_property> l_value){
            value = std::move(l_value);
        }

        tdx_document(std::unordered_map<std::string, tdx_values::tdx_value> l_value){

        }

        std::optional<std::unordered_map<std::string, tdx_models::tdx_property>> value = std::nullopt;
        bool is_free = true;

        tdx_value_type get_type() final { return tdx_value_type::document; }

        tdx_bytes_result serialize() final;
        static tdx_document parse(byte_vector& value);

        bool contains_key(std::string& key);
        vr::result<bool, tdx_models::tdx_property> try_get_key(std::string& key);
    };
}