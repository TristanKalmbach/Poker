//
// Created by Tristan Kalmbach on 10/12/17.
//

#include "HandEvaluator.hpp"

bool HandEvaluator::HasFlush(Hand const &hand)
{
    auto const &cards = hand.GetCardsInHand();

    for (int i = 0; i < HAND_SIZE; ++i)
        if (cards[i].getSuit() != cards[0].getSuit())
            return false;

    return true;
}

bool HandEvaluator::HasRoyalFlush(Hand const &hand)
{
    auto const &cards = hand.GetCardsInHand();

    for (int i = 0; i < HAND_SIZE; ++i)
    {
        // Card must be royal
        if (cards[i].IsCardRoyal())
            return false;

        // Must be a flush
        if (!HandEvaluator::HasFlush(hand))
            return false;

        // Must be a straight
        if (!HandEvaluator::HasStraight(hand))
            return false;
    }

    return true;
}

bool HandEvaluator::HasStraight(Hand const &hand)
{
    auto const &cards = hand.GetCardsInHand();

    auto cardOne = cards[0];
    auto cardTwo = cards[1];
    auto cardThree = cards[2];
    auto cardFour = cards[3];
    auto cardFive = cards[4];

    return (cardOne.GetNumericalValueFromRank() + 1) == cardTwo.GetNumericalValueFromRank() &&
    (cardTwo.GetNumericalValueFromRank() + 1) == cardThree.GetNumericalValueFromRank() &&
    (cardThree.GetNumericalValueFromRank() + 1) == cardFour.GetNumericalValueFromRank() &&
    (cardFour.GetNumericalValueFromRank() + 1) == cardFive.GetNumericalValueFromRank();

}

bool HandEvaluator::HasPair(Hand const &hand)
{
    std::vector<CardRank> ranks;

    auto const &cards = hand.GetCardsInHand();
    for (auto const c : cards)
        ranks.push_back(c.getRank());

    auto it = std::adjacent_find(ranks.begin(), ranks.end());
    return it != ranks.end();
}
