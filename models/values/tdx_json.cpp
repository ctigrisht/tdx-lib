#include "tdx_json.hpp"
#include "json/single_include/nlohmann/json.hpp";

namespace tdx_values {
    tdx_bytes_result tdx_json::serialize() {
        auto serialized_string = value.value().dump();
        int32_t data_size = serialized_string.size();

        auto size_bytes = internal_serializers::serialize_int32(data_size);
        std::byte string_bytes[data_size];
        std::transform(
                serialized_string.begin(),
                serialized_string.end(),
                string_bytes,
                [](const char &character) {
                    return std::byte(character);
                });

        byte_vector ret_bytes{};
        ret_bytes.reserve(data_size + sizeof(int32_t));

        ret_bytes.insert(ret_bytes.end(), size_bytes.begin(), size_bytes.end());

        for (int i = 0; i < data_size; i++)
            ret_bytes.push_back(string_bytes[i]);

        return std::move(ret_bytes);
    }

    tdx_json tdx_json::parse(byte_vector &value) {
        auto begin = value.begin();
        auto data_size_end = begin + 4;
        auto span = std::span{begin, data_size_end};
        auto data_size = internal_serializers::parse_int32(span);
        auto data_end = data_size_end + data_size;
        auto data_bytes = std::span{data_size_end, data_end};

        char chars[data_size];
        for (int i = 0; i < data_size; ++i)
            chars[i] = (char)data_bytes[i];

        std::string final_string(chars, data_size);
        njson json = nlohmann::json::parse(final_string);
        return tdx_json{std::move(json)};
    }
}