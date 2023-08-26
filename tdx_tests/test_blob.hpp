#pragma once

#include "shared.hpp"

void test_blob() {
    auto test_name = "TESTS: tdx_blob";
    TEST_RESULTS[test_name] = {};
    std::cout << std::endl << test_name << std::endl;

    auto blob1 = byte_vector{stdbyte(1), stdbyte(1), stdbyte(1)};
    auto blob2 = byte_vector{stdbyte(156), stdbyte(132), stdbyte(242), stdbyte(156), stdbyte(132), stdbyte(242)};

    auto tdx1 = tdx_values::tdx_blob{blob1};
    auto tdx2 = tdx_values::tdx_blob{blob2};
    std::vector<tdx_values::tdx_blob> tests{
            tdx1, tdx2
    };

    for (auto test_value : tests) {
        auto bytes = test_value.serialize();

        auto value = bytes.move_value();

        auto parsed = tdx_values::tdx_blob::parse(value);

        auto passed = parsed.value.value() == test_value.value.value();
        std::cout
                << "Test '" << test_value.value.value().size() << "' sized byte array "
                << (passed ? "passed" : "failed")
                << std::endl;

        if (passed)
            TEST_RESULTS[test_name].passed++;
        else TEST_RESULTS[test_name].failed++;
    }
}
