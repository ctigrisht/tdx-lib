#pragma once

#include <bit>

//#define BIG_ENDIAN 0
//#define LITTLE_ENDIAN 1

namespace tdx_internal {

    enum struct system_byte_order {
        SBO_BIG_ENDIAN = 0,
        SBO_LITTLE_ENDIAN = 1
    };

    static system_byte_order BYTE_ORDER;

    system_byte_order get_system_byte_order() {
        if constexpr(std::endian::native == std::endian::big)
        {
            BYTE_ORDER = system_byte_order::SBO_BIG_ENDIAN;
        }
        else if constexpr(std::endian::native == std::endian::little)
        {
            BYTE_ORDER = system_byte_order::SBO_LITTLE_ENDIAN;
        }
        else
        {
            throw "Machine needs to be LE or BE";
        }
    }

}
