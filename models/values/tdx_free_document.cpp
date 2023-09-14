#include "tdx_free_document.hpp"
#include "../tdx_property.hpp"
#include "../result_codes_table.hpp"


namespace tdx_values {
    byte_vector serialize_key(std::string value);

    tdx_free_document::tdx_free_document(tdx_prop_map l_value) {
        value = std::move(l_value);
    }

    tdx_bytes_result tdx_free_document::serialize() {
        if (!value.has_value())
            return (false);
        auto props = value.value();

        auto final_bytes = byte_vector{};

        for (const auto &prop: props) {
            auto tmp_bytes = byte_vector {
                stdbyte (0)
            };

            auto& prop_key = prop.first;
            auto prop_value = prop.second->value.get();

            auto result_value_type_code = get_type_code(prop_value->get_type());
            if (result_value_type_code.is_error())
                return (result_value_type_code.get_error());

            auto key_bytes = serialize_key(prop_key);
            uint16_t key_size = key_bytes.size();
            auto key_size_bytes = internal_serializers::serialize_uint16(key_size);

            auto result_value_bytes = prop_value->serialize();
            if (result_value_bytes.is_error())
                return (result_value_bytes.get_error());

            tmp_bytes.insert(tmp_bytes.end(), key_size_bytes.begin(), key_size_bytes.end());

            auto iter_ptr = tmp_bytes.begin() + 3;
            tmp_bytes.insert(iter_ptr, key_bytes.begin(), key_bytes.end());

            auto value_bytes = result_value_bytes.get_value();

            iter_ptr += key_size;
            tmp_bytes.insert(iter_ptr, value_bytes.begin(), value_bytes.end());

//            iter_ptr += value_bytes.size();

            final_bytes.insert(
                    final_bytes.end(),
                    std::make_move_iterator(tmp_bytes.begin()),
                    std::make_move_iterator(tmp_bytes.end()));
        }

        return {final_bytes};
    }

    tdx_free_document tdx_free_document::parse(byte_vector &value) {
        return {};
    }

    byte_vector serialize_key(std::string value) {
        auto length = value.length();

        std::byte tmp_bytes[length];
        std::transform(
                value.begin(),
                value.end(),
                tmp_bytes,
                [](const char &character) {
                    return std::byte(character);
                });

        byte_vector ret_bytes{};
        ret_bytes.reserve(length);

        for (int i = 0; i < length; i++)
            ret_bytes.push_back(tmp_bytes[i]);

        return std::move(ret_bytes);
    }
}