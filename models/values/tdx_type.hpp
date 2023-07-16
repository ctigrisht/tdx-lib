#pragma once

namespace tdx_values{
    enum struct tdx_value_type : int_fast32_t {
        null = 0,
        string = 1,
        int16 = 2,
        int32 = 3,
        int64 = 4,
        // int128 = 5,
        uint16 = 6,
        uint32 = 7,
        uint64 = 8,
        // uint128 = 9,
        float32 = 10,
        float64 = 11,
        // float128 = 12,
        decimal = 13,
        datetime = 14,
        timespan = 15,
        blob = 16,
        blob_ref = 17,
        json = 18,
        document = 19,

        guid = 100,
        uint64_id = 101,

        array = 110,

        // relationships
        link_ref = 500,
    };
}