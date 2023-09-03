#pragma once

#include "typedefs/tdx_property.hpp"

namespace tdx_models{
    struct tdx_property_deleter{
        void operator()(tdx_property* p) const;
    };
}