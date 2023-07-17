//
// Created by khamas on 17/7/23.
//

#include <string>
#include "includes.hpp"

struct test_result {
    int passed = 0;
    int failed = 0;
};

static std::unordered_map<std::string, test_result> TEST_RESULTS = {};

void run_tests();

int main() {
    run_tests();

    return 0;
}

void test_int32() {
    auto test_name = "TESTS: tdx_int32";
    TEST_RESULTS[test_name] = {};
    std::cout << std::endl << test_name << std::endl;

    std::vector<std::int_fast32_t> tests{
            0,
            3290489238,
            -329013420,
            5430430
    };

    for (std::int_fast32_t test_value: tests) {
        tdx_values::tdx_int32 tdx_val(test_value);

        auto bytes = tdx_val.serialize();
        auto parsed = tdx_values::tdx_int32::parse(bytes);

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

void test_uint16() {
    std::cout << std::endl << "TESTS: tdx_uint16" << std::endl;

    std::vector<std::uint_fast16_t> tests{
            65000,
            0,
            2943
    };

    for (std::uint_fast16_t test_value: tests) {
        tdx_values::tdx_uint16 tdx_val(test_value);

        auto bytes = tdx_val.serialize();
        auto parsed = tdx_values::tdx_uint16::parse(bytes);

        std::cout
                << "Test '" << test_value << "' "
                << (parsed.value.value() == test_value ? "passed" : "failed")
                << std::endl;
    }
}

void test_int16() {
    std::cout << std::endl << "TESTS: tdx_int16" << std::endl;

    std::vector<std::int_fast16_t> tests{
            1,
            10230,
            -4430,
            -32
    };

    for (std::int_fast16_t value: tests) {
//        std::cout << "Testing: " << value;

        tdx_values::tdx_int16 i16 = tdx_values::tdx_int16(value);

        auto bytes = i16.serialize();
        auto parsed = tdx_values::tdx_int16::parse(bytes);

        std::cout
                << "Test '" << value << "' "
                << (parsed.value.value() == value ? "passed" : "failed")
                << std::endl;
//        std::cout << " : " << parsed.value.value() << std::endl;
    }
}

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

        auto bytes = doc->serialize();

        std::byte arr[bytes.size()];

//        std::cout << "Bytes: " << std::endl;
//        for (auto byte: bytes)
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

void run_tests() {
    test_uint16();
    test_int16();
    test_int32();
    test_string();

    int passed = 0;
    int failed = 0;
    for (auto result: TEST_RESULTS) {
        passed += result.second.passed;
        failed += result.second.failed;
    }

    std::cout << std::endl << "Tests: " << passed + failed << ", Passed: " << passed << ", Failed: " << failed << std::endl;
}