//
// Created by Tristan Kalmbach on 10/12/17.
//

#pragma once

enum HandRanks
{
    None,
    Pair, // Two cards of the same rank.
    TwoPair, // Two different pairs.
    ThreeOfAKind, // Three cards of the same rank.
    Straight, // Five cards in a sequence, but not of the same suit.
    Flush, // Any five cards of the same suit, but not in a sequence.
    FullHouse, // Three of a kind with a pair.
    FourOfAKind, // Four cards of the same rank.
    StraightFlush, // Five cards in a sequence, all in the same suit.
    RoyalFlush // A, K, Q, J, 10, all the same suit.
};
