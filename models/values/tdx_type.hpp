#pragma once

#include <array>
#include "result.hpp"

namespace tdx_values {
    enum struct tdx_value_type : int32_t {
        null = 0,
        string = 10,
        boolean = 20,
        int16 = 30,
        int32 = 40,
        int64 = 50,
        int128 = 51, // TODO
        uint16 = 60,
        uint32 = 70,
        uint64 = 80,
        uint128 = 90, // TODO
        float32 = 100,
        float64 = 110,
        float128 = 120, // TODO
        decimal = 130, // TODO
        datetime = 140,
        timespan = 150,
        daterange = 141,
        blob = 160,
        blob_ref = 170,
        json = 180, // TODO !!bug!!
        document = 190, // TODO

        guid = 1000,
        uint64_id = 1010,

        array = 1100,

        // relationships
        link_ref = 5000,
    };

    static vr::result<std::array<std::byte, 2>, std::string> get_type_code(tdx_value_type type) {
        switch (type) {
            case tdx_value_type::null:
                return {{stdbyte(0), stdbyte(1)}};
            case tdx_value_type::string:
                return {{stdbyte(10), stdbyte(8)}};
            case tdx_value_type::boolean:
                return {{stdbyte(11), stdbyte(1)}};
            case tdx_value_type::int16:
                return {{stdbyte(20), stdbyte(16)}};
            case tdx_value_type::int32:
                return {{stdbyte(20), stdbyte(32)}};
            case tdx_value_type::int64:
                return {{stdbyte(20), stdbyte(64)}};
            case tdx_value_type::int128:
                return {{stdbyte(20), stdbyte(128)}};
            case tdx_value_type::uint16:
                return {{stdbyte(21), stdbyte(16)}};
            case tdx_value_type::uint32:
                return {{stdbyte(21), stdbyte(32)}};
            case tdx_value_type::uint64:
                return {{stdbyte(21), stdbyte(64)}};
            case tdx_value_type::uint128:
                return {{stdbyte(21), stdbyte(128)}};
            case tdx_value_type::float32:
                return {{stdbyte(30), stdbyte(32)}};
            case tdx_value_type::float64:
                return {{stdbyte(30), stdbyte(64)}};
            case tdx_value_type::float128:
                return {{stdbyte(30), stdbyte(128)}};
            case tdx_value_type::decimal:
                return {{stdbyte(31), stdbyte(128)}};
            case tdx_value_type::datetime:
                return {{stdbyte(41), stdbyte(0)}};
            case tdx_value_type::timespan:
                return {{stdbyte(41), stdbyte(1)}};
            case tdx_value_type::daterange:
                return {{stdbyte(41), stdbyte(2)}};
            case tdx_value_type::blob:
                return {{stdbyte(50), stdbyte(0)}};
            case tdx_value_type::blob_ref:
                return {{stdbyte(50), stdbyte(1)}};
            case tdx_value_type::json:
                return {{stdbyte(60), stdbyte(0)}};
            case tdx_value_type::document:
                return {{stdbyte(60), stdbyte(1)}};
            case tdx_value_type::guid:
                return {{stdbyte(70), stdbyte(0)}};
            case tdx_value_type::uint64_id:
                return {{stdbyte(70), stdbyte(1)}};
            case tdx_value_type::array:
                return {{stdbyte(100), stdbyte(0)}};
            case tdx_value_type::link_ref:
                return {{stdbyte(254), stdbyte(0)}};
            default:
                return {"Invalid type"};
        };
    }
}