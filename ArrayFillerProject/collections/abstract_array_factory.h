//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once
#include "array_factory.h"
namespace atlas::collections {



    template<class T>
    class abstract_array_factory: public array_factory<T>{
        using ArrayPointer = std::shared_ptr<std::vector<T>>;

        ArrayPointer data_;
        size_t size_;

    protected:
        auto getData() const -> ArrayPointer  {
            return data_;
        }



        [[nodiscard]]auto getSize() const -> size_t  {
            return size_;
        }

        virtual auto fill_array() -> void = 0;

    public:
        ~abstract_array_factory() override = default;
        auto create_and_fill_array(size_t size) -> ArrayPointer final {

            data_ = std::shared_ptr<std::vector<T>>{new std::vector<T>(size)};

            size_ = size;
            fill_array();
            return data_;
        }
    };
}
