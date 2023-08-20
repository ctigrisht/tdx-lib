#pragma once

#include "values_cpp_includes.hpp"

namespace tdx_values{
    class tdx_blob_ref final : public tdx_value {
    public:
        tdx_blob_ref() { value = std::nullopt; }

        explicit tdx_blob_ref(std::string l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::blob_ref; }

        bool is_null = true;
        std::optional<std::string> value;

        tdx_bytes_result serialize() final;
        static tdx_blob_ref parse(byte_vector value);
    };
}