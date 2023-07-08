#pragma once

#include <string>

#include "../../../lib/imports/magic_enum/magic_enum_all.hpp"

namespace tdx_models{
    enum struct tdx_string_encoding{
        ASCII = 0,
        UTF_8 = 1,
        UTF_16 = 2,
        UTF_32 = 3
    };

    std::string get_encoding_name(tdx_string_encoding encoding){
        return "";
    }
}