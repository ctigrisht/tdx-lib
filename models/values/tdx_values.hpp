#pragma once

#include <optional>
#include <chrono>

#include "json/single_include/nlohmann/json.hpp"

#include "tdx_value.hpp"
#include "../shared_types.hpp"
#include "../tdx_property.hpp"
#include "../string_encoding.hpp"

#include "tdx_type.hpp"

namespace tdx_values {
    class tdx_null final : public tdx_value {
    public:
        tdx_null() {}

        tdx_value_type get_type() final { return tdx_value_type::null; }

        byte_vector serialize() final;
        static std::unique_ptr<tdx_value> parse(byte_vector value);
    };





    class tdx_int64 final : public tdx_value {
    public:
        tdx_int64() { value = std::nullopt; }

        explicit tdx_int64(std::int_fast64_t l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::int64; }

        bool is_null = true;
        std::optional<std::int_fast64_t> value;

        byte_vector serialize() final;
        static std::unique_ptr<tdx_value> parse(byte_vector& value);
    };

    class tdx_uint32 final : public tdx_value {
    public:
        tdx_uint32() { value = std::nullopt; }

        explicit tdx_uint32(std::uint_fast32_t l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::uint32; }

        bool is_null = true;
        std::optional<std::uint_fast32_t> value;

        byte_vector serialize() final;
        static std::unique_ptr<tdx_value> parse(byte_vector value);
    };

    class tdx_uint64 final : public tdx_value {
    public:
        tdx_uint64() { value = std::nullopt; }

        explicit tdx_uint64(std::uint_fast64_t l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::uint64; }

        bool is_null = true;
        std::optional<std::uint_fast64_t> value;

        byte_vector serialize() final;
        static std::unique_ptr<tdx_value> parse(byte_vector value);
    };

    class tdx_float32 final : public tdx_value {
    public:
        tdx_float32() { value = std::nullopt; }

        explicit tdx_float32(float l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::float32; }

        bool is_null = true;
        std::optional<float> value;

        byte_vector serialize() final;
        static std::unique_ptr<tdx_value> parse(byte_vector value);
    };

    class tdx_float64 final : public tdx_value {
    public:
        tdx_float64() { value = std::nullopt; }

        explicit tdx_float64(double l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::float64; }

        bool is_null = true;
        std::optional<double> value;

        byte_vector serialize() final;
        static std::unique_ptr<tdx_value> parse(byte_vector value);
    };

//    class tdx_decimal final : public tdx_value {
//    public:
//        tdx_value_type get_type() final { return tdx_value_type::decimal; }
//
//        bool is_null = true;
//        std::optional <_Decimal128> value = std::nullopt;
//
//        bytes_uptr serialize() final {
//            throw;
//        }
//    };

    class tdx_datetime final : public tdx_value {
    public:
        tdx_datetime() {
            value = std::nullopt;
        }

        tdx_datetime(std::chrono::time_point<std::chrono::system_clock> l_value) {
            value = l_value.time_since_epoch().count();
        }

        tdx_datetime(std::int_fast64_t l_value){
            value = l_value;
        }

        tdx_value_type get_type() final { return tdx_value_type::datetime; }

        bool is_null = true;
        std::optional<std::int_fast64_t> value;


        byte_vector serialize() final;
        static tdx_datetime parse(byte_vector& value);
        static tdx_datetime now();
    };

    class tdx_timespan final : public tdx_value {
        tdx_timespan() {

        }

//        explicit tdx_timespan(std::chrono::duration<std::chrono::milliseconds> l_value) {
//            is_null = false;
//        }

        explicit tdx_timespan(std::int_fast64_t l_value) {
            is_null = false;
            value = l_value;
        }

        bool is_null = true;
        std::optional<std::int_fast64_t> value;

        tdx_value_type get_type() final { return tdx_value_type::timespan; }

        byte_vector serialize() final;
        static std::unique_ptr<tdx_value> parse(byte_vector value);
    };

    class tdx_blob final : public tdx_value {
    public:
        tdx_blob() { value = std::nullopt; }

        explicit tdx_blob(byte_vector l_value) {
//            value = std::make_optional<bytes_uptr>(l_value);
            value = std::move(l_value);
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::blob; }

        bool is_null = true;
        std::optional<byte_vector> value;

        byte_vector serialize() final;
        static std::unique_ptr<tdx_value> parse(byte_vector value);
    };

    class tdx_blob_ref final : public tdx_value {
    public:
        tdx_blob_ref() { value = std::nullopt; }

        explicit tdx_blob_ref(std::string l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::blob_ref; }

        bool is_null = true;
        std::optional<std::string> value;

        byte_vector serialize() final;
        static std::unique_ptr<tdx_value> parse(byte_vector value);
    };

    class tdx_json final : public tdx_value {
    public:
        tdx_json() { value = std::nullopt; }

        explicit tdx_json(nlohmann::json l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::json; }

        bool is_null = true;
        std::optional<nlohmann::json> value;

        byte_vector serialize() final;
        static std::unique_ptr<tdx_value> parse(byte_vector value);
    };

    class tdx_document final : public tdx_value {
        tdx_document(){ }
        explicit tdx_document(std::unordered_map<std::string, tdx_models::tdx_property> l_value){
            value = std::move(l_value);
        }

    public:
        std::optional<std::unordered_map<std::string, tdx_models::tdx_property>> value = std::nullopt;

        byte_vector serialize() final;
        static std::unique_ptr<tdx_value> parse(byte_vector value);
    };
}