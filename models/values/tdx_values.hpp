#pragma once

#include <optional>

#include "tdx_value.hpp"
#include "../string_encoding.hpp"

namespace tdx_values
{
    class tdx_null final : public tdx_value
    {
    public:
        tdx_value_type get_type() final { return tdx_value_type::null; }

        bytes_uptr serialize() final
        {
            throw "noimpl";
        }
    };

    class tdx_string final : public tdx_value
    {
    public:
        tdx_value_type get_type() final { return tdx_value_type::string; }

        bool is_null = true;
        std::optional<std::string> value;
        tdx_string_encoding Encoding = tdx_string_encoding::UTF_8;

        bytes_uptr serialize() final
        {
            throw "noimpl";
        }
    };

    class tdx_int16 final : public tdx_value
    {
    public:
        tdx_value_type get_type() final { return tdx_value_type::int16; }

        bool is_null = true;
        std::optional<std::int_fast16_t> value = 0;

        bytes_uptr serialize() final
        {
            throw "noimpl";
        }
    };

    class tdx_int32 final : public tdx_value
    {
    public:
        tdx_value_type get_type() final { return tdx_value_type::int32; }

        bool is_null = true;
        std::optional<std::int_fast32_t> value = 0;

        bytes_uptr serialize() final
        {
            throw "noimpl";
        }
    };

    class tdx_int64 final : public tdx_value
    {
    public:
        tdx_value_type get_type() final { return tdx_value_type::int64; }

        bool is_null = true;
        std::optional<std::int_fast64_t> value = 0;

        bytes_uptr serialize() final
        {
            throw "noimpl";
        }
    };

    class tdx_uint16 final : public tdx_value
    {
    public:
        tdx_value_type get_type() final { return tdx_value_type::uint16; }

        bool is_null = true;
        std::optional<std::uint_fast16_t> value = 0;

        bytes_uptr serialize() final
        {
            throw "noimpl";
        }
    };

    class tdx_uint32 final : public tdx_value
    {
    public:
        tdx_value_type get_type() final { return tdx_value_type::uint32; }

        bool is_null = true;
        std::optional<std::uint_fast32_t> value = 0;

        bytes_uptr serialize() final
        {
            throw "noimpl";
        }
    };

    class tdx_uint64 final : public tdx_value
    {
    public:
        tdx_value_type get_type() final { return tdx_value_type::uint64; }

        bool is_null = true;
        std::optional<std::uint_fast64_t> value = 0;

        bytes_uptr serialize() final
        {
            throw "noimpl";
        }
    };

    class tdx_decimal final : public tdx_value
    {
    public:
        tdx_value_type get_type() final { return tdx_value_type::decimal; }

        bool is_null = true;
        std::optional<_Decimal128> value = 0;

        bytes_uptr serialize() final
        {
            throw "noimpl";
        }
    };

    class tdx_blob final : public  tdx_value {
    public:
        tdx_value_type get_type() final {return tdx_value_type::blob;}

        bool is_null = true;
        std::optional<std::byte[]> value = std::make_optional<std::byte[]>();

        bytes_uptr serialize() final{
            throw;
        }
    };

    class tdx_blob_ref : public  tdx_value {
    public:
        tdx_value_type get_type() final { return tdx_value_type::blob_ref; }

        bool is_null = true;
        std::optional<std::string> value = std::make_optional();

        bytes_uptr serialize() final {
            throw;
        }
    };
}