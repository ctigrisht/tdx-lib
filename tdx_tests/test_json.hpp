#pragma once

#include "shared.hpp"


void test_json() {
    auto test_name = "TESTS: tdx_json";
    std::cout << std::endl << test_name << std::endl;

    std::vector<njson> tests{
            njson{},
            njson::parse("[1, 2, 3, \"Hello\"]"),
            njson{
                    {"Hello",    "Youtube"},
                    {"Monetize", "Me"},
                    {"Price",    2000}
            }
    };


    for (njson test_value: tests) {
        tdx_values::tdx_json *doc = new tdx_values::tdx_json(
                test_value);

        auto result = doc->serialize();

        if (result.is_error()) {
            std::cout << "Test failed, result is error" << std::endl;
            TEST_RESULTS[test_name].failed++;
            delete doc;
            return;
        }

        auto &bytes = result.get_value();

        std::byte arr[bytes.size()];

        auto parsed = tdx_values::tdx_json::parse(bytes);

        if (!parsed.value.has_value()) {
            std::cout << "Test failed, value is null" << std::endl;
            TEST_RESULTS[test_name].failed++;
            delete doc;
            return;
        }

        njson final = parsed.value.value();
        auto passed = final == test_value;
        std::cout
                << "Test '" << test_value << "' : '" << final << "' "
                << (passed ? "passed" : "failed")
                << std::endl;
        delete doc;

        if (passed)
            TEST_RESULTS[test_name].passed++;
        else TEST_RESULTS[test_name].failed++;
    }
}