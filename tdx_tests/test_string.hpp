#pragma once

#include "shared.hpp"


void test_string() {
    std::cout << std::endl << "TESTS: tdx_string (UTF-8)" << std::endl;

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
        std::cout
                << "Test '" << test_value << "' : '" << final << "' "
                << (final == test_value ? "passed" : "failed")
                << std::endl;
//        std::cout << *parsed.value_u8 << std::endl;
        delete doc;
    }
}