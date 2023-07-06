//
// Created by JoachimWagner on 06.07.2023.
//

#include "array_factory_sequential_impl_test.h"

using namespace atlas::collections;

TEST_F(array_factory_sequential_impl_test, bla) {

    auto  generator_mock_ = std::make_unique<generator_mock>();


    EXPECT_CALL(*generator_mock_, next())
        .WillOnce(Return(2))
        .WillOnce(Return(4))
        .WillOnce(Return(8));

    array_factory_sequential_impl<int> object_under_test{std::move(generator_mock_)};
    auto result = object_under_test.create_and_fill_array(3);

    EXPECT_THAT(*result, ElementsAre(2,4,8));
    EXPECT_THAT(*result, SizeIs(3));

}
