#pragma once

#include "shared.hpp"

void test_timespan() {
    auto test_name = "TESTS: tdx_timespan";
    TEST_RESULTS[test_name] = {};
    std::cout << std::endl << test_name << std::endl;

    std::vector<tdx_values::tdx_timespan> tests{
            tdx_values::tdx_timespan{0},
            tdx_values::tdx_timespan{250},
            tdx_values::tdx_timespan{3209432},
    };

    for (auto test_value: tests) {
        auto result = test_value.serialize();

        auto& bytes = result.get_value();

        std::array<stdbyte, sizeof(int64_t)> barr = {};
        for (int i = 0; i < sizeof(int64_t); ++i)
            barr[i] = bytes[i];

        auto parsed = tdx_values::tdx_timespan::parse(barr);

        auto passed = parsed.value.value() == test_value.value.value();
        std::cout
                << "Test '" << test_value.value.value() << "' "
                << (passed ? "passed" : "failed")
                << std::endl;

        if (passed)
            TEST_RESULTS[test_name].passed++;
        else TEST_RESULTS[test_name].failed++;
    }
}