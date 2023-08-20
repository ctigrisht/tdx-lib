#pragma once

#include "values_cpp_includes.hpp"

namespace tdx_values{

    class tdx_json final : public tdx_value {
    public:
        tdx_json() { value = std::nullopt; }

        explicit tdx_json(nlohmann::json l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::json; }

        bool is_null = true;
        std::optional<nlohmann::json> value;

        tdx_bytes_result serialize() final;
        static tdx_json parse(byte_vector value);
    };
}