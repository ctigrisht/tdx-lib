#pragma once

#include <cstdint>

#include "../../models/values/tdx_value.hpp"
#include "../../models/values/tdx_values.hpp"

using namespace tdx_values;

namespace internal_serializers {
    bytes_uptr serialize_string(tdx_string value);

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

    bytes_uptr serialize_document();

    bytes_uptr serialize_guid();

    bytes_uptr serialize_uint64_id();

    bytes_uptr serialize_link_ref();
}