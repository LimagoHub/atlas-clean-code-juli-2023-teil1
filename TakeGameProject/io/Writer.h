//
// Created by JoachimWagner on 04.07.2023.
//

#pragma once


#include <string>

class Writer {

public:
    virtual void write(const std::string &message) = 0;

};
