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


        void playRound() {

            player_move();
            computer_move();
        }

        void player_move() {
            int move;

            while(true) {
                std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3." << std::endl;
                std::cin >> move;
                if(move >= 1 && move <= 3) break;
                std::cout << "Ungueltiger Zug" << std::endl;
            }
            stones -= move;
        }

        void computer_move() {
            const int moves[] = {3,1,1,2};
            int move;
            if(stones < 1) {
                std::cout << "Du Loser" << std::endl;

                return;
            }
            if(stones == 1) {
                std::cout << "Du hast nur Glueck gehabt" << std::endl;

                return;
            }
            move  = moves[stones % 4];
            std::cout << "Computer nimmt" << move << "Steine." << std::endl;

            stones -= move;
        }

        bool is_gameover() {
            return stones < 1;
        }
    };
}
