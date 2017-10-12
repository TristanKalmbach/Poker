//
// Created by Tristan Kalmbach on 10/11/17.
//

#pragma once

#include "Card.hpp"
#include <algorithm>

// Setting to increase number of decks used in the game. Default is 1.
#define NUM_DECKS 1
#define HAND_SIZE 5

using Hand = std::list<Card>;

class Deck
{

public:
    Deck();
    ~Deck() { m_deck.clear(); }

    // Main methods
    void FillDeck();
    void ShuffleDeck();
    Hand CreateHand();
    Card GetRandomCardFromDeck();
	void RemoveCardFromDeck(std::pair<int, int> pair);

    // Debugging & Testing methods
    void PrintDeckDetails();

private:
    std::vector<Card> m_deck;
};
