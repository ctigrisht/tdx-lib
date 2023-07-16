#pragma once

using bytes_uptr = std::unique_ptr<std::byte[]>;
template <typename T> using sptr = std::shared_ptr<T>;
template <typename T> using const_sptr = std::shared_ptr<const T>;