cmake_minimum_required(VERSION 3.8)
project(Poker)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Cards/Card.cpp Cards/Card.hpp Cards/CardProperties.hpp Cards/Deck.cpp Cards/Deck.hpp)
add_executable(Poker ${SOURCE_FILES})