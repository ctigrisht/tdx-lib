#include "tdx_datetime.hpp"

#include <cstdint>
#include <array>

namespace tdx_values {

//    tdx_datetime::tdx_datetime(std::int_fast64_t l_value)
    std::array<std::byte, 2> serialize_uint16(std::uint16_t value);

    std::array<stdbyte, 8> serialize_internal_int64(std::int64_t value);

    byte_vector serialize_time_zone(const std::string &value);

    std::int64_t parse_int64(std::array<std::byte, sizeof (std::int64_t)> &bytes);

    std::uint_fast16_t parse_uint16(std::array<std::byte, 2> &in_bytes);

    std::string parse_time_zone_code(byte_vector &bytes, std::uint_fast16_t tz_size);

    byte_vector tdx_datetime::serialize() {
        if (!value.has_value())
            return {};

        byte_vector final_bytes = {};

        const std::string &tz_string = time_zone.has_value()
                                       ? time_zone.value()
                                       : DEFAULT_TIME_ZONE_CODE;

        auto date_bytes = serialize_internal_int64(value.value()); // size 8
        auto tz_bytes = serialize_time_zone(tz_string); // size dyn
        auto tz_size_bytes = serialize_uint16(tz_string.length()); // size 4

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
        std::array<stdbyte, sizeof (std::int64_t)> date_val_bytes{};

        std::copy(value.begin(), value.begin() + sizeof(std::int64_t), date_val_bytes.begin());

        auto tz_size_start = value.begin() + sizeof(std::int_fast64_t);
        auto tz_size_end = tz_size_start + sizeof(std::uint_least16_t);

        auto skip_size = sizeof(std::int_fast64_t);
        auto tz_size_bytes = std::array<std::byte, 2>({
            value[skip_size],
            value[skip_size+1]
        });


        std::int64_t date_val = parse_int64(date_val_bytes);
        std::uint16_t tz_size = parse_uint16(tz_size_bytes);

        auto tzc_start = tz_size_end;
        auto tzc_end = tzc_start + tz_size;
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

    std::array<stdbyte, 8> serialize_internal_int64(std::int64_t value) {
        auto type_size = sizeof(std::int64_t);
        std::array<stdbyte, sizeof (std::int64_t)> buffer{};

        buffer[0] = static_cast<stdbyte>(value >> 8 * 0);
        buffer[1] = static_cast<stdbyte>(value >> 8 * 1);
        buffer[2] = static_cast<stdbyte>(value >> 8 * 2);
        buffer[3] = static_cast<stdbyte>(value >> 8 * 3);
        buffer[4] = static_cast<stdbyte>(value >> 8 * 4);
        buffer[5] = static_cast<stdbyte>(value >> 8 * 5);
        buffer[6] = static_cast<stdbyte>(value >> 8 * 6);
        buffer[7] = static_cast<stdbyte>(value >> 8 * 7);

//        auto byte_data = static_cast<std::byte *>(static_cast<void *>(&value));

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

        return buffer;
    }

    std::array<std::byte, 2> serialize_uint16(std::uint16_t value) {
        auto type_size = sizeof(std::uint_least16_t);

        std::byte bytes[type_size];
        bytes[0] = static_cast<std::byte>(value >> 0);
        bytes[1] = static_cast<std::byte>(value >> 8);

        if constexpr (std::endian::native == std::endian::big) {
            auto tmp = bytes[0];
            bytes[0] = bytes[1];
            bytes[1] = tmp;
        }

        auto ret_bytes = std::array{bytes[0], bytes[1]};

        return std::move(ret_bytes);
    }

    std::int64_t parse_int64(std::array<stdbyte, sizeof (std::int64_t)> &bytes) {
        const auto type_size = sizeof(std::int64_t);

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

        std::int64_t cast_value;
        memcpy(&cast_value, buffer, type_size);
        return cast_value;
    }

    std::uint_fast16_t parse_uint16(std::array<std::byte, 2> &in_bytes) {
//        const auto type_size = sizeof(std::uint_least16_t);

//        std::byte buffer[type_size];
//        for (int i = 0; i < type_size; ++i) {
//            buffer[i] = in_bytes[i];
//        }

        if constexpr (std::endian::native == std::endian::big) {
            auto tmp = in_bytes[0];
            in_bytes[0] = in_bytes[1];
            in_bytes[1] = in_bytes[0];
        }

        std::uint_least16_t cast_value = 0;
        auto* tmp_bytes = reinterpret_cast<std::byte*>(&cast_value);
        tmp_bytes[0] = in_bytes[0];
        tmp_bytes[1] = in_bytes[1];

//        memcpy(&cast_value, (std::byte*) in_bytes, 2);

        return cast_value;
    }

    std::string parse_time_zone_code(byte_vector &bytes, std::uint_fast16_t tz_size) {
        char characters[tz_size];
        for (int i = 0; i < tz_size; i++)
            characters[i] = char(bytes[i]);

        return {characters, tz_size};
    }
}