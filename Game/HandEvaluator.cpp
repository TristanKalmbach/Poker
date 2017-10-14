//
// Created by Tristan Kalmbach on 10/12/17.
//

#include "HandEvaluator.hpp"

bool HandEvaluator::HasFlush(Hand const &hand) {
    // Create a vector for easy access
    for (int i = 0; i < HAND_SIZE; ++i) {
        if (hand[i].getSuit() != hand[0].getSuit())
            return false;
    }

    return true;
}

bool HandEvaluator::HasRoyalFlush(Hand const &hand) {
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

bool HandEvaluator::HasStraight(Hand const &hand) {
    // Check cards
    std::vector<int> ranks = Deck::GetHandAsInts(hand);
    auto it = ranks.begin();

}

bool HandEvaluator::HasPair(Hand const &hand) {
    std::vector<int> ranks = Deck::GetHandAsInts(hand);

    // Sort so adjacent_find will find it faster.
    std::sort(ranks.begin(), ranks.end());

    const auto it = repetition_find(ranks.begin(), ranks.end(), 2);
    return it != ranks.end();
}

bool HandEvaluator::HasThreeOfKind(Hand const &hand) {
    std::vector<int> ranks = Deck::GetHandAsInts(hand);

    // Sort so adjacent_find will find it faster.
    std::sort(ranks.begin(), ranks.end());

    const auto it = repetition_find(ranks.begin(), ranks.end(), 3);
    return it != ranks.end();
}

bool HandEvaluator::HasFourOfKind(Hand const &hand) {
    std::vector<int> ranks = Deck::GetHandAsInts(hand);

    // Sort so adjacent_find will find it faster.
    std::sort(ranks.begin(), ranks.end());

    const auto it = repetition_find(ranks.begin(), ranks.end(), 4);
    return it != ranks.end();
}

bool HandEvaluator::HasTwoPair(Hand const &hand) {
    if (!HasPair(hand))
        return false;

    // We've gotten here meaning there is already a pair.
    // So, if we have a sorted vector and the adjacent_find found a pair,
    // We'll find the next pair if it exists.

    return false;
}

bool HandEvaluator::HasStraightFlush(Hand const &hand) {
    return HasFlush(hand) && HasStraight(hand);
}

bool HandEvaluator::IsEveryCardRoyal(Hand const &hand) {
    //return std::none_of(hand.begin(), hand.cend(), [&](){
    //    for (auto const &c : hand)
    //
    // });
}

int HandEvaluator::GetHandRankValue(Hand const &hand) {
    int value = 0;

    // Get the value of all of the cards
    for (auto const &c : hand)
        value += c.GetCardRankValue();

    // TODO: Evaluate hand ranks to increase hand value

    return value;
}

// TODO: IMPLEMENT THIS WITH STL ALGORITHM PREFERABLY
bool HandEvaluator::HasFullHouse(Hand const &hand) {
    return HasThreeOfKind(hand) && HasPair(hand);
}
