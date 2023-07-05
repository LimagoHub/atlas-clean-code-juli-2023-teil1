//
// Created by JoachimWagner on 04.07.2023.
//

#pragma once

#include <iostream>
#include "Writer.h"

class ConsoleWriter :public Writer{
public:
    void write(const std::string &message) override {
        std::cout << message << std::endl;
    }
};
