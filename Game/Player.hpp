#pragma once

#include "../Cards/CardProperties.hpp"
#include "../Cards/Card.hpp"


class Player
{
public:
	explicit Player(const std::list<Card> hand)
	{
		m_hand = hand;
	}

	~Player() { }

	std::list<Card> GetHand() { return m_hand; }
	
private:
	std::list<Card> m_hand;
};
