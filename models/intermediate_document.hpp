#include <string>


namespace tdx_models{
    extern "C" struct intermediate_optional_string {
        bool has_value = false;
        std::string value;
    };

    extern "C" struct intermediate_value{
        std::string key;
        int type;

    };

    extern "C" struct intermediate_document{

    };
}