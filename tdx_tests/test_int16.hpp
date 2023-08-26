#pragma once

#include "shared.hpp"

void test_int16() {
    std::cout << std::endl << "TESTS: tdx_int16" << std::endl;

    std::vector<std::int_fast16_t> tests{
            1,
            10230,
            -4430,
            -32
    };

    for (std::int_fast16_t value: tests) {
//        std::cout << "Testing: " << value;

        tdx_values::tdx_int16 i16 = tdx_values::tdx_int16(value);

        auto result = i16.serialize();
        auto parsed = tdx_values::tdx_int16::parse(result.get_value());

        std::cout
                << "Test '" << value << "' "
                << (parsed.value.value() == value ? "passed" : "failed")
                << std::endl;
//        std::cout << " : " << parsed.value.value() << std::endl;
    }
}