cmake_minimum_required(VERSION 3.25)
project(ArrayFillerProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(ArrayFillerProject main.cpp controllers/BaseController.h time/stopwatch.h client/ArrayClient.h)
