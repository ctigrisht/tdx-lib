#pragma once

#include <string>
#include <memory>

using bytes_uptr = std::unique_ptr<std::byte[]>;

namespace tdx_models
{
    enum struct tdx_value_type
    {
        null = 0,
        string = 1,
        int16 = 2,
        int32 = 3,
        int64 = 4,
        // int128 = 5,
        uint16 = 6,
        uint32 = 7,
        uint64 = 8,
        // uint128 = 9,
        float32 = 10,
        float64 = 11,
        // float128 = 12,
        decimal = 13,
        blob = 14,
        blob_ref = 15,
        json = 16,
        document = 17,
        
        guid = 100,
        uint64_id = 101,

        // relationships
        link_ref = 500,        
    };

    class tdx_value
    {
    private:
    public:
        const bool IsNull;
        const tdx_value_type Type = tdx_value_type::null;

        virtual bytes_uptr serialize();
        virtual tdx_value_type get_type();
    };

}
