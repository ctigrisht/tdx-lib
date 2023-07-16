#include "types_table_helper.hpp"
#include "../../models/values/tdx_type.hpp"

using namespace tdx_values;

namespace lib_internal {
    std::unique_ptr<std::byte[2]> get_type_code(tdx_value_type type) {
        switch (type){
            case tdx_value_type::null:
                return [0, 1];

            default:
                return [0, 1];
        }
    }
}