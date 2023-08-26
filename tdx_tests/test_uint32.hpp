#pragma once

#include "shared.hpp"


void test_uint32() {
    auto test_name = "TESTS: tdx_uint32";
    TEST_RESULTS[test_name] = {};
    std::cout << std::endl << test_name << std::endl;

    std::vector<std::uint_fast32_t> tests{
            0,
            3290489238,
            98458449,
    };

    for (std::uint_fast32_t test_value: tests) {
        tdx_values::tdx_uint32 tdx_val(test_value);

        auto result = tdx_val.serialize();
        auto parsed = tdx_values::tdx_uint32::parse(result.get_value());

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