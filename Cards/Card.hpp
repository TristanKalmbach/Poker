//
// Created by Tristan Kalmbach on 10/11/17.
//

#pragma once

#include "CardProperties.hpp"

const std::vector<CardSuits> Suits = { CardSuits::Club, CardSuits::Diamond, CardSuits::Heart, CardSuits::Spade };
const std::vector<CardRank> Ranks = { CardRank::Ace, CardRank::Two, CardRank::Three, CardRank::Four,
                                              CardRank::Five, CardRank::Six, CardRank::Seven, CardRank::Eight,
                                              CardRank::Nine, CardRank::Ten, CardRank::Jack, CardRank::Queen,
                                              CardRank::King };

class Card
{
public:
    // Every card has a suit and a value
    Card(CardSuits suit, CardRank rank)
    {
        m_suit = suit;
        m_rank = rank;
    }

    CardSuits getSuit() const { return m_suit; }
    CardRank getRank() const { return m_rank; }

    std::string GetNameFromRank() const;
    std::string GetNameFromSuit() const;
    bool IsCardRoyal() const;
    int GetNumericalValueFromRank() const;

    // Debugging & Test methods
    void PrintCardDetails() const;

private:
    CardRank m_rank;
    CardSuits m_suit;
};