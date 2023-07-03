cmake_minimum_required(VERSION 3.20)
project(TakeGameProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(TakeGameProject main.cpp game/Game.h game/TakeGame/TakeGameImpl.h client/GameClient.h)
