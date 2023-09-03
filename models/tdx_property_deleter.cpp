#include "tdx_property_deleter.hpp"
#include "tdx_property.hpp"

namespace tdx_models{
    void tdx_property_deleter::operator()(tdx_models::tdx_property *p) const {
        std::default_delete<tdx_property>{}(p);
    }
}