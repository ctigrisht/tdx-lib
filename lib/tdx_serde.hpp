#pragma once

#include <cstdint>
#include <memory>

#include "../models/tdx_document.hpp"

namespace tdx_serde{
    tdx_models::tdx_document deserialize(){
        throw "Not implemented";
    }

    std::shared_ptr<std::byte[]> serialize(){
        throw "Not implemented";
    }
    
}