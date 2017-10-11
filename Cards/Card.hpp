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

    CardSuits getSuit() const {
        return m_suit;
    }

    void setSuit(CardSuits m_suit) {
        Card::m_suit = m_suit;
    }

    CardRank getRank() const {
        return m_rank;
    }

    void setRank(CardRank m_value) {
        Card::m_rank = m_value;
    }

    std::string GetNameFromRank(CardRank rank) const
    {
        switch (rank)
        {
            case CardRank::Ace:
                return "Ace";
            case CardRank::Two:
                return "Two";
            case CardRank::Three:
                return "Three";
            case CardRank::Four:
                return "Four";
            case CardRank::Five:
                return "Five";
            case CardRank::Six:
                return "Six";
            case CardRank::Seven:
                return "Seven";
            case CardRank::Eight:
                return "Eight";
            case CardRank::Nine:
                return "Nine";
            case CardRank::Ten:
                return "Ten";
            case CardRank::Jack:
                return "Jack";
            case CardRank::Queen:
                return "Queen";
            case CardRank::King:
                return "King";
            default:
                return "Error";
        }
    }

    std::string GetNameFromSuit(CardSuits suit) const
    {
        switch (suit)
        {
            case CardSuits::Club:
                return "Clubs";
            case CardSuits::Diamond:
                return "Diamonds";
            case CardSuits::Heart:
                return "Hearts";
            case CardSuits::Spade:
                return "Spades";
            default:
                return "Error";
        }
    }

    // Debugging & Test methods
    void PrintCardDetails() const;

private:
    CardRank m_rank;
    CardSuits m_suit;
};