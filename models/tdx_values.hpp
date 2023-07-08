#pragma once

#include "tdx_value.hpp"
#include "string_encoding.hpp"


namespace tdx_models
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

        std::string Value;
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

        std::int_fast16_t Value = 0;

        bytes_uptr serialize() final
        {
            throw "noimpl";
        }
    };

    class tdx_int32 final : public tdx_value
    {
    public:
        tdx_value_type get_type() final { return tdx_value_type::int32; }

        std::int_fast32_t Value = 0;

        bytes_uptr serialize() final
        {
            throw "noimpl";
        }
    };

    class tdx_int64 final : public tdx_value
    {
    public:
        tdx_value_type get_type() final { return tdx_value_type::int64; }

        std::int_fast64_t Value = 0;

        _Decimal128 lsf = 0;
        bytes_uptr serialize() final
        {
            throw "noimpl";
        }
    };

    class tdx_uint16 final : public tdx_value
    {
    public:
        tdx_value_type get_type() final { return tdx_value_type::uint16; }

        std::uint_fast16_t Value = 0;

        bytes_uptr serialize() final
        {
            throw "noimpl";
        }
    };

    class tdx_uint32 final : public tdx_value
    {
    public:
        tdx_value_type get_type() final { return tdx_value_type::uint32; }

        std::uint_fast32_t Value = 0;

        bytes_uptr serialize() final
        {
            throw "noimpl";
        }
    };

    class tdx_uint64 final : public tdx_value
    {
    public:
        tdx_value_type get_type() final { return tdx_value_type::uint64; }

        std::uint_fast64_t Value = 0;

        bytes_uptr serialize() final
        {
            throw "noimpl";
        }
    };

}