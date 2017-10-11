//
// Created by Tristan Kalmbach on 10/11/17.
//

#pragma once

#include "Card.hpp"

#define NUM_DECKS 4

class Deck {

public:
    Deck();
    ~Deck()
    {
        m_deck.clear();
    }

    void FillDeck();
    void ShuffleDeck();

    // Debugging & Testing methods
    void PrintDeckDetails();

private:
    std::vector<Card> m_deck;
};
