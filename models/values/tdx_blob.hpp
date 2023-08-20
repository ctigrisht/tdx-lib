#pragma once

#include "values_cpp_includes.hpp"

namespace tdx_values{
    class tdx_blob final : public tdx_value {
    public:
        tdx_blob() = default;

        explicit tdx_blob(byte_vector& ref_value) {
//            value = std::make_optional<bytes_uptr>(l_value);
            value = byte_vector(ref_value);
            is_null = false;
        }

//        explicit tdx_blob(byte_vector l_value) {
////            value = std::make_optional<bytes_uptr>(l_value);
//            value = std::make_unique<byte_vector>(std::move(l_value));
//            is_null = false;
//        }
//        explicit tdx_blob(std::unique_ptr<byte_vector> l_value){
//            value = std::move(l_value);
//            is_null = false;
//        }

        tdx_value_type get_type() final { return tdx_value_type::blob; }

        bool is_null = true;
        std::optional<byte_vector> value = std::nullopt;


        tdx_bytes_result serialize() final;
        static tdx_blob parse(byte_vector& value);
        static tdx_blob from_copy(byte_vector l_value);
    };
}