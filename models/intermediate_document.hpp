#include <string>

#include "values/tdx_value.hpp"

namespace tdx_models{
    extern "C" struct intermediate_string {
        bool has_value = false;
        int encoding;
        char* value;
    };

    extern "C" struct intermediate_int32{
        bool has_value = false;
        int_fast32_t value;
    };

    extern "C" struct intermediate_value{
        char* key;
        tdx_values::tdx_value_type type = tdx_values::tdx_value_type::null;

        intermediate_string* string_value = NULL;
        intermediate_int32* int32_value = NULL;
    };

    extern "C" struct intermediate_property{
        char* name;
        intermediate_value value;
    };

    extern "C" struct intermediate_document{
        int properties_count = 0;
        intermediate_property* properties = [];
    };
}