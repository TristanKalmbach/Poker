//
// Created by Tristan Kalmbach on 10/11/17.
//

#pragma once

#include "Card.hpp"

#define HAND_SIZE 5

class Hand
{
public:
    ~Hand() { m_hand.clear(); }

    void AddCardToHand(Card card);

    // For outside use
    std::vector<Card> GetCardsInHand() const { return m_hand; }

private:
    std::vector<Card> m_hand;
};