#pragma once

#include "shared.hpp"

void test_datetime() {
    auto test_name = "TESTS: tdx_datetime";
    TEST_RESULTS[test_name] = {};
    std::cout << std::endl << test_name << std::endl;

    std::vector<tdx_values::tdx_datetime> tests{
            tdx_values::tdx_datetime{0},
            tdx_values::tdx_datetime{3492039},
            tdx_values::tdx_datetime{std::chrono::system_clock::now()},
            tdx_values::tdx_datetime{39402394328, std::string("utc")},
            tdx_values::tdx_datetime{324329482938, std::string("GMT+5")},
            tdx_values::tdx_datetime{std::chrono::system_clock::now(), std::string("GMT+8")},
    };

    for (auto test_value: tests) {

        auto result = test_value.serialize();

        auto parsed = tdx_values::tdx_datetime::parse(result.get_value());

        bool passed =
                test_value.value.value() == parsed.value.value()
                && test_value.time_zone == parsed.time_zone;

        std::cout
                << "Test '" << test_value.value.value() << "' " << "Timezone: '" << test_value.time_zone.value() << "'"
                << (passed ? "passed" : "failed")
                << std::endl;
    }
}