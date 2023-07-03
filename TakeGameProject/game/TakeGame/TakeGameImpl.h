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
            while(! is_gameover()) {
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

        void player_move() { // Mischmasch (kaese)
            if(is_gameover()) return;

            while(true) {
                std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3." << std::endl;
                std::cin >> move;
                if(is_turn_valid()) break;
                std::cout << "Ungueltiger Zug" << std::endl;
            }
            terminateMove("Mensch");
        }




        void computer_move() { // Mischmasch (kaese)
            if(is_gameover()) return;

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
            if(is_gameover()) {
                std::cout << player << " hat verloren" << std::endl;
            }
        }

        // Im Implemetierungssumpf --------------------------------------

        bool is_turn_valid() const { return move >= 1 && move <= 3; }
        void updateBoard() { stones -= move; } // Operation

        bool is_gameover() { // Operation
            return stones < 1;
        }
    };
}
