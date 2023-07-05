//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once

#include <vector>
#include <thread>
#include <cmath>
#include "../../abstract_array_factory.h"
#include "../../../generators/number_generator_factory.h"
using namespace atlas::generators;

namespace atlas::collections {

    template<class T>
    class array_factory_parallel_impl : public abstract_array_factory<T> {

        number_generator_factory &generatorFactory_;
        size_t thread_count_;
        std::vector<std::thread> threadHolder_;
        std::size_t partitionSize_;


    public:
        array_factory_parallel_impl(number_generator_factory  &generatorFactory, size_t threadCount) : generatorFactory_(
                generatorFactory),
                thread_count_(threadCount) {}



    protected:
        auto fill_array() -> void override {
            calculatePartitionSize();
            initializeThreadHolder();
            addWorkersToThreads();
            joinThreads();
        }

    private:
        auto calculatePartitionSize() -> void {
            partitionSize_ = static_cast<std::size_t>(std::floor(this->getSize() / thread_count_));
        }

        auto initializeThreadHolder()  -> void
        {
            threadHolder_ = std::vector<std::thread>{};
            threadHolder_.reserve(thread_count_);
        }

        auto addWorkersToThreads()  -> void
        {
            for (auto segment = 0U; segment < thread_count_; ++segment) {
                start_single_worker_for_segment( segment);
            }
        }

        auto joinThreads() -> void
        {
            for (auto& thread : threadHolder_) {
                thread.join();
            }
        }

        auto  start_single_worker_for_segment(const unsigned int segment) -> void
        {
            const size_t start = segment * partitionSize_;
            const size_t end = start + partitionSize_;
            threadHolder_.emplace_back(&this->fill_segment_worker, this, start, end);
        }

        auto fill_segment_worker( std::size_t startIndex, std::size_t endIndex) -> void
        {
            auto const numberGenerator = generatorFactory_.create();

            for (auto i = startIndex; i < endIndex; ++i) {
                this->getData()[i] = numberGenerator->next();

            }
        }

    };
}