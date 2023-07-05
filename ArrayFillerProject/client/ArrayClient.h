//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once


#include <memory>
#include <climits>
#include <iostream>
#include "../collections/array_factory.h"
class ArrayClient {

    using MyFactory =  std::unique_ptr<atlas::collections::array_factory<int>>;

    MyFactory factory_;

public:

    explicit ArrayClient(MyFactory factory) : factory_(std::move(factory)) {}

    auto go() {
        auto data = factory_->create_and_fill_array(INT32_MAX/16);
        for (int i = 0; i < 10; ++i) {
            std::cout << data[i] << std::endl;
        }

    }
};
