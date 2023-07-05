//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once
#include <random>
#include <climits>
#include "../number_generator.h"

namespace atlas::generators {
    class mersenne_twister_number_generator : public number_generator {
    public:
        explicit mersenne_twister_number_generator()
                : device_{}
                , rng_{ device_() }
                , distribution_(INT_MIN, INT_MAX)
        {
            // NOOP
        }

        [[nodiscard]] auto next() -> int { return distribution_(rng_); }

    private:
        std::random_device device_;
        mutable std::mt19937 rng_;
        std::uniform_int_distribution<std::int32_t> distribution_;
    };

}