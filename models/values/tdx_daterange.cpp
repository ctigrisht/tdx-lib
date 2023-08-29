#include "tdx_daterange.hpp"

namespace tdx_values {
    tdx_bytes_result tdx_daterange::serialize() {
        if (!value.has_value())
            return (false);

        auto l_value = value.value();

        auto value_first = l_value[0];
        auto value_last = l_value[1];

        stdbyte *bytes_first = static_cast<std::byte *>(static_cast<void *>(&value_first));
        stdbyte *bytes_last = static_cast<std::byte *>(static_cast<void *>(&value_last));


        byte_vector final_vec = {};
        final_vec.resize(sizeof(int64_t) * 2);

        if constexpr (std::endian::native == std::endian::big)
            return (false);
        else {

//            for (int i = 0; i < sizeof(int64_t) ++i) {
//
//            }
            final_vec[0] = bytes_first[0];
            final_vec[1] = bytes_first[1];
            final_vec[2] = bytes_first[2];
            final_vec[3] = bytes_first[3];
            final_vec[4] = bytes_first[4];
            final_vec[5] = bytes_first[5];
            final_vec[6] = bytes_first[6];
            final_vec[7] = bytes_first[7];

            final_vec[8] = bytes_last[0];
            final_vec[9] = bytes_last[1];
            final_vec[10] = bytes_last[2];
            final_vec[11] = bytes_last[3];
            final_vec[12] = bytes_last[4];
            final_vec[13] = bytes_last[5];
            final_vec[14] = bytes_last[6];
            final_vec[15] = bytes_last[7];

//            final_vec[0] = (stdbyte) (value_first << 0);
//            final_vec[1] = (stdbyte) (value_first << 8 * 1);
//            final_vec[2] = (stdbyte) (value_first << 8 * 2);
//            final_vec[3] = (stdbyte) (value_first << 8 * 3);
//            final_vec[4] = (stdbyte) (value_first << 8 * 4);
//            final_vec[5] = (stdbyte) (value_first << 8 * 5);
//            final_vec[6] = (stdbyte) (value_first << 8 * 6);
//            final_vec[7] = (stdbyte) (value_first << 8 * 7);
//
//            final_vec[8] = (stdbyte) (value_last << 0);
//            final_vec[9] = (stdbyte) (value_last << 8 * 1);
//            final_vec[10] = (stdbyte) (value_last << 8 * 2);
//            final_vec[11] = (stdbyte) (value_last << 8 * 3);
//            final_vec[12] = (stdbyte) (value_last << 8 * 4);
//            final_vec[13] = (stdbyte) (value_last << 8 * 5);
//            final_vec[14] = (stdbyte) (value_last << 8 * 6);
//            final_vec[15] = (stdbyte) (value_last << 8 * 7);

            return {std::move(final_vec)};
        }
    }

    tdx_daterange tdx_daterange::parse(std::span<stdbyte> &value) {
        int64_t first_value;
        memcpy(&first_value, value.subspan(0, 8).data(), sizeof(int64_t));

        int64_t last_value;
        memcpy(&last_value, value.subspan(8, 8).data(), sizeof(int64_t));

        return tdx_daterange{{first_value, last_value}};
    }
}