//
// Created by JoachimWagner on 06.07.2023.
//

#pragma once
#include "gmock/gmock.h"
#include "../../../collections/impl/sequential/array_factory_sequential_impl.h"
#include "../../../generators/generator.h"
//class MockBlacklistService : public BlacklistService {
//public:
//    MOCK_METHOD(bool, is_blacklisted, (const person& person), (const, override));
//
//};

class Dummy{};

class generator_mock: public atlas::generators::generator<int> {
public:
    MOCK_METHOD(int, next, (), ( override));
};


using namespace testing;
namespace atlas::collections {
    class array_factory_sequential_impl_test: public Test {
        protected:
          generator_mock generator_mock_;
          array_factory_sequential_impl<int> object_under_test{std::move(std::make_unique<generator_mock>())};
    };
}
