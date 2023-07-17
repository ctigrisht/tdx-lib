#include "values_cpp_includes.hpp"
#include "tdx_string.hpp"

#include <string>

using namespace tdx_models;

namespace tdx_values {
    byte_vector serialize_string_utf8(std::string& value);

    tdx_string::tdx_string() {
        value_u8 = std::nullopt;
        encoding = tdx_string_encoding::UTF_8;
//        u8value = nullptr;
//        u16value = nullptr;
//        u32value = nullptr;
    }

    tdx_string::tdx_string(std::string l_value) {
        value_u8 = std::move(l_value);
        encoding = tdx_models::tdx_string_encoding::UTF_8;
        is_null = false;
    }

//    tdx_string::tdx_string(const_sptr<std::u8string> l_value) {
//        u8value = l_value;
//        encoding = tdx_models::tdx_string_encoding::UTF_8;
//        is_null = false;
//    }

//    tdx_string::tdx_string(const_sptr<std::u16string> l_value) {
//        u16value = l_value;
//        encoding = tdx_models::tdx_string_encoding::UTF_16;
//        is_null = false;
//    }
//
//    tdx_string::tdx_string(const_sptr<std::u32string> l_value) {
//        u32value = l_value;
//        encoding = tdx_models::tdx_string_encoding::UTF_32;
//        is_null = false;
//    }

    byte_vector tdx_string::serialize() {
        switch (this->encoding) {
            case tdx_string_encoding::UTF_8:{
                if (this->value_u8.has_value())
                    return serialize_string_utf8(this->value_u8.value());
                return {};
            }
            case tdx_string_encoding::UTF_16:
                throw;
            case tdx_string_encoding::UTF_32:
                throw;
            default:
                throw "Encoding not implemented";
        };
    }

    tdx_string tdx_string::parse(byte_vector value) {
        auto length = value.size();

        char characters[length];
        for (int i = 0; i < length; i++)
            characters[i] = char(value[i]);

        std::string final_string(characters, length);

        return tdx_string(std::string(final_string));
    }

    const std::optional<std::string> &tdx_string::to_string() const {
        switch (this->encoding) {
            case tdx_string_encoding::UTF_8: {
                return this->value_u8;
            }

            default:
                throw "Encoding not supported";
        }
    }

    byte_vector serialize_string_utf8(std::string& value) {
        uint length = value.length();

        std::byte tmp_bytes[length];
        std::transform(
                value.begin(),
                value.end(),
                tmp_bytes,
                [](const char &character) {
                    return std::byte(character);
                });

        byte_vector ret_bytes;

        for (int i = 0; i < length; i++)
            ret_bytes.push_back(tmp_bytes[i]);

        return std::move(ret_bytes);
    }

}