#pragma once

#include <string>
#include <variant>
#include <optional>

namespace vr {
    template<typename TValue, typename TError>
    class result {
    public:
        result(TValue value) {
            _data = std::move(value);
        }

        result(TError error) {
            _data = std::move(error);
        }

        std::variant<TValue, TError> _data;

        bool is_error() {
            return std::holds_alternative<TError>(_data);
        }

        bool is_success() {
            return std::holds_alternative<TValue>(_data);
        }

        std::optional<TValue &> try_get_value() {
            if (!std::holds_alternative<TValue>(_data))
                return std::nullopt;
            return &std::get<TValue>(_data);
        }

        TValue move_value(){
            return std::move(std::get<TValue>(_data));
        }

        TValue& get_value() {
            return std::get<TValue>(_data);
        }

        TError& get_error() {
            return std::get<TValue>(_data);
        }
    };

    template<typename TValue>
    class str_result : public result<TValue, std::string> {
    public:
        str_result(TValue value) {
            this->_data = std::move(value);
        }

        str_result(std::string error) {
            this->_data = std::move(error);
        }
    };
}