#pragma once

#include <string>
#include <memory>
#include <iostream>

#include "values_cpp_includes.hpp"
#include "magic_enum/magic_enum.hpp"
#include "../shared_types.hpp"
#include "tdx_type.hpp"

namespace tdx_values {
    class tdx_value {
    private:
    public:
        tdx_value() = default;

        virtual tdx_result serialize() = 0; // returns result or error code

        //static std::unique_ptr<tdx_value> parse_agnostic(byte_vector data);

        virtual tdx_value_type get_type() = 0;

        virtual ~tdx_value() {

        }

//        std::string get_type_name() {
//            return (std::string) magic_enum::enum_name(get_type());
//            //return "";
//        }
    };
}
