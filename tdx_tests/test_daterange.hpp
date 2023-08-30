#pragma once

#include "shared.hpp"

void test_daterange_invertedstamps_constructor() {
    bool passed = true;
    auto test_name = "TESTS: test_daterange_invertedstamps_constructor";

    int64_t val0 = 100000;
    int64_t val1 = 45000;

    try {
        tdx_values::tdx_daterange{std::array<int64_t, 2>{val0, val1}};
    } catch (std::runtime_error &ex) {
        passed = val0 > val1;
    }

    std::cout << std::endl << test_name << " passed" << std::endl;

    if (passed)
        TEST_RESULTS[test_name].passed++;
    else TEST_RESULTS[test_name].failed++;
}

void test_daterange() {
    auto test_name = "TESTS: tdx_daterange";
    TEST_RESULTS[test_name] = {};
    std::cout << std::endl << test_name << std::endl;

    std::vector<tdx_values::tdx_daterange> tests{
            tdx_values::tdx_daterange{std::array<int64_t, 2>{9384298, 2903219039}},
            tdx_values::tdx_daterange{std::array<int64_t, 2>{938429, 13023219}},
            tdx_values::tdx_daterange{2903219039},
    };

    for (auto test_value: tests) {

        auto result = test_value.serialize();
        auto bytes_vec = result.get_value();
        auto span = std::span<stdbyte>(bytes_vec.begin(), bytes_vec.end());
        auto parsed = tdx_values::tdx_daterange::parse(span);

        auto test_val = test_value.value.value();
        auto parse_val = parsed.value.value();
        bool passed = test_val[0] == parse_val[0] && test_val[1] == parse_val[1];

        std::cout
                << "Test '" << test_value.value.value()[0] << " : " << test_value.value.value()[1] << " "
                << (passed ? "passed" : "failed")
                << std::endl;

        if (passed)
            TEST_RESULTS[test_name].passed++;
        else TEST_RESULTS[test_name].failed++;
    }
}