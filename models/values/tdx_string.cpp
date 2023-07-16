#include "includes.hpp"

namespace tdx_values{

    tdx_string::tdx_string() {
        u8value = nullptr;
        u16value = nullptr;
        u32value = nullptr;
    }

    tdx_string::tdx_string(const_sptr<std::u8string> l_value) {
        u8value = l_value;
        encoding = tdx_models::tdx_string_encoding::UTF_8;
        is_null = false;
    }

    tdx_string::tdx_string(const_sptr<std::u16string> l_value) {
        u16value = l_value;
        encoding = tdx_models::tdx_string_encoding::UTF_16;
        is_null = false;
    }

    tdx_string::tdx_string(const_sptr<std::u32string> l_value) {
        u32value = l_value;
        encoding = tdx_models::tdx_string_encoding::UTF_32;
        is_null = false;
    }

    bytes_uptr tdx_string::serialize() {
//        internal_serializers::serialize_string(*this);
        switch (this->encoding) {
            case tdx_models::tdx_string_encoding::UTF_8:
                return internal_serializers::serialize_string_utf8(this->u8value);
            case tdx_models::tdx_string_encoding::UTF_16:
                return internal_serializers::serialize_string_utf16(this->u16value);
            case tdx_models::tdx_string_encoding::UTF_32:
                return internal_serializers::serialize_string_utf32(this->u32value);
            default:
                throw "Encoding not implemented";
        }
    }

    std::unique_ptr<tdx_value> tdx_string::parse(std::unique_ptr<std::byte[]> value){
        return nullptr;
    }

    tdx_string::~tdx_string() {}
}