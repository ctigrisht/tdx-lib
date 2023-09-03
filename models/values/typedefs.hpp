#pragma once

#include "../../lib/internal/result.hpp"
//#include "../shared_types.hpp"
//#include "../tdx_property.hpp"
//#include "../string_encoding.hpp"
#include "json/single_include/nlohmann/json.hpp"

typedef vr::result<byte_vector, uint32_t> tdx_bytes_result;
typedef nlohmann::json njson;