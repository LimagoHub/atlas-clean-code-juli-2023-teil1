//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once
#include <chrono>
#include <iostream>
#include <memory>
#include "../../array_factory.h"
namespace atlas::collections {
    template<class T>
    class array_factory_benchmark_decorator: public array_factory<T>{

        using array_factory_pointer = std::unique_ptr<array_factory<T>>;

        array_factory_pointer arrayFactory_;

    public:
        explicit array_factory_benchmark_decorator(array_factory_pointer _arrayFactory) : arrayFactory_(std::move(_arrayFactory)) {}
        ~array_factory_benchmark_decorator() override = default;
        auto create_and_fill_array(size_t size) -> std::shared_ptr<std::vector<T>> override {
            auto start = std::chrono::high_resolution_clock::now();
            auto result = arrayFactory_->create_and_fill_array(size);
            auto ende = std::chrono::high_resolution_clock::now();
            std::cout << std::endl << "Zeit: " << std::chrono::duration_cast<std::chrono::milliseconds>(ende-start).count() << " ms" << std::endl;
            return result;
        }
    };
}