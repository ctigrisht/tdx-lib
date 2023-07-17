#pragma once

#include <vector>

//struct dynamic_byte_array{
//    int length = 0;
//    std::byte[] array;
//};

using byte_vector = std::vector<std::byte>;
//using bytes_uptr = std::unique_ptr<dynamic_byte_array>;
template <typename T> using sptr = std::shared_ptr<T>;
template <typename T> using const_sptr = std::shared_ptr<const T>;