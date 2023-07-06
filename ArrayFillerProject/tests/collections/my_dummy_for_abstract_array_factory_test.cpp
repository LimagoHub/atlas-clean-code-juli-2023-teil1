//
// Created by JoachimWagner on 06.07.2023.
//
#include "gmock/gmock.h"
#include "my_dummy_for_abstract_array_factory_test.h"
using namespace atlas::collections;
TEST_F(my_dummy_for_abstract_array_factory_test,create_intitialized) {

    auto result = object_under_test.create_and_fill_array(10);
    EXPECT_THAT(*result, Not(IsEmpty()));
}