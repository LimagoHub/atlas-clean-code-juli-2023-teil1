//
// Created by JoachimWagner on 03.07.2023.
//

#pragma once

#include <vector>
#include "../AbstractGame.h"

#include "../../io/Writer.h"

namespace atlas::game {

    class TakeGameImpl: public AbstractGame<int,int> {

    public:
        explicit TakeGameImpl(Writer &writer) : AbstractGame(writer) {
            setBoard(23);
        }

    protected:

        // Im Implementierungssumpf --------------------------------------

        bool isTurnValid() const override { return getMove() >= 1 && getMove() <= 3; }

        void updateBoard() override { setBoard(getBoard() - getMove()) ;} // Operation

        bool isGameover() const override { // Operation
            return getBoard() < 1 || getPlayers().empty();
        }
    };
}
