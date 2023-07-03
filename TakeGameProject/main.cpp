#include <iostream>
#include "game/TakeGame/TakeGameImpl.h"
#include "client/GameClient.h"
int main() {

    atlas::game::TakeGameImpl game;
    GameClient client{game};
    client.go();

    return 0;
}
