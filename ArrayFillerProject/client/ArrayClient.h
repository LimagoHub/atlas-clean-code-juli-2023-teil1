//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once


#include <memory>
#include "../collections/array_factory.h"
class ArrayClient {

    std::shared_ptr<atlas::collections::array_factory<int>> factory_;

public:

    explicit ArrayClient(const std::shared_ptr<atlas::collections::array_factory<int>> &factory) : factory_(factory) {}

    auto go() {
        auto data = factory_->create_and_fill_array(1000);
        // Do something with array (Fachlogik)
    }
};
