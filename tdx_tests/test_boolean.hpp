#pragma once

#include "shared.hpp"


void test_boolean() {
    auto test_name = "TESTS: tdx_boolean";
    TEST_RESULTS[test_name] = {};
    std::cout << std::endl << test_name << std::endl;

    std::vector<bool> tests{
            true,
            false
    };

    for (bool test_value: tests) {
        tdx_values::tdx_boolean tdx_val(test_value);

        auto result = tdx_val.serialize();
        auto parsed = tdx_values::tdx_boolean::parse(result.get_value()[0]);

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