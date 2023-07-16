#include "serializers.hpp"

#include <bit>
#include <iostream>
#include <memory>

#include "endian_tester.hpp"
#include "../../models/values/tdx_values.hpp"
#include "../../models/string_encoding.hpp"

using namespace tdx_internal;
using namespace tdx_models;
using namespace tdx_values;

namespace internal_serializers {
    bytes_uptr serialize_string_utf8(const_sptr<std::u8string> value) {
        int length = value->length();

        auto ret_bytes = std::make_unique<std::byte[]>(length);

        std::byte tmp_bytes[length];

        std::transform(
                value->begin(),
                value->end(),
                tmp_bytes,
                [](const char& character){
                    return std::byte(character);
                });

        for (int i = 0; i < length; i++)
            ret_bytes[i] = tmp_bytes[i];

        return std::move(ret_bytes);
    }

    bytes_uptr serialize_string_utf16(const_sptr<std::u16string> value) {
        throw "UTF-16 not implemented";
//        int length = value->length();
//
//        std::byte bytes[length];
//        std::transform(
//                value->begin(),
//                value->end(),
//                bytes,
//                [](const char& character){
//                    return std::byte(character);
//                });
    }

    bytes_uptr serialize_string_utf32(const_sptr<std::u32string> value) {
        throw "UTF-32 not implemented";
    }
    bytes_uptr serialize_string(tdx_string value) {
        switch (value.encoding) {
            case tdx_string_encoding::UTF_8:
                return serialize_string_utf8(value.u8value);
            case tdx_string_encoding::UTF_16:
                return serialize_string_utf16(value.u16value);
            case tdx_string_encoding::UTF_32:
                return serialize_string_utf32(value.u32value);
            default: throw "Encoding not implemented";
        }
    }

//    bytes_uptr serialize_int8();
//    bytes_uptr serialize_uint8();
    bytes_uptr serialize_int16(tdx_int16 value);

    bytes_uptr serialize_uint16(tdx_uint16 value);

    bytes_uptr serialize_int32(tdx_int32 value);

    bytes_uptr serialize_uint32(tdx_uint32 value);

    bytes_uptr serialize_int64(tdx_int64 value);

    bytes_uptr serialize_uint64(tdx_uint64 value);

//    bytes_uptr serialize_int128();
//    bytes_uptr serialize_uint128();
    bytes_uptr serialize_float32(tdx_float32 value);

    bytes_uptr serialize_float64(tdx_float64 value);

//    bytes_uptr serialize_decimal128(tdx_decimal value);

    bytes_uptr serialize_blob(tdx_blob value);

    bytes_uptr serialize_blob_ref(tdx_blob_ref value);

    bytes_uptr serialize_json(tdx_json value);

    bytes_uptr serialize_document(tdx_document value);

//    bytes_uptr serialize_guid();
//
//    bytes_uptr serialize_uint64_id();
//
//    bytes_uptr serialize_link_ref();
}