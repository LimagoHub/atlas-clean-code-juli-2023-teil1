//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once
#include "array_factory.h"
namespace atlas::collections {



    template<class T>
    class abstract_array_factory: public array_factory<T>{
        using ArrayPointer = std::shared_ptr<T[]>;

        ArrayPointer data_;
        size_t size_;

    protected:
        auto getData() -> ArrayPointer const {
            return data_;
        }



        auto getSize() -> size_t const {
            return size_;
        }

        virtual auto fill_array() -> void = 0;

    public:
        auto create_and_fill_array(size_t size) -> ArrayPointer override {
            data_ = std::shared_ptr<T[]>{new T[size]};
            size_ = size;
            fill_array();
            return data_;
        }
    };
}
