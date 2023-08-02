#pragma once

#include <variant>

namespace vr {
    template<typename TValue, typename TError>
    class result {
    public:
        result(TValue value){

        }

        result(TError error){

        }

        std::variant<TValue, TError> _data;

        bool is_error() {
            return std::holds_alternative<TError>(_data);
        }

        TValue get_value() {

        }

        TError get_error(){
            return std::variant_alternative(_data);
        }
    };
}