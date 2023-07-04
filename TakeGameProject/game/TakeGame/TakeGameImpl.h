//
// Created by JoachimWagner on 03.07.2023.
//

#pragma once
#include "../Game.h"
namespace atlas::game {

    class TakeGameImpl: public Game {

    public:
        TakeGameImpl() : stones(23) {}
        void play() override {
            while(!isGameover()) {
                playRound();
            }
        }
    private:
        int stones;
        int move;

        void playRound() { // Integration
            player_move();
            computer_move();
        }

        void player_move() { // Integration
            if(isGameover()) return;
            executeMove();
            terminateMove("Mensch");
        }

        void executeMove()  {
            while(true) {
                std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3." << std::endl;
                std::cin >> move;
                if(isTurnValid()) break;
                std::cout << "Ungueltiger Zug" << std::endl;
            }
        }


        void computer_move() { // Mischmasch (kaese)
            if(isGameover()) return;

            const int moves[] = {3,1,1,2};
            move  = moves[stones % 4];
            std::cout << "Computer nimmt" << move << "Steine." << std::endl;

            terminateMove( "Computer");
        }

        void terminateMove( std::string player) { // Integration
            updateBoard();
            printGameOverMessageIfGameIsOver(player);
        }

        void printGameOverMessageIfGameIsOver(const std::string &player) { // Operation
            if(isGameover()) {
                std::cout << player << " hat verloren" << std::endl;
            }
        }

        // Im Implemetierungssumpf --------------------------------------

        bool isTurnValid() const { return move >= 1 && move <= 3; }

        void updateBoard() { stones -= move; } // Operation

        bool isGameover() { // Operation
            return stones < 1;
        }
    };
}
