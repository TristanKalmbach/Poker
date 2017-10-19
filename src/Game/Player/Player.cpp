#include "Player.hpp"

void Player::ReplaceCard(const int index, const Card replacementCard)
{
    if (index > m_hand.size())
        return;

    m_hand.at(index) = replacementCard;

    for (auto const &c : m_hand)
        c.PrintCardDetails();
}
