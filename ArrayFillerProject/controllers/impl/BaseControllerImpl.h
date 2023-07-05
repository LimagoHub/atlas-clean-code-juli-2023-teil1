//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once
#include <memory>
#include "../BaseController.h"
#include "../../client/ArrayClient.h"
#include "../../collections/impl/sequential/array_factory_sequential_impl.h"
#include "../../collections/impl/parallel/array_factory_parallel_impl.h"
#include "../../collections/impl/decorators/array_factory_benchmark_decorator.h"
#include "../../generators/random/mersenne_twister_number_generator.h"

using namespace atlas::collections;

namespace atlas::controllers {
    class BaseControllerImpl: public BaseController {

        using array_filler_pointer = array_factory<int>;
        using array_benchmark= array_factory_benchmark_decorator<int>;
        using my_generator = atlas::generators::mersenne_twister_number_generator;

        auto create()-> int {

            std::unique_ptr<array_factory<int>> arrayFactoryPointer_;
            auto generator_ = std::make_unique<my_generator>() ;

            arrayFactoryPointer_ = std::make_unique<array_factory_sequential_impl<int>>(std::move(generator_));
            arrayFactoryPointer_ = std::make_unique<array_benchmark>(std::move(arrayFactoryPointer_));

            ArrayClient client_{std::move(arrayFactoryPointer_)};
            client_.go();


            return 0;
        }
    public:
        auto run() -> void override {
            create();
        }
    };
}
