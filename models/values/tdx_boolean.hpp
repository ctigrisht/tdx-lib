#pragma once

#include <span>

#include "values_cpp_includes.hpp"

namespace tdx_values {
    class tdx_boolean final : public tdx_value {
    public:
        tdx_boolean(){
            value = std::nullopt;
        }

        tdx_boolean(bool l_value){
            value = l_value;
        }

        std::optional<bool> value;

        tdx_value_type get_type() final { return tdx_value_type::boolean; }
        tdx_bytes_result serialize() final;

        static tdx_boolean parse(stdbyte &bytes);
    };
}