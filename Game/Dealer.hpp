#pragma once

#include "Player.hpp"

class Dealer {
public:
    Dealer(std::vector<Card> hand) {
        hand = m_hand;
    }

    std::vector<Card> GetHand() const { return m_hand; }

private:
    std::vector<Card> m_hand;
};
