//
// Created by JoachimWagner on 06.07.2023.
//

#pragma once
#include "Caclulator.h"

class CalculatorExtension : public Caclulator{

public:
    virtual auto mult(double a, double b) const -> double = 0;

};
