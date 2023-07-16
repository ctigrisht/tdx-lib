#pragma once

#include <string>
#include <memory>

#include "magic_enum/magic_enum.hpp"
#include "../shared_types.hpp"

namespace tdx_values {
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
        blob = 14,
        blob_ref = 15,
        json = 16,
        document = 17,

        guid = 100,
        uint64_id = 101,

        // relationships
        link_ref = 500,
    };

    class tdx_value {
    private:
    public:
        tdx_value();

        virtual ~tdx_value();

        virtual bytes_uptr serialize();

        virtual tdx_value_type get_type();

        std::string get_type_name() {
            return (std::string) magic_enum::enum_name(get_type());
            //return "";
        }
    };

}
