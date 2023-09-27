#pragma once

#include <unordered_map>
#include <cstdint>
#include <string>

namespace tdx_models {
    const uint32_t CODE_SUCCESS = 0;
    const uint32_t CODE_GENERIC_ERROR = 101;
    const uint32_t CODE_INVALID_FORMAT = 102;
    const uint32_t CODE_UNSUPPORTED_OP = 103;
    const uint32_t CODE_UNSUPPORTED_ENUM = 104;
    const uint32_t CODE_INVALID_DATA = 105;

    const std::unordered_map<uint32_t, std::string> TDX_RESULT_CODES{
            {CODE_SUCCESS,          "Success"},
            {CODE_GENERIC_ERROR,    "Generic error"},
            {CODE_INVALID_FORMAT,   "Invalid format"},
            {CODE_UNSUPPORTED_OP,   "Unsupported operation"},
            {CODE_UNSUPPORTED_ENUM, "Unsupported enum"},
    };
}