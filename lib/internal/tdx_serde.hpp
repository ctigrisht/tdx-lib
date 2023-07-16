#pragma once

// #include <cstdint>
// #include <memory>
// #include <vector>

#include "../../models/tdx_document.hpp"

namespace tdx_serde{
    tdx_models::tdx_document _deserialize();

    std::unique_ptr<std::byte[]> _serialize();
    
}