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

enum CardFlags
{
	FLAG_NONE = 0x0,
	FLAG_CARD_DRAWN = 0x1,
	FLAG_CARD_REMOVED = 0x2
};

class Card
{
public:
    // Every card has a suit and a value
	Card(): m_rank(), m_suit(), m_flags()
	{

	}

	Card(CardSuits suit, CardRank rank): m_flags(FLAG_NONE)
	{
		m_suit = suit;
		m_rank = rank;
	}

	CardSuits getSuit() const { return m_suit; }
    CardRank getRank() const { return m_rank; }

	// std::pair<suit, rank>
	std::pair<int, int> GetCardAsIntPair() const;

    std::string GetNameFromRank() const;
    std::string GetNameFromSuit() const;
    bool IsCardRoyal() const;

	// Flags
	void SetFlags(const CardFlags flags) { m_flags = flags; }
	CardFlags GetFlags() const { return m_flags; }

	// For magic
    int GetNumericalValueFromRank() const;
	int GetNumericalValueFromSuit() const;

    // Debugging & Test methods
    void PrintCardDetails() const;

private:
    CardRank m_rank;
    CardSuits m_suit;

	CardFlags m_flags;
};