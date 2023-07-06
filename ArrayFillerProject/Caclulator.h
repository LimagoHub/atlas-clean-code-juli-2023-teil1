//
// Created by JoachimWagner on 06.07.2023.
//

#pragma once


class Caclulator {

public:
    virtual auto add(double a, double b) const -> double = 0;
    virtual auto sub(double a, double b) const -> double = 0;

};
