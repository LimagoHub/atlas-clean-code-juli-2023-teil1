//
// Created by JoachimWagner on 03.07.2023.
//

#pragma once
#include "../game/Game.h"
using namespace atlas::game;
class GameClient {
    Game &game;

public:
    explicit GameClient(Game &game) : game(game) {}

    void go() {
        game.play();
    }
};
