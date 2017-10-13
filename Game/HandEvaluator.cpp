//
// Created by Tristan Kalmbach on 10/12/17.
//

#include "HandEvaluator.hpp"

bool HandEvaluator::HasFlush(Hand const &hand)
{
	// Create a vector for easy access
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		if (hand[i].getSuit() != hand[0].getSuit())
			return false;
	}

    return true;
}

bool HandEvaluator::HasRoyalFlush(Hand const &hand)
{
	// Every card needs to be royal
	if (!HandEvaluator::IsEveryCardRoyal(hand))
		return false;

    // Must be a flush
    if (!HandEvaluator::HasFlush(hand))
        return false;

    // Must be a straight
    if (!HandEvaluator::HasStraight(hand))
        return false;

    return true;
}

bool HandEvaluator::HasStraight(Hand const &hand)
{
	// Check cards
	auto cardOne = hand[0];
	auto cardTwo = hand[1];
	auto cardThree = hand[2];
	auto cardFour = hand[3];
	auto cardFive = hand[4];

	return (cardOne.GetNumericalValueFromRank() + 1) == cardTwo.GetNumericalValueFromRank() &&
		(cardTwo.GetNumericalValueFromRank() + 1) == cardThree.GetNumericalValueFromRank() &&
		(cardThree.GetNumericalValueFromRank() + 1) == cardFour.GetNumericalValueFromRank() &&
		(cardFour.GetNumericalValueFromRank() + 1) == cardFive.GetNumericalValueFromRank();
}

bool HandEvaluator::HasPair(Hand const &hand)
{
    std::vector<CardRank> ranks;
    for (auto const c : hand)
        ranks.push_back(c.getRank());

	const auto it = std::adjacent_find(ranks.begin(), ranks.end());
    return it != ranks.end();
}

bool HandEvaluator::HasStraightFlush(Hand const& hand)
{
	return HasFlush(hand) && HasStraight(hand);
}

bool HandEvaluator::IsEveryCardRoyal(Hand const& hand)
{
	std::size_t numRoyal = 0;
	for (auto const &c : hand)
	{
		if (c.IsCardRoyal())
			++numRoyal;
	}
	
	return numRoyal == 5;
}

int HandEvaluator::GetHandRankValue(Hand const& hand)
{
	int value = 0;

	// Get the value of all of the cards
	for (auto const &c : hand)
		value += c.GetCardRankValue();

	// TODO: Evaluate hand ranks to increase hand value

	return value;
}
