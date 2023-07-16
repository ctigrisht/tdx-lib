#pragma once

#include <string>
#include "magic_enum/magic_enum.hpp"

namespace tdx_models
{
    enum struct tdx_string_encoding
    {
        ASCII = 0,
        UTF_8 = 1,
        UTF_16 = 2,
        UTF_32 = 3
    };

    //const tdx_string_encoding DEFAULT_STRING_ENCODING = tdx_string_encoding::UTF_8;

//    std::string get_encoding_name(tdx_string_encoding encoding)
//    {
//        return "";
//        //return (std::string)magic_enum::enum_name(encoding);
//    }
}