#pragma once

#include "values_cpp_includes.hpp"
#include "json/single_include/nlohmann/json.hpp"

namespace tdx_values{

    class tdx_json final : public tdx_value {
    public:
        tdx_json() { value = std::nullopt; }

        tdx_json(std::string l_json){
            njson json_obj = nlohmann::json::parse(l_json);
            value = std::move(json_obj);
        }

        tdx_json(nlohmann::json l_value) {
            value = std::move(l_value);
        }

        tdx_value_type get_type() final { return tdx_value_type::json; }

        std::optional<njson> value;

        tdx_bytes_result serialize() final;
        static tdx_json parse(byte_vector& value);

        njson& get_ref(){
            return value.value();
        }
    };
}