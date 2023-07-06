//
// Created by JoachimWagner on 06.07.2023.
//

#pragma once

#include <vector>
#include <thread>
#include <cmath>
#include <algorithm>
#include <execution>

#include "../../abstract_array_factory.h"
#include "../../../generators/number_generator_factory.h"
using namespace atlas::generators;

namespace atlas::collections {

    template<class T>
    class array_factory_auto_impl :public abstract_array_factory<T>{
        using MyGeneratorFactory = std::unique_ptr<generator_factory<T>>;
        MyGeneratorFactory generatorFactory_;

    public:
        explicit array_factory_auto_impl(MyGeneratorFactory generatorFactory) : generatorFactory_(
                std::move(generatorFactory)) {}

        ~array_factory_auto_impl() override = default;

    protected:
        auto fill_array() -> void override {
            auto generator = generatorFactory_->create();
            std::for_each(std::execution::par, this->getData()->begin(), this->getData()->end(),[&generator](T &value){
                value = generator->next();
            });
        }
    };
}
