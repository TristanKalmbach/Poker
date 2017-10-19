#pragma once

#include "CardProperties.hpp"
#include "Card.hpp"
#include "HandEvaluator.hpp"


class Player
{
public:
	explicit Player(const Hand &hand)
	{
		m_hand = hand;
	}

	~Player()
	{
	}

	Hand GetHand() const { return m_hand; }

    void ReplaceCard(int index, Card replacementCard);

private:
	Hand m_hand;
};
