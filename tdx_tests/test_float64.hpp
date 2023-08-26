#pragma once

#include "shared.hpp"


void test_float64() {
    auto test_name = "TESTS: tdx_float64";
    TEST_RESULTS[test_name] = {};
    std::cout << std::endl << test_name << std::endl;

    std::vector<double> tests{
            0,
            329048.03342,
            98458449.92382,
            -934923.43243,
            -342
    };

    for (double test_value: tests) {
        tdx_values::tdx_float64 tdx_val(test_value);

        auto result = tdx_val.serialize();

        auto& bytes = result.get_value();

        auto parsed = tdx_values::tdx_float64::parse(bytes);

        auto passed = parsed.value.value() == test_value;
        std::cout
                << "Test '" << test_value << "' "
                << (passed ? "passed" : "failed")
                << std::endl;

        if (passed)
            TEST_RESULTS[test_name].passed++;
        else TEST_RESULTS[test_name].failed++;
    }
}