#pragma once

#include <string>
#include "../includes.hpp"

struct test_result {
    int passed = 0;
    int failed = 0;
};

static std::unordered_map<std::string, test_result> TEST_RESULTS = {};