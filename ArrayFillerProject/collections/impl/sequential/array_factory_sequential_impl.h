//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once
#include "../../abstract_array_factory.h"
#include "../../../generators/generator.h"

namespace atlas::collections {

    template<class T>
    class array_factory_sequential_impl :public abstract_array_factory<T>{
        using MyGenerator =  std::unique_ptr<atlas::generators::generator<T>>;
        MyGenerator generator_;


    public:
        explicit array_factory_sequential_impl(MyGenerator generator) : generator_(std::move(generator)) {}
        ~array_factory_sequential_impl()  override = default;
    protected:
        auto fill_array() -> void override {
            auto field = this->getData();
            for (size_t i = 0; i < this->getSize(); ++i) {
                field->at(i) = generator_->next();
            }
        }

    };

}
