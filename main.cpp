#include <iostream>

#include "main.hpp"

#include "includes.hpp"

int main(){
    tdx_values::tdx_value* doc = new tdx_values::tdx_string(
            std::make_shared<std::u8string>(u8"hello"));

    auto bytes = doc->serialize();

    std::cout << bytes << std::endl;


    delete doc;
//    std::cout << "Hello twitch :)" << std::endl;

    return 0;
}

int serialize(){
    return 0;
}