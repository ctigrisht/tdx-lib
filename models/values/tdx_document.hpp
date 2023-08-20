#pragma once

#include "values_cpp_includes.hpp"
#include <unordered_map>

namespace tdx_values{

    class tdx_document final : public tdx_value {
    public:
        tdx_document(){ }
        explicit tdx_document(std::unordered_map<std::string, tdx_models::tdx_property> l_value){
            value = std::move(l_value);
        }

        std::optional<std::unordered_map<std::string, tdx_models::tdx_property>> value = std::nullopt;
        bool is_free = true;

        tdx_value_type get_type() final { return tdx_value_type::document; }

        tdx_bytes_result serialize() final;
        static tdx_document parse(byte_vector value);
    };
}