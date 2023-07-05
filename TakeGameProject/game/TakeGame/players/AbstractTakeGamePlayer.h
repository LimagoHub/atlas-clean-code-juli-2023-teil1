//
// Created by JoachimWagner on 04.07.2023.
//

#pragma once
#include "../../Players/AbstractPlayer.h"

class AbstractTakeGamePlayer: public AbstractPlayer<int, int> {



public:
    AbstractTakeGamePlayer(const std::string &name) : AbstractPlayer(name) {}



};
