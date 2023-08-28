//
// Created by khamas on 17/7/23.
//

#include <string>
#include "../includes.hpp"

#include "test_blob.hpp"
#include "test_datetime.hpp"
#include "test_float32.hpp"
#include "test_float64.hpp"
#include "test_int16.hpp"
#include "test_int32.hpp"
#include "test_int64.hpp"
#include "test_string.hpp"
#include "test_boolean.hpp"
#include "test_timespan.hpp"
#include "test_uint16.hpp"
#include "test_uint32.hpp"
#include "test_uint64.hpp"
#include "test_daterange.hpp"

void run_tests();

int main() {
    run_tests();

    return 0;
}

void run_tests() {
    test_string();
    test_boolean();
    test_blob();
    test_datetime();
    test_timespan();
    test_daterange();
    test_float32();
    test_float64();
    test_int16();
    test_int32();
    test_int64();
    test_uint16();
    test_uint32();
    test_uint64();

    int passed = 0;
    int failed = 0;
    for (auto result: TEST_RESULTS) {
        passed += result.second.passed;
        failed += result.second.failed;
    }

    std::cout << std::endl << "Tests: " << passed + failed << ", Passed: " << passed << ", Failed: " << failed
              << std::endl;
}