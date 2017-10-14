//
// Created by Tristan Kalmbach on 10/12/17.
//

#include "HandEvaluator.hpp"
#include <boost/algorithm/algorithm.hpp>

bool HandEvaluator::HasFlush(Hand const& hand)
{
	// Create a vector for easy access
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		if (hand[i].getSuit() != hand[0].getSuit())
			return false;
	}

	return true;
}

bool HandEvaluator::HasRoyalFlush(Hand const& hand)
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

bool HandEvaluator::HasStraight(Hand const& hand)
{
	// Get the hand as integer values
	std::vector<int> ranks = Deck::GetHandAsInts(hand);
	
	// Create an empty vector of the same size
	std::vector<int> copy(5);

	// Fill the copy vector with incrementing elements based on the starting element of ranks after sorting
	std::sort(ranks.begin(), ranks.end());

	// Assuming, hypothetically, rank[0] is 5, then we'll increment the starting value by 1 for each reserved element in the new copy vector
	std::iota(copy.begin(), copy.end(), ranks[0]);

	// In the end, if the vectors are the same, you've got a straight. 
	return ranks == copy;
}

bool HandEvaluator::HasPair(Hand const& hand)
{
	std::vector<int> ranks = Deck::GetHandAsInts(hand);

	// Sort so adjacent_find will find it faster.
	std::sort(ranks.begin(), ranks.end());

	const auto it = repetition_find(ranks.begin(), ranks.end(), 2);
	return it != ranks.end();
}

bool HandEvaluator::HasThreeOfKind(Hand const& hand)
{
	std::vector<int> ranks = Deck::GetHandAsInts(hand);

	// Sort so adjacent_find will find it faster.
	std::sort(ranks.begin(), ranks.end());

	const auto it = repetition_find(ranks.begin(), ranks.end(), 3);
	return it != ranks.end();
}

bool HandEvaluator::HasFourOfKind(Hand const& hand)
{
	std::vector<int> ranks = Deck::GetHandAsInts(hand);

	// Sort so adjacent_find will find it faster.
	std::sort(ranks.begin(), ranks.end());

	const auto it = repetition_find(ranks.begin(), ranks.end(), 4);
	return it != ranks.end();
}

bool HandEvaluator::HasTwoPair(Hand const& hand)
{
	if (!HasPair(hand))
		return false;

	// We've gotten here meaning there is already a pair.
	// So, if we have a sorted vector and the adjacent_find found a pair,
	// We'll find the next pair if it exists.

	return false;
}

bool HandEvaluator::HasStraightFlush(Hand const& hand)
{
	return HasFlush(hand) && HasStraight(hand);
}

// O(N)
bool HandEvaluator::IsEveryCardRoyal(Hand const& hand)
{
	std::vector<int> ranks = Deck::GetHandAsInts(hand);

	return boost::algorithm::all_of(ranks.begin(), ranks.end(), [](int r)
                                {
	                                return r >= 10;
                                });
}

int HandEvaluator::GetHandRankValue(Hand const& hand)
{
	int value = 0;

	// Get the value of all of the cards
	for (auto const& c : hand)
		value += c.GetCardRankValue();

	// TODO: Evaluate hand ranks to increase hand value

	return value;
}

bool HandEvaluator::HasFullHouse(Hand const& hand)
{
	// Find three repeating elements and then two separate repeating elements that do not equal the first three. 
	// Order does not matter so sort is unnecessary, BUT we'll do it for simplicitys sake.
	std::vector<int> ranks = Deck::GetHandAsInts(hand);

	// Sort. In theory now we'll have xxyyy || xxxyy in terms of pair/triple
	std::sort(ranks.begin(), ranks.end());

	// Find a pair
	const auto it = HandEvaluator::repetition_find(ranks.begin(), ranks.end(), 2);

	// Find a triple
	const auto it2 = HandEvaluator::repetition_find(ranks.begin(), ranks.end(), 3);

	// If the value of the iterators are NOT equal, yet they're found, then we have a xxyyy/xxxyy situation.
	return (it != it2) && (it != ranks.end() && it2 != ranks.end());
}
