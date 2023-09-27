#include "tdx_free_document.hpp"
#include "../tdx_property.hpp"
#include "../tdx_property_deleter.hpp"
#include "../result_codes_table.hpp"


namespace tdx_values {
    byte_vector serialize_key(std::string value);

    tdx_free_document::tdx_free_document(tdx_prop_map l_value) {
        value = std::move(l_value);
    }

    tdx_bytes_result tdx_free_document::serialize() {
        if (!value.has_value())
            return (false);

        const auto& props = value.value();

        uint16_t prop_count = props.size(); // TODO serialize this

        auto final_bytes = byte_vector{
            stdbyte (0)
        };

        auto prop_count_bytes = internal_serializers::serialize_uint16(prop_count);
        final_bytes.insert(
                final_bytes.end(),
                prop_count_bytes.begin(),
                prop_count_bytes.end());

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

            tmp_bytes.insert(tmp_bytes.end(), key_size_bytes.begin(), key_size_bytes.end());
            tmp_bytes.insert(tmp_bytes.end(), key_bytes.begin(), key_bytes.end());

            auto type_code = result_value_type_code.get_value();
            tmp_bytes.insert(tmp_bytes.end(), type_code.begin(), type_code.end());

            auto result_value_bytes = prop_value->serialize();
            if (result_value_bytes.is_error()){
//                return (result_value_bytes.get_error());
                tmp_bytes.push_back(stdbyte(0));
                final_bytes.insert(
                        final_bytes.end(),
                        std::make_move_iterator(tmp_bytes.begin()),
                        std::make_move_iterator(tmp_bytes.end()));

                continue;
            }

            tmp_bytes.push_back(stdbyte(1));

            auto iter_ptr = tmp_bytes.end();
            auto& value_bytes = result_value_bytes.get_value();
            tmp_bytes.insert(iter_ptr, value_bytes.begin(), value_bytes.end());

//            iter_ptr += value_bytes.size();

            final_bytes.insert(
                    final_bytes.end(),
                    std::make_move_iterator(tmp_bytes.begin()),
                    std::make_move_iterator(tmp_bytes.end()));
        }

        return {std::move(final_bytes)};
    }

    vr::result<tdx_free_document, uint32_t> tdx_free_document::parse(byte_vector &value) {
        if (value[0] != stdbyte(0))
            return (CODE_INVALID_DATA);

        auto prop_count = internal_serializers::parse_uint16({
            value [1],
            value [2]
        });

        auto iterator = value.begin() + 3;

        for (int current_prop = 0; current_prop < prop_count; ++current_prop) {
            auto prop_key_size = internal_serializers::parse_uint16({
                    value[3], value[4]
            });

            iterator += 2;

            auto span = std::span{iterator, iterator + prop_key_size};
            iterator += prop_key_size;

            auto prop_key_name_result = internal_serializers::parse_native_string(span);
            if (prop_key_name_result.is_error())
                return (prop_key_name_result.get_error());

            auto type_code =
        }

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

    vr::result<bool, uint16_t> parse_key_size(std::array<stdbyte, 2> data_bytes){

    }

    vr::result<bool, std::string> parse_key(std::span<stdbyte> data_bytes){

    }
}