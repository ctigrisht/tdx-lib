#pragma once

#include "shared.hpp"


void test_float32() {
    auto test_name = "TESTS: tdx_float32";
    TEST_RESULTS[test_name] = {};
    std::cout << std::endl << test_name << std::endl;

    std::vector<float> tests{
            0,
            9048.0334,
            3449.9238,
            -9349.432,
            -342
    };

    for (float test_value: tests) {
        tdx_values::tdx_float32 tdx_val(test_value);

        auto result = tdx_val.serialize();
        auto parsed = tdx_values::tdx_float32::parse(result.get_value());

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