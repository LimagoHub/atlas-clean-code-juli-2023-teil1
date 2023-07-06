//
// Created by JoachimWagner on 06.07.2023.
//

#pragma once
#include "../../collections/abstract_array_factory.h"

class Dummy {

};


namespace atlas::collections {
template<class T>
class my_dummy_for_abstract_array_factory: public abstract_array_factory<T> {
protected:
    auto fill_array() -> void override {
        // NOP
    }
};

}
