#pragma once

#include <cstdint>

#include "../../models/values/extern_includes.hpp"

using namespace tdx_values;

namespace internal_serializers {
    byte_vector serialize_string_utf8(std::string& value);
//    byte_vector serialize_string_utf16(std::u16string& value);
//    byte_vector serialize_string_utf32(std::u32string& value);
//
//    byte_vector serialize_string(tdx_string& value);
//
////    bytes_uptr serialize_int8();
////    bytes_uptr serialize_uint8();
//    byte_vector serialize_int16(tdx_int16& value);
//
//    byte_vector serialize_uint16(tdx_uint16& value);
//
//    byte_vector serialize_int32(tdx_int32& value);
    std::array<stdbyte, 4> serialize_int32(int32_t value);

//    byte_vector serialize_uint32(tdx_uint32& value);
//
//    byte_vector serialize_int64(tdx_int64& value);
//
//    byte_vector serialize_uint64(tdx_uint64& value);

//    bytes_uptr serialize_int128();
//    bytes_uptr serialize_uint128();
//    byte_vector serialize_float32(tdx_float32& value);
//
//    byte_vector serialize_float64(tdx_float64& value);

//    bytes_uptr serialize_decimal128(tdx_decimal value);

//    byte_vector serialize_blob(tdx_blob& value);
//
//    byte_vector serialize_blob_ref(tdx_blob_ref& value);
//
//    byte_vector serialize_json(tdx_json& value);
//
//    byte_vector serialize_document(tdx_document& value);

//    bytes_uptr serialize_guid();
//
//    bytes_uptr serialize_uint64_id();
//
//    bytes_uptr serialize_link_ref();
}