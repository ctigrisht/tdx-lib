#pragma once

#include <string>

#include "../shared_types.hpp"
#include "../string_encoding.hpp"
#include "tdx_value.hpp"

namespace tdx_values{
    class tdx_string final : public tdx_value {
    public:
        tdx_string();

        explicit tdx_string(std::string l_value);

        tdx_value_type get_type() final { return tdx_value_type::string; }

        bool is_null = true;

        std::optional<std::string> value_u8;

//        const_sptr<std::u8string> u8value;
//        const_sptr<std::u16string> u16value;
//        const_sptr<std::u32string> u32value;

        tdx_models::tdx_string_encoding encoding;

        byte_vector serialize() final;
        [[nodiscard]]
        const std::optional<std::string>& to_string() const;

        static tdx_string parse(byte_vector value);

        ~tdx_string() final{

        }
    };
}