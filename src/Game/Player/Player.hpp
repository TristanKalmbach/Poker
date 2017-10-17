#pragma once

#include "CardProperties.hpp"
#include "Card.hpp"


class Player
{
public:
	explicit Player(const std::vector<Card> hand)
	{
		m_hand = hand;
	}

	~Player()
	{
	}

	std::vector<Card> GetHand() const { return m_hand; }

private:
	std::vector<Card> m_hand;
};
