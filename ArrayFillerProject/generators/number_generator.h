//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once

#pragma once

#include "generator.h"

namespace atlas::generators {

    class number_generator: public generator<int> {
    public:
        ~number_generator() override = default;
        [[nodiscard ]] auto next() -> int  override  = 0;
    };
}
