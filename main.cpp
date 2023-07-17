#include <iostream>
#include <string>

#include "main.hpp"

#include "includes.hpp"

void test_int16();
void test_string();

int main() {

    test_int16();
    test_string();

    return 0;
}

void test_int16() {
    std::vector<std::int_fast16_t> tests{
            1,
            10230,
            6000,
            31309,
            1231,
            -4430,
            -32
    };

    for (std::int_fast16_t value: tests) {
//        std::cout << "Testing: " << value;

        tdx_values::tdx_int16 i16 = tdx_values::tdx_int16(value);

        auto bytes = i16.serialize();
        auto parsed = tdx_values::tdx_int16::parse(bytes);

        std::cout
                << "Test '" << value << "' "
                << (parsed.value.value() == value ? "passed" : "failed")
                << std::endl;
//        std::cout << " : " << parsed.value.value() << std::endl;
    }
}

void test_string() {
    std::vector<std::string> tests{
        "Hello Twitch :)",
        "Bonjour éééééé",
        "科區文常中標最得還"
    };

    for (std::string test : tests){
        tdx_values::tdx_value *doc = new tdx_values::tdx_string(
                std::make_unique<std::string>());

        auto bytes = doc->serialize();

        std::byte arr[bytes.size()];

//        std::cout << "Bytes: " << std::endl;
        for (auto byte: bytes)
            std::cout << std::int_fast32_t(byte);

        std::cout << std::endl;

        auto parsed = tdx_values::tdx_string::parse(bytes);

        std::string final = *parsed.value_u8;
        std::cout
            << "Test '" << test << "' "
            << (final == test ? "passed" : "failed")
            << std::endl;
//        std::cout << *parsed.value_u8 << std::endl;
        delete doc;
    }



}

int serialize() {
    return 0;
}