cmake_minimum_required(VERSION 3.16)
project(TakeGameProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(TakeGameProject main.cpp game/Game.h game/TakeGame/TakeGameImpl.h client/GameClient.h game/TakeGame/players/AbstractTakeGamePlayer.h game/TakeGame/players/HumanPlayer.h game/TakeGame/players/ComputerPlayer.h io/Writer.h io/ConsoleWriter.h game/AbstractGame.h game/Players/Player.h game/Players/AbstractPlayer.h)
