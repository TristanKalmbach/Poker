//
// Created by Tristan Kalmbach on 10/12/17.
//

#pragma once

#include "../Cards/Hand.hpp"

class HandEvaluator
{
public:
    static bool IsFlush(Hand const &hand);
    static bool IsRoyalFlush(Hand const &hand);
    static bool IsStraight(Hand const &hand);
    static bool HasTwoOfKind(Hand const &hand);
    static bool HasThreeOfKind(Hand const &hand);
    static bool HasFourOfKind(Hand const &hand);
    static bool IsStraightFlush(Hand const &hand);
    static bool IsFullHouse(Hand const &hand);

private:
    HandEvaluator();
    ~HandEvaluator();
};