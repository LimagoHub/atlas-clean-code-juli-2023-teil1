//
// Created by JoachimWagner on 04.07.2023.
//

#pragma once

#include <vector>
#include "Game.h"
#include "Players/Player.h"
#include "../io/Writer.h"

namespace atlas::game {
    template<class BOARD, class MOVE>

    class AbstractGame : public Game {

    public:
        explicit AbstractGame(Writer &writer) : writer(writer) {}
        void play() override {
            while(!isGameover()) {
                playRound();
            }
        }

        void addPlayer(Player<BOARD,MOVE> * player) {
            players.push_back(player);
        }

        void removePlayer(Player<BOARD,MOVE> * player) {
            // TODO Implement
        }


    private:
        Writer &writer;
        BOARD board;
        MOVE move;


        // Observer
        std::vector<Player<BOARD,MOVE> *> players;
        Player<BOARD,MOVE>  * currentPlayer;

        void playRound() { // Integration
            for( const auto &player : players){
                setCurrentPlayer(player);
                playSingleMove();
            }
         }

        void playSingleMove() { // Integration
            if(isGameover()) return;
            executeMove();
            terminateMove();
        }

        void terminateMove( ) { // Integration
            updateBoard();
            printGameOverMessageIfGameIsOver();
        }

        void executeMove()  {
            do {
                move = currentPlayer->requestMove(board);
            }  while(turnIsInvalid());
        }
        bool turnIsInvalid() {
            if(isTurnValid()) return false;
            write( "Ungueltiger Zug");
            return true;
        }
        void printGameOverMessageIfGameIsOver() { // Operation
            if(isGameover()) {
                write( currentPlayer->getName() + " hat verloren" );
            }
        }

        void setCurrentPlayer(Player<BOARD,MOVE> *currentPlayer) {
            this->currentPlayer = currentPlayer;
        }

    protected:
        const std::vector<Player<BOARD, MOVE> *> &getPlayers() const {
            return players;
        }
        BOARD getBoard() const {
            return board;
        }

        void setBoard(BOARD board) {
            AbstractGame::board = board;
        }

        MOVE getMove() const {
            return move;
        }

        void setMove(MOVE move) {
            AbstractGame::move = move;
        }
        void write(std::string message) {
            writer.write(message);
        }
        virtual  bool isGameover() const = 0;
        virtual void updateBoard() = 0;
        virtual bool isTurnValid() const = 0;
    };

}
