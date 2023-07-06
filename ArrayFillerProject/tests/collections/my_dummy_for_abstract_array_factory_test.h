//
// Created by JoachimWagner on 06.07.2023.
//

#pragma once
#include "gtest/gtest.h"
#include "my_dummy_for_abstract_array_factory.h"

using namespace testing;

namespace atlas::collections {
    class my_dummy_for_abstract_array_factory_test :public Test{

    protected:
        my_dummy_for_abstract_array_factory<Dummy> object_under_test;
    };
}
