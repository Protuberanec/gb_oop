cmake_minimum_required(VERSION 3.20)
project(OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP main.cpp BlackJack.cpp BlackJack.h Card.cpp Card.h Hand.cpp Hand.h myPair.cpp myPair.h GenericPlayer.cpp GenericPlayer.h)
