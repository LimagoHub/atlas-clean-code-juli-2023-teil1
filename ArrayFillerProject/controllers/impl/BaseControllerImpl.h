//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once
#include <memory>
#include "../BaseController.h"
#include "../../client/ArrayClient.h"
#include "../../collections/impl/sequential/array_factory_sequential_impl.h"
#include "../../collections/impl/parallel/array_factory_parallel_impl.h"
#include "../../collections/impl/parallel/array_factory_auto_impl.h"
#include "../../collections/impl/decorators/array_factory_benchmark_decorator.h"
#include "../../collections/impl/decorators/array_factory_logging_decorator.h"
#include "../../collections/impl/decorators/array_factory_security_decorator.h"
#include "../../generators/random/mersenne_twister_number_generator.h"
#include "../../generators/random/mersenne_twister_number_generator_factory.h"

using namespace atlas::collections;

namespace atlas::controllers {
    class BaseControllerImpl: public BaseController {

        using array_filler_pointer = std::unique_ptr<array_factory<int>>;
        using array_benchmark= array_factory_benchmark_decorator<int>;
        using array_logging= array_factory_logging_decorator<int>;
        using array_security= array_factory_security_decorator<int>;
        using my_generator_factory_pointer = std::unique_ptr<atlas::generators::generator_factory<int>>;

        auto create(const size_t threadCount = 1) const -> void  {

            array_filler_pointer arrayFactoryPointer_;
            my_generator_factory_pointer factory_;

            std::cout << "Messung mit " << threadCount << " Threads: " ;

            factory_ = create_generator_factory();
            arrayFactoryPointer_ = create_array_factory(threadCount, std::move(factory_));

            ArrayClient client_{std::move(arrayFactoryPointer_)};
            client_.go();

        }

        auto create_generator_factory() const-> my_generator_factory_pointer {
            return std::make_unique<mersenne_twister_number_generator_factory>();
         }

        auto create_array_factory(const size_t threadCount, my_generator_factory_pointer factory_) const -> array_filler_pointer {
            array_filler_pointer arrayFactoryPointer_;
            if(threadCount == 1)
                arrayFactoryPointer_ = std::make_unique<array_factory_sequential_impl<int>>(std::move(factory_->create()));
            else
                //arrayFactoryPointer_ = std::make_unique<array_factory_parallel_impl<int>>(std::move(factory_), threadCount);
                arrayFactoryPointer_ = std::make_unique<array_factory_auto_impl<int>>(std::move(factory_));

            arrayFactoryPointer_ = std::make_unique<array_benchmark>(std::move(arrayFactoryPointer_));
            arrayFactoryPointer_ = std::make_unique<array_logging>(std::move(arrayFactoryPointer_));
            arrayFactoryPointer_ = std::make_unique<array_security>(std::move(arrayFactoryPointer_));
            return arrayFactoryPointer_;
        }


    public:
        ~BaseControllerImpl() override = default ;
        auto run() -> void override {
            auto availableProcessors = std::thread::hardware_concurrency();
            for (int threadCount = 1; threadCount <= availableProcessors + 1; ++threadCount) {
                create(threadCount);
            }

        }
    };
}
