#pragma once

#include <string>
#include <memory>
#include <iostream>

#include "magic_enum/magic_enum.hpp"
#include "../shared_types.hpp"
#include "tdx_type.hpp"

namespace tdx_values {
    class tdx_value {
    private:
    public:
        tdx_value() { }

        virtual bytes_uptr serialize() = 0;
        virtual std::unique_ptr<tdx_value> parse(std::unique_ptr<std::byte[]> data) = 0;

        virtual tdx_value_type get_type() = 0;

        virtual ~tdx_value() {

        }

//        std::string get_type_name() {
//            return (std::string) magic_enum::enum_name(get_type());
//            //return "";
//        }
    };
}
