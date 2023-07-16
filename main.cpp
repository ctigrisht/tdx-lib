#include <iostream>

#include "main.hpp"

#include "includes.hpp"


extern "C" int serialize(){
    tdx_values::tdx_string doc = tdx_values::tdx_string(
            std::make_shared<std::u8string>(u8"hello"));

//    tdx_values::tdx_blob_ref blob;

    doc.is_null = true;

    return 0;
}