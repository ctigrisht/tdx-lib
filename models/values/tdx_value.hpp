#pragma once

#include <string>
#include <memory>
#include <iostream>
#include "magic_enum/magic_enum.hpp"
#include "../shared_types.hpp"
#include "tdx_type.hpp"
#include "typedefs.hpp"
//#include "../intermediate_includes.hpp"

namespace tdx_values {
    class tdx_value {
    private:
    public:
        tdx_value() = default;

        virtual tdx_bytes_result serialize() = 0; // returns result or error code

        //static std::unique_ptr<tdx_value> parse_agnostic(byte_vector data);

        virtual tdx_value_type get_type() = 0;

        virtual ~tdx_value() {}
    };
}
