//
// Created by Tristan Kalmbach on 10/11/17.
//

#include "Deck.hpp"

void Deck::FillDeck()
{
    for (int numDecks = 0; numDecks < NUM_DECKS; ++numDecks)
        for (auto const &s : Suits)
            for (auto const &r : Ranks)
            {
                Card card(s, r);
                m_deck.push_back(card);
            }

    Deck::ShuffleDeck();
}

void Deck::ShuffleDeck()
{
    // Randomly shuffle the deck.
    std::mt19937 g(std::random_device{}());
    std::shuffle(m_deck.begin(), m_deck.end(), g);
}

Deck::Deck()
{
    Deck::FillDeck();
}

void Deck::PrintDeckDetails()
{
    std::cout << "Deck Size: " << m_deck.size() << "\n";

    for (auto const &d : m_deck)
        d.PrintCardDetails();
}
