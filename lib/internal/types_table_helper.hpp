#pragma once

#include <cstddef>
#include <memory>

namespace lib_internal{
    std::unique_ptr<std::byte[2]> get_type_code();
}