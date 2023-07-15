#pragma once

#include <optional>

#include "json/single_include/nlohmann/json.hpp"

#include "tdx_value.hpp"
#include "../tdx_property.hpp"
#include "../string_encoding.hpp"

namespace tdx_values {
    class tdx_null final : public tdx_value {
    public:
        tdx_null() {}

        tdx_value_type get_type() final { return tdx_value_type::null; }

        bytes_uptr serialize() final {
            throw;
        }
    };

    class tdx_string final : public tdx_value {
    public:
        tdx_string() {
            value = std::nullopt;
        }

        tdx_string(std::string l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_string(std::string l_value, tdx_models::tdx_string_encoding l_encoding) {
            value = l_value;
            encoding = l_encoding;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::string; }

        bool is_null = true;
        std::optional <std::string> value;
        tdx_models::tdx_string_encoding encoding;

        bytes_uptr serialize() final {
            throw;
        }
    };

    class tdx_int16 final : public tdx_value {
    public:
        tdx_int16() {
            value = std::nullopt;
        }

        tdx_int16(std::int_fast16_t l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::int16; }

        bool is_null = true;
        std::optional <std::int_fast16_t> value;

        bytes_uptr serialize() final {
            throw;
        }
    };

    class tdx_int32 final : public tdx_value {
    public:
        tdx_int32() { value = std::nullopt; }

        tdx_int32(std::int_fast32_t l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::int32; }

        bool is_null = true;
        std::optional <std::int_fast32_t> value;

        bytes_uptr serialize() final {
            throw;
        }
    };

    class tdx_int64 final : public tdx_value {
    public:
        tdx_int64() { value = std::nullopt; }

        tdx_int64(std::int_fast64_t l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::int64; }

        bool is_null = true;
        std::optional <std::int_fast64_t> value;

        bytes_uptr serialize() final {
            throw;
        }
    };

    class tdx_uint16 final : public tdx_value {
    public:
        tdx_uint16() { value = std::nullopt; }

        tdx_uint16(std::uint_fast16_t l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::uint16; }

        bool is_null = true;
        std::optional <std::uint_fast16_t> value;

        bytes_uptr serialize() final {
            throw;
        }
    };

    class tdx_uint32 final : public tdx_value {
    public:
        tdx_uint32() { value = std::nullopt; }

        tdx_uint32(std::uint_fast32_t l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::uint32; }

        bool is_null = true;
        std::optional <std::uint_fast32_t> value;

        bytes_uptr serialize() final {
            throw;
        }
    };

    class tdx_uint64 final : public tdx_value {
    public:
        tdx_uint64() { value = std::nullopt; }

        tdx_uint64(std::uint_fast64_t l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::uint64; }

        bool is_null = true;
        std::optional <std::uint_fast64_t> value;

        bytes_uptr serialize() final {
            throw;
        }
    };

    class tdx_float32 final : public tdx_value {
    public:
        tdx_float32() { value = std::nullopt; }

        tdx_float32(float l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::float32; }

        bool is_null = true;
        std::optional<float> value;

        bytes_uptr serialize() final {
            throw;
        }
    };

    class tdx_float64 final : public tdx_value {
    public:
        tdx_float64() { value = std::nullopt; }

        tdx_float64(double l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::float64; }

        bool is_null = true;
        std::optional<double> value;

        bytes_uptr serialize() final {
            throw;
        }
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

    class tdx_blob final : public tdx_value {
    public:
        tdx_blob() { value = nullptr; }

        tdx_blob(bytes_uptr l_value) {
//            value = std::make_optional<bytes_uptr>(l_value);
            value = std::move(l_value);
            is_null = value == nullptr;
        }

        tdx_value_type get_type() final { return tdx_value_type::blob; }

        bool is_null = true;
        bytes_uptr value;

        bytes_uptr serialize() final {
            throw;
        }
    };

    class tdx_blob_ref final : public tdx_value {
    public:
        tdx_blob_ref() { value = std::nullopt; }

        tdx_blob_ref(std::string l_value) {
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::blob_ref; }

        bool is_null = true;
        std::optional <std::string> value;

        bytes_uptr serialize() final {
            throw;
        }
    };

    class tdx_json final : public tdx_value {
    public:
        tdx_json() { value = std::nullopt; }
        tdx_json(nlohmann::json l_value){
            value = l_value;
            is_null = false;
        }

        tdx_value_type get_type() final { return tdx_value_type::json; }

        bool is_null = true;
        std::optional <nlohmann::json> value;

        bytes_uptr serialize() final {
            throw;
        }
    };

    class tdx_document final : public tdx_value {
    public:
        std::optional <std::map<std::string, tdx_models::tdx_property>> value = std::nullopt;

        bytes_uptr serialize() final {
            throw;
        }
    };
}