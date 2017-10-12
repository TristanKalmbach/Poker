//
// Created by Tristan Kalmbach on 10/12/17.
//

#pragma once

#include "../Cards/Hand.hpp"

class HandEvaluator
{
public:
    static bool HasFlush(Hand const &hand);
    static bool HasRoyalFlush(Hand const &hand);
    static bool HasStraight(Hand const &hand);
    static bool HasPair(Hand const &hand);
    static bool HasThreeOfKind(Hand const &hand);
    static bool HasTwoPair(Hand const &hand);
    static bool HasFourOfKind(Hand const &hand);
    static bool IsStraightFlush(Hand const &hand);
    static bool IsFullHouse(Hand const &hand);

private:
    HandEvaluator();
    ~HandEvaluator();
};
