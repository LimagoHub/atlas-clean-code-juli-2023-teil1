//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once
#include <memory>
#include "generator_factory.h"


namespace atlas::generators {
    class number_generator_factory: public generator_factory<int> {

    public:

        ~number_generator_factory()  override = default;
        [[nodiscard]] auto create() const -> std::unique_ptr<generator<int>> override = 0;
    };
}
