#pragma once

#include "values_cpp_includes.hpp"

namespace tdx_values{

    class tdx_timespan final : public tdx_value {
    public:
        tdx_timespan() {

        }

//        explicit tdx_timespan(std::chrono::duration<std::chrono::milliseconds> l_value) {
//            is_null = false;
//        }

        explicit tdx_timespan(std::int64_t l_value) {
            is_null = false;
            value = l_value;
        }

        bool is_null = true;
        std::optional<std::int64_t> value;

        tdx_value_type get_type() final { return tdx_value_type::timespan; }

        tdx_result serialize() final;
        static tdx_timespan parse(std::array<stdbyte, sizeof (std::int64_t)>& value);
    };

}