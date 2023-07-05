#include <iostream>
#include "game/TakeGame/TakeGameImpl.h"
#include "client/GameClient.h"
#include "io/ConsoleWriter.h"
#include "game/TakeGame/players/HumanPlayer.h"
#include "game/TakeGame/players/ComputerPlayer.h"

int main() {

    ConsoleWriter writer;
    HumanPlayer fritz{"Fritz"};
    ComputerPlayer hal{"HAL"};
    atlas::game::TakeGameImpl game{writer};
    game.addPlayer(&fritz);
    game.addPlayer(&hal);
    GameClient client{game};
    client.go();

    return 0;
}
