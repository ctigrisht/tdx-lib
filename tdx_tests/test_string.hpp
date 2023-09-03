#pragma once

#include "shared.hpp"


void test_string() {
    auto test_name = "TESTS: tdx_string (UTF-8)";
    std::cout << std::endl << test_name << std::endl;

    std::vector<std::string> tests{
            "Hello Twitch :)",
            "Bonjour éééééé",
            "科區文常中標最得還"
    };


    for (std::string test_value: tests) {
        tdx_values::tdx_value *doc = new tdx_values::tdx_string(
                test_value);

        auto result = doc->serialize();

        auto& bytes = result.get_value();

        std::byte arr[bytes.size()];

//        std::cout << "Bytes: " << std::endl;
//        for (auto byte: result)
//            std::cout << std::int_fast32_t(byte);

//        std::cout << std::endl;

        auto parsed = tdx_values::tdx_string::parse(bytes);

        std::string final = *parsed.value_u8;
        auto passed = final == test_value;

        std::cout
                << "Test '" << test_value << "' : '" << final << "' "
                << (passed? "passed" : "failed")
                << std::endl;
//        std::cout << *parsed.value_u8 << std::endl;
        delete doc;
        if (passed)
            TEST_RESULTS[test_name].passed++;
        else TEST_RESULTS[test_name].failed++;
    }
}