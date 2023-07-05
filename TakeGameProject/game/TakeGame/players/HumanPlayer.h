//
// Created by JoachimWagner on 04.07.2023.
//

#pragma once

#include <iostream>
#include "AbstractTakeGamePlayer.h"

class HumanPlayer: public AbstractTakeGamePlayer {
public:
    explicit HumanPlayer(const std::string &name) : AbstractTakeGamePlayer(name) {}

    int requestMove(const int &stones) const override {
        int move;
        std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3." << std::endl;
        std::cin >> move;
        return move;
    }
};
