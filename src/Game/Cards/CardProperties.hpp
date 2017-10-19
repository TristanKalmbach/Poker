//
// Created by Tristan Kalmbach on 10/11/17.
//

#pragma once

#include <cstdint>
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <list>
#include <set>

enum class CardSuits : std::uint8_t
{
	Club,
	Diamond,
	Heart,
	Spade,

	MaxSuit
};

enum class CardRank : std::uint8_t
{
	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,

	MaxRank
};

enum CardPos
{
    CardOne = 0,
    CardTwo,
    CardThree,
    CardFour,
    CardFive
};