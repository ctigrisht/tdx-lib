#pragma once

#include <unordered_map>
#include <vector>
#include <string>

#include "values/tdx_value.hpp"
#include "tdx_property.hpp"
#include "tdx_link.hpp"
// using namespace std;

namespace tdx_models{
    class tdx_document
    {
    private:
        /* data */
    public:
        std::string header;
        std::unordered_map<std::string, tdx_property> values;
        std::vector<tdx_link> links;

        tdx_document(/* args */);
        ~tdx_document();
    };
    
//    tdx_document::tdx_document(/* args */)
//    {
//
//    }
//
//    tdx_document::~tdx_document()
//    {
//
//    }
    
}