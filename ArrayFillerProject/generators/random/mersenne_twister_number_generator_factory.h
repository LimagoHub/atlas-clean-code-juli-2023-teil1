//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once

#include "../number_generator_factory.h"
#include "mersenne_twister_number_generator.h"

namespace atlas::generators {
    class mersenne_twister_number_generator_factory : public number_generator_factory {
    public:


        ~mersenne_twister_number_generator_factory() override = default;
        [[nodiscard]] auto create() const -> std::unique_ptr<generator<int>> override
        {
            return std::make_unique<mersenne_twister_number_generator>();
        }
    };
}
