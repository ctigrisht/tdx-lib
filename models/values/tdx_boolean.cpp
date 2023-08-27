#include "tdx_boolean.hpp"

#include <span>

namespace tdx_values{
    tdx_bytes_result tdx_boolean::serialize() {
        if (!value.has_value())
            return (false);
        return {{value.value() == 0 ? stdbyte(0): stdbyte(1)}};
    }

    tdx_boolean tdx_boolean::parse(stdbyte &bytes) {
        if (bytes == stdbyte(0))
            return {false};
        else return {true};
    }
}