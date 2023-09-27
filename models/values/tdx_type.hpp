#pragma once

#include <array>
#include "result.hpp"
#include "../result_codes_table.hpp"

namespace tdx_values {
    enum struct tdx_value_type : int32_t {
        null = 0,
        string = 10,
        boolean = 20,
        int16 = 30,
        int32 = 40,
        int64 = 50,
        int128 = 51, // TODO later
        uint16 = 60,
        uint32 = 70,
        uint64 = 80,
        uint128 = 90, // TODO later
        float32 = 100,
        float64 = 110,
        float128 = 120, // TODO later
        decimal = 130, // TODO later
        datetime = 140,
        timespan = 150,
        daterange = 141,
        blob = 160,
        blob_ref = 170,
        json = 180,
        document = 190, // TODO

        guid = 1000,
        uint64_id = 1010,

        array = 1100,

        // relationships
        link_ref = 5000,
    };

    static vr::result<tdx_value_type, uint32_t> get_type_code(std::array<stdbyte, 2> bytes) {
        if (bytes[0] == stdbyte(0) && bytes[1] == stdbyte(1))
            return {tdx_value_type::null};
        if (bytes[0] == stdbyte(10) && bytes[1] == stdbyte(8))
            return {tdx_value_type::string};
        if (bytes[0] == stdbyte(11) && bytes[1] == stdbyte(1))
            return {tdx_value_type::boolean};
        if (bytes[0] == stdbyte(20) && bytes[1] == stdbyte(16))
            return {tdx_value_type::int16};
        if (bytes[0] == stdbyte(20) && bytes[1] == stdbyte(32))
            return {tdx_value_type::int32};
        if (bytes[0] == stdbyte(20) && bytes[1] == stdbyte(64))
            return {tdx_value_type::int64};
        if (bytes[0] == stdbyte(20) && bytes[1] == stdbyte(128))
            return {tdx_value_type::int128};
        if (bytes[0] == stdbyte(21) && bytes[1] == stdbyte(16))
            return {tdx_value_type::uint16};
        if (bytes[0] == stdbyte(21) && bytes[1] == stdbyte(32))
            return {tdx_value_type::uint32};
        if (bytes[0] == stdbyte(21) && bytes[1] == stdbyte(64))
            return {tdx_value_type::uint64};
        if (bytes[0] == stdbyte(21) && bytes[1] == stdbyte(128))
            return {tdx_value_type::uint128};
        if (bytes[0] == stdbyte(30) && bytes[1] == stdbyte(32))
            return {tdx_value_type::float32};
        if (bytes[0] == stdbyte(30) && bytes[1] == stdbyte(64))
            return {tdx_value_type::float64};
        if (bytes[0] == stdbyte(30) && bytes[1] == stdbyte(128))
            return {tdx_value_type::float128};
        if (bytes[0] == stdbyte(31) && bytes[1] == stdbyte(128))
            return {tdx_value_type::decimal};
        if (bytes[0] == stdbyte(41) && bytes[1] == stdbyte(0))
            return {tdx_value_type::datetime};
        if (bytes[0] == stdbyte(41) && bytes[1] == stdbyte(1))
            return {tdx_value_type::timespan};
        if (bytes[0] == stdbyte(41) && bytes[1] == stdbyte(2))
            return {tdx_value_type::daterange};
        if (bytes[0] == stdbyte(50) && bytes[1] == stdbyte(0))
            return {tdx_value_type::blob};
        if (bytes[0] == stdbyte(50) && bytes[1] == stdbyte(1))
            return {tdx_value_type::blob_ref};
        if (bytes[0] == stdbyte(60) && bytes[1] == stdbyte(0))
            return {tdx_value_type::json};
        if (bytes[0] == stdbyte(60) && bytes[1] == stdbyte(1))
            return {tdx_value_type::document};
        if (bytes[0] == stdbyte(70) && bytes[1] == stdbyte(0))
            return {tdx_value_type::guid};
        if (bytes[0] == stdbyte(70) && bytes[1] == stdbyte(1))
            return {tdx_value_type::uint64_id};
        if (bytes[0] == stdbyte(100) && bytes[1] == stdbyte(0))
            return {tdx_value_type::array};
        if (bytes[0] == stdbyte(254) && bytes[1] == stdbyte(0))
            return {tdx_value_type::link_ref};

        return {tdx_models::CODE_INVALID_DATA};
    }

    static vr::result<std::array<std::byte, 2>, std::uint32_t> get_type_code(tdx_value_type type) {
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
                return {tdx_models::CODE_UNSUPPORTED_ENUM};
        };
    }
}