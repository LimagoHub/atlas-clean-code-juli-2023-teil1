//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once

#include <memory>
#include "generator.h"
namespace atlas::generators {
    template<class T>
    class generator_factory {
        public:
            virtual ~generator_factory() = default;
            [[nodiscard]] virtual auto create() const->std::unique_ptr<generator<T>> = 0;
    };
}
