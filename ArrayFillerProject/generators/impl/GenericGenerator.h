//
// Created by JoachimWagner on 06.07.2023.
//

#pragma once

#include <memory>
#include <functional>
#include "../generator.h"
namespace atlas::generators {
    class GenericGenerator : public generator<int> {

        int value{0};
        std::function<int(int)> myFunc;
    public:
        GenericGenerator(int seed, const std::function<int(int)> &myFunc) : value(seed), myFunc(myFunc) {}

        ~GenericGenerator() override = default;

        auto next() -> int override {
            int result = value;
            value = myFunc(value);
            return result;
        }
    };
}