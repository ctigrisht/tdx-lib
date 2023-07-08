#pragma once

#include <string>
#include <vector>

#include "tdx_value.hpp"

namespace tdx_models
{
    class tdx_vector
    {
    private:
    public:
        std::string PrimaryCollection;
        std::string StickyCollection;
    };

    class vector_relationship
    {
    public:
        std::string Name;
        std::vector<tdx_value> Values;
    };
}