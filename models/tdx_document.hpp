#pragma once

#include <unordered_map>
#include <string>

#include "values/tdx_value.hpp"

// using namespace std;

namespace tdx_models{
    class tdx_document
    {
    private:
        /* data */
    public:
        std::string Header;
        std::unordered_map<std::string, tdx_values::tdx_value> Values;
        tdx_values::tdx_value_type Type = tdx_values::tdx_value_type::int32;

        tdx_document(/* args */);
        ~tdx_document();
    };
    
    tdx_document::tdx_document(/* args */)
    {

    }
    
    tdx_document::~tdx_document()
    {

    }
    
}