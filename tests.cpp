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

        auto parsed = tdx_values::tdx_blob::parse(bytes);

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
        auto bytes = test_value.serialize();

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

        auto bytes = test_value.serialize();
        auto parsed = tdx_values::tdx_datetime::parse(bytes);

        bool passed =
                test_value.value.value() == parsed.value.value()
                && test_value.time_zone == parsed.time_zone;

        std::cout
                << "Test '" << test_value.value.value() << "' " << "Timezone: '" << test_value.time_zone.value() << "'"
                << (passed ? "passed" : "failed")
                << std::endl;
    }
}

void test_float64() {
    auto test_name = "TESTS: tdx_float64";
    TEST_RESULTS[test_name] = {};
    std::cout << std::endl << test_name << std::endl;

    std::vector<double> tests{
            0,
            329048.03342,
            98458449.92382,
            -934923.43243,
            -342
    };

    for (double test_value: tests) {
        tdx_values::tdx_float64 tdx_val(test_value);

        auto bytes = tdx_val.serialize();
        auto parsed = tdx_values::tdx_float64::parse(bytes);

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

void test_float32() {
    auto test_name = "TESTS: tdx_float32";
    TEST_RESULTS[test_name] = {};
    std::cout << std::endl << test_name << std::endl;

    std::vector<float> tests{
            0,
            9048.0334,
            3449.9238,
            -9349.432,
            -342
    };

    for (float test_value: tests) {
        tdx_values::tdx_float32 tdx_val(test_value);

        auto bytes = tdx_val.serialize();
        auto parsed = tdx_values::tdx_float32::parse(bytes);

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

void test_uint64() {
    auto test_name = "TESTS: tdx_uint64";
    TEST_RESULTS[test_name] = {};
    std::cout << std::endl << test_name << std::endl;

    std::vector<std::uint_fast64_t> tests{
            0,
            32904892389849328,
            98458449,
    };

    for (std::uint_fast64_t test_value: tests) {
        tdx_values::tdx_uint64 tdx_val(test_value);

        auto bytes = tdx_val.serialize();
        auto parsed = tdx_values::tdx_uint64::parse(bytes);

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

void test_int64() {
    auto test_name = "TESTS: tdx_int64";
    TEST_RESULTS[test_name] = {};
    std::cout << std::endl << test_name << std::endl;

    std::vector<std::int_fast64_t> tests{
            0,
            32904892389849328,
            98458449,
    };

    for (std::int_fast64_t test_value: tests) {
        tdx_values::tdx_int64 tdx_val(test_value);

        auto bytes = tdx_val.serialize();
        auto parsed = tdx_values::tdx_int64::parse(bytes);

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

        auto bytes = tdx_val.serialize();
        auto parsed = tdx_values::tdx_uint32::parse(bytes);

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
    test_uint32();
    test_int32();
    test_int64();
    test_uint64();
    test_string();
    test_float32();
    test_float64();
    test_datetime();
    test_timespan();
    test_blob();

    int passed = 0;
    int failed = 0;
    for (auto result: TEST_RESULTS) {
        passed += result.second.passed;
        failed += result.second.failed;
    }

    std::cout << std::endl << "Tests: " << passed + failed << ", Passed: " << passed << ", Failed: " << failed
              << std::endl;
}