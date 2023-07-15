#include <iostream>

#include "main.hpp"

#include "includes.hpp"


extern "C" int serialize(){
    tdx_values::tdx_blob_ref doc = tdx_values::tdx_blob_ref();

//    tdx_values::tdx_blob_ref blob;

    doc.is_null = true;

    return 0;
}