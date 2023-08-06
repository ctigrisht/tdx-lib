#pragma once

#include <string>
#include <memory>
#include "values/tdx_value.hpp"
//#include "values/tdx_values.hpp"

namespace tdx_models{
    class tdx_property{
    public:
        std::string name;
//        std::unique_ptr<tdx_values::tdx_value> value;
    };
}