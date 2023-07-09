#include <iostream>

#include "main.hpp"

#include "includes.hpp"


extern "C" int serialize(){
    auto doc = new tdx_values::tdx_blob_ref{
        .is_null = false,
        .value = std::make_optional<std::string>()
    };

    return 0;
}