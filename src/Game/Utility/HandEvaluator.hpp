//
// Created by Tristan Kalmbach on 10/12/17.
//

#pragma once

#include "Deck.hpp"
#include <numeric>

class HandEvaluator
{
public:
	static bool HasFlush(Hand const& hand);
	static bool HasRoyalFlush(Hand const& hand);
	static bool HasStraight(Hand const& hand);
	static bool HasPair(Hand const& hand);
	static bool HasThreeOfKind(Hand const& hand);
	static bool HasTwoPair(Hand const& hand);
	static bool HasFourOfKind(Hand const& hand);
	static bool HasStraightFlush(Hand const& hand);
	static bool HasFullHouse(Hand const& hand);
	static bool IsEveryCardRoyal(Hand const& hand);
	static int GetHandRankValue(Hand const& hand);

	// Taken from stackoverflow
	// https://stackoverflow.com/questions/26982371/find-multiple-adjacent-values-in-container
	template <class InputIt>
    static InputIt repetition_find(InputIt first, InputIt last, size_t repetitions);

private:
	HandEvaluator() { }
	~HandEvaluator() { }
};
