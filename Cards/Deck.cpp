//
// Created by Tristan Kalmbach on 10/11/17.
//

#include "Deck.hpp"

// Fill the deck with cards.
void Deck::FillDeck() {
    for (int numDecks = 0; numDecks < NUM_DECKS; ++numDecks)
        for (auto const &s : Suits)
            for (auto const &r : Ranks) {
                const Card card(std::make_pair(s, r));
                m_deck.push_back(card);
            }

    Deck::ShuffleDeck();
}

// Random shuffle the cards in the deck
void Deck::ShuffleDeck() {
    // Randomly shuffle the deck.
    std::mt19937 g(std::random_device{}());
    std::shuffle(m_deck.begin(), m_deck.end(), g);
}

// When a deck is created, fill it.
Deck::Deck() {
    Deck::FillDeck();
}

// Print the deck details
void Deck::PrintDeckDetails() {
    std::cout << "Deck Size: " << m_deck.size() << "\n";

    for (auto const &d : m_deck)
        d.PrintCardDetails();
}

// Add 5 cards to hand and return a pointer to it.
Hand Deck::CreateHand() {
    std::vector<Card> hand;
    for (int i = 0; i < HAND_SIZE; ++i) {
        // Get a random card from the deck
        const Card card = GetRandomCardFromDeck();
        hand.push_back(card);
    }

    return hand;
}

// Selects a random card from this deck object.
Card Deck::GetRandomCardFromDeck() {
    // Randomize the elements and select whichever is in the front of the vector.
    auto GetRandom = [](auto vec) {
        std::vector<Card> out;
        std::sample(vec.begin(), vec.end(), std::back_inserter(out), 1, std::mt19937{std::random_device{}()});
        return out.front();
    };

    // Assign whatever random card we just got to a card object.
    Card card = GetRandom(m_deck);
    while (card.GetFlags() == CardFlags::FLAG_CARD_DRAWN)
        card = GetRandom(m_deck);

    card.SetFlags(CardFlags::FLAG_CARD_DRAWN);
    return card;
}

std::vector<int> Deck::GetHandAsInts(Hand const &hand) {
    std::vector<int> ranks;
    for (auto const c : hand)
        ranks.push_back(c.GetNumericalValueFromRank());

    return ranks;
}
