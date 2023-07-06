#pragma once
#include <chrono>
#include <iostream>
#include <memory>
#include "../../array_factory.h"
namespace atlas::collections {
    template<class T>
    class array_factory_security_decorator: public array_factory<T>{

        using array_factory_pointer = std::unique_ptr<array_factory<T>>;

        array_factory_pointer arrayFactory_;

    public:
        explicit array_factory_security_decorator(array_factory_pointer _arrayFactory) : arrayFactory_(std::move(_arrayFactory)) {}
        ~array_factory_security_decorator() override = default;
        auto create_and_fill_array(size_t size) -> std::shared_ptr<std::vector<T>> override {
            std::cout << "Du kommst hier rein." << std::endl;
            return arrayFactory_->create_and_fill_array(size);

        }
    };
}