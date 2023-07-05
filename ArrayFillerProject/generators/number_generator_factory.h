//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once
#include <memory>
#include "number_generator.h"


namespace atlas::generators {
    class number_generator_factory {

    public:

        virtual ~number_generator_factory() = default;

        [[nodiscard]] virtual auto create() const->std::unique_ptr<number_generator> = 0;
    };
}
