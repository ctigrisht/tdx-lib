#pragma once

#include "shared.hpp"

void test_uint16() {
    std::cout << std::endl << "TESTS: tdx_uint16" << std::endl;

    std::vector<std::uint_fast16_t> tests{
            65000,
            0,
            2943
    };

    for (std::uint_fast16_t test_value: tests) {
        tdx_values::tdx_uint16 tdx_val(test_value);

        auto result = tdx_val.serialize();
        auto parsed = tdx_values::tdx_uint16::parse(result.get_value());

        std::cout
                << "Test '" << test_value << "' "
                << (parsed.value.value() == test_value ? "passed" : "failed")
                << std::endl;
    }
}