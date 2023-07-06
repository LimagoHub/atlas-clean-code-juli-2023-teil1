//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once
#include <memory>
#include <vector>

namespace atlas::collections {
    template<class T>
    class array_factory {


    public:
        virtual ~array_factory() = default;
        virtual auto create_and_fill_array(size_t size) -> std::shared_ptr<std::vector<T> > = 0;
    };

}
