#include "values_cpp_includes.hpp"

#include <string>

using namespace tdx_models;

namespace tdx_values{

    tdx_string::tdx_string() {
        value_u8 = nullptr;
//        u8value = nullptr;
//        u16value = nullptr;
//        u32value = nullptr;
    }

    tdx_string::tdx_string(const_sptr<std::string> l_value) {
        value_u8 = l_value;
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
        return internal_serializers::serialize_string(*this);
    }

    tdx_string tdx_string::parse(byte_vector value){
        auto length = value.size();

        char characters[length];
        for (int i = 0; i < length; i++)
            characters[i] = char(value[i]);

        std::string final_string(characters, length);

        return tdx_string(std::make_unique<const std::string>(final_string));
    }

    std::string tdx_string::to_string() {
        switch (this->encoding) {
            case tdx_string_encoding::UTF_8:
            {
                throw "noimpl";
//                auto val =value_u8.get();
//                return val;
//                auto length = this->u8value->length();
//                char chars[length];
//                auto u8str = this->u8value.get();
//                for (auto i = 0; i < length; i++)
//                    chars[i] = u8str[0][i];
//
//                return std::string(chars, length);
            }

            default: throw "Encoding not supported";
        }
    }

    tdx_string::~tdx_string() {}
}