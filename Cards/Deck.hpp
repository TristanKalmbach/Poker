//
// Created by Tristan Kalmbach on 10/11/17.
//

#pragma once

#include "Card.hpp"
#include "Hand.hpp"

// Setting to increase number of decks used in the game. Default is 1.
#define NUM_DECKS 1

class Deck
{

public:
    Deck();
    ~Deck() { m_deck.clear(); }

    // Main methods
    void FillDeck();
    void ShuffleDeck();
    std::shared_ptr<Hand> CreateHand();
    Card GetRandomCardFromDeck();

    // Debugging & Testing methods
    void PrintDeckDetails();

private:
    std::vector<Card> m_deck;
};
