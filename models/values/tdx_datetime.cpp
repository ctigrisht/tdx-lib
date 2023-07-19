#include "tdx_datetime.hpp"

#include <cstdint>

namespace tdx_values {

//    tdx_datetime::tdx_datetime(std::int_fast64_t l_value)
    byte_vector serialize_string_length(std::uint_fast16_t value);

    byte_vector serialize_internal_uint64(std::uint_fast64_t value);

    byte_vector serialize_time_zone(const std::string &value);

    std::int_fast64_t parse_int64(byte_vector &bytes);

    std::uint_fast16_t parse_uint16(byte_vector &bytes);

    std::string parse_time_zone_code(byte_vector &bytes, std::uint_fast16_t tz_size);

    byte_vector tdx_datetime::serialize() {
        if (!value.has_value())
            return {};

        byte_vector final_bytes = {};

        const std::string &tz_string = time_zone.has_value()
                                       ? time_zone.value()
                                       : DEFAULT_TIME_ZONE_CODE;

        auto date_bytes = serialize_internal_uint64(value.value()); // size 8
        auto tz_bytes = serialize_time_zone(tz_string); // size dyn
        auto tz_size_bytes = serialize_string_length(tz_string.length()); // size 4

        final_bytes.insert(final_bytes.end(), date_bytes.begin(), date_bytes.end());
        final_bytes.insert(final_bytes.end(), tz_size_bytes.begin(), tz_size_bytes.end());
        final_bytes.insert(final_bytes.end(), tz_bytes.begin(), tz_bytes.end());

//        std::cout << "Serialized" << std::endl;
        return std::move(final_bytes);
    }

    // TODO don't copy vectors, slice into a view instead
    tdx_datetime tdx_datetime::parse(byte_vector &value)
    {
        auto bytes_length = value.size();
        byte_vector date_val_bytes = byte_vector(value.begin(), value.begin() + sizeof(std::int_fast64_t));
        auto tz_size_start = value.begin() + sizeof(std::int_fast64_t);
        auto tz_size_end = tz_size_start + sizeof(std::uint_fast16_t);
        byte_vector tz_size_bytes = byte_vector(tz_size_start, tz_size_end);


        auto date_val = parse_int64(date_val_bytes);
        std::uint_fast16_t tz_size = parse_uint16(tz_size_bytes);

        auto tzc_start = tz_size_end;
        auto tzc_end = tzc_start + (unsigned long long)tz_size;
        byte_vector tz_code_bytes = byte_vector(tzc_start, tzc_end);

        auto tz_code = parse_time_zone_code(tz_code_bytes, tz_size);

        return {date_val, tz_code};
    }

    tdx_datetime tdx_datetime::now() {
        std::chrono::time_point point = std::chrono::system_clock::now();
        auto ticks = point.time_since_epoch().count();

        return tdx_datetime{ticks};
    }

    byte_vector serialize_time_zone(const std::string &value) {

        uint length = value.length();

        std::byte tmp_bytes[length];
        std::transform(
                value.begin(),
                value.end(),
                tmp_bytes,
                [](const char &character) {
                    return std::byte(character);
                });

        byte_vector ret_bytes;

        for (int i = 0; i < length; i++)
            ret_bytes.push_back(tmp_bytes[i]);

        return std::move(ret_bytes);
    }

    byte_vector serialize_internal_uint64(std::uint_fast64_t value) {
        auto type_size = sizeof(std::int_fast64_t);
        std::byte buffer[type_size];

        auto byte_data = static_cast<std::byte *>(static_cast<void *>(&value));
        for (int i = 0; i < type_size; ++i) {
            buffer[i] = byte_data[i];
        }

        if constexpr (std::endian::native == std::endian::big) {
            std::byte tmp_arr[type_size];
            for (int i = 0; i < type_size; ++i) {
                auto inverse = type_size - 1 - i;
                tmp_arr[inverse] = byte_data[i];
            }
            for (int i = 0; i < type_size; ++i) {
                buffer[i] = tmp_arr[i];
            }
        }

        auto ret_bytes = byte_vector();
        for (int i = 0; i < type_size; ++i) {
            ret_bytes.push_back(buffer[i]);
        }

        return std::move(ret_bytes);
    }

    byte_vector serialize_string_length(std::uint_fast16_t value) {
        auto type_size = sizeof(std::uint_fast16_t);
//        std::uint_fast16_t
        std::byte bytes[type_size];

        auto byte_data = static_cast<std::byte *>(static_cast<void *>(&value));
        for (int i = 0; i < type_size; ++i) {
            bytes[i] = byte_data[i];
        }

        if constexpr (std::endian::native == std::endian::big) {
            auto tmp = bytes[0];
            bytes[0] = bytes[1];
            bytes[1] = tmp;
        }

        auto ret_bytes = byte_vector();
        for (int i = 0; i < type_size; ++i) {
            ret_bytes.push_back(bytes[i]);
        }

        return std::move(ret_bytes);
    }

    std::int_fast64_t parse_int64(byte_vector &bytes) {
        const auto type_size = sizeof(std::int_fast64_t);

        if (type_size > type_size)
            throw std::exception();

        std::byte buffer[type_size];
        for (int i = 0; i < type_size; ++i) {
            buffer[i] = bytes[i];
        }

        if constexpr (std::endian::native == std::endian::big) {
            std::byte tmp_arr[type_size];
            for (int i = 0; i < type_size; ++i) {
                auto inverse = type_size - 1 - i;
                tmp_arr[inverse] = buffer[i];
            }
            for (int i = 0; i < type_size; ++i) {
                buffer[i] = tmp_arr[i];
            }
        }

        std::int_fast64_t cast_value;
        memcpy(&cast_value, buffer, type_size);
        return cast_value;
    }

    std::uint_fast16_t parse_uint16(byte_vector &bytes) {
        const auto length = sizeof(std::uint_fast16_t);

        std::byte buffer[length];
        for (int i = 0; i < length; ++i) {
            buffer[i] = bytes[i];
        }

        if constexpr (std::endian::native == std::endian::big) {
            auto tmp = buffer[0];
            buffer[0] = buffer[1];
            buffer[1] = buffer[0];
        }

        std::int_fast16_t cast_value;
        memcpy(&cast_value, buffer, length);

        return cast_value;
    }

    std::string parse_time_zone_code(byte_vector &bytes, std::uint_fast16_t tz_size) {
        char characters[tz_size];
        for (int i = 0; i < tz_size; i++)
            characters[i] = char(bytes[i]);

        return {characters, tz_size};
    }
}