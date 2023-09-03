#pragma once

#include <string>
#include <memory>
#include "values/extern_includes.hpp"
#include "typedefs/tdx_value.hpp"

namespace tdx_models{
    class tdx_property{
    public:
        std::string name;
        std::unique_ptr<tdx_values::tdx_value> value;
    };
}