#pragma once

#include "shared.hpp"

void test_int32() {
    auto test_name = "TESTS: tdx_int32";
    TEST_RESULTS[test_name] = {};
    std::cout << std::endl << test_name << std::endl;

    std::vector<std::int_fast32_t> tests{
            0,
            32904892,
            -3290134,
            5430430
    };

    for (std::int_fast32_t test_value: tests) {
        tdx_values::tdx_int32 tdx_val(test_value);

        auto result = tdx_val.serialize();
        auto parsed = tdx_values::tdx_int32::parse(result.get_value());

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
