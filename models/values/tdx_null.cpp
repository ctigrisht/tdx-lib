#include "values_cpp_includes.hpp"

#include "tdx_null.hpp"

namespace tdx_values {
    tdx_bytes_result tdx_null::serialize() {
        auto ret_vec = byte_vector{};
        ret_vec.resize(2 + padding_size);
        ret_vec[0] = NULL_FLAG[0];
        ret_vec[1] = NULL_FLAG[1];

        return std::move(ret_vec);
    }

    tdx_null tdx_null::parse(byte_vector &value) {
        auto val = tdx_null();
        val.padding_size = value.size() - 2;
        return val;
    }
}