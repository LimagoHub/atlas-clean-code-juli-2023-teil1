//
// Created by JoachimWagner on 04.07.2023.
//

#pragma once
#include "Player.h"
template<class BOARD, class MOVE>
class AbstractPlayer: public Player<BOARD, MOVE> {

    std::string name;

public:
    explicit AbstractPlayer(const std::string &name) : name(name) {}

    std::string getName() const override {
        return name;
    }

};
