//
// Created by JoachimWagner on 04.07.2023.
//

#pragma once

#include <iostream>
#include "AbstractTakeGamePlayer.h"

class ComputerPlayer :public AbstractTakeGamePlayer{
    constexpr static const int moves[] = {3,1,1,2};
public:
    explicit ComputerPlayer(const std::string &name) : AbstractTakeGamePlayer(name) {}

    int requestMove(const int &stones) const override {
        int move;

        move  = moves[stones % 4];
        std::cout << "Computer nimmt" << move << "Steine." << std::endl;

        return move;
    }
};
