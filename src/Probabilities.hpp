//
// Created by Tristan Kalmbach on 10/11/17.
//

#pragma once

#include "Deck.hpp"
#include "HandEvaluator.hpp"
#include "HandRankings.hpp"

#include <chrono>

namespace Testing
{
    class Probabilities
    {
    public:

        static void GetProbabilitiesOfHandConditions(const HandRanks handRanks, const int desiredFavorableOutcomes)
        {
            // Create a deck and hand
            const auto deck = std::make_shared<Deck>();
            std::vector<Card> cards;

            int numRuns = 0;
            int outcomes = 0;

            // Start time benchmark
            const auto begin = std::chrono::steady_clock::now();

            while (outcomes < desiredFavorableOutcomes)
            {
                const auto hand = deck->CreateHand();
                cards = hand;

                switch (handRanks)
                {
                    case HandRanks::Pair:
                    {
                        if (HandEvaluator::HasPair(hand))
                            ++outcomes;
                    }
                    break;
                    case HandRanks::Flush:
                    {
                        if (HandEvaluator::HasFlush(hand))
                            ++outcomes;
                    }
                    break;
                    case HandRanks::Straight:
                    {
                        if (HandEvaluator::HasStraight(hand))
                            ++outcomes;
                    }
                    break;
                    case HandRanks::StraightFlush:
                    {
                        if (HandEvaluator::HasStraightFlush(hand))
                            ++outcomes;
                    }
                    break;
                    case HandRanks::RoyalFlush:
                    {
                        if (HandEvaluator::HasRoyalFlush(hand))
                            ++outcomes;
                    }
                    break;
                    case HandRanks::ThreeOfAKind:
                    {
                        if (HandEvaluator::HasThreeOfKind(hand))
                            ++outcomes;
                    }
                    break;
                    case HandRanks::FourOfAKind:
                    {
                        if (HandEvaluator::HasFourOfKind(hand))
                            ++outcomes;
                    }
                    break;
                    case HandRanks::FullHouse:
                    {
                        if (HandEvaluator::HasFullHouse(hand))
                            ++outcomes;
                    }
                    break;
                    case HandRanks::AllRoyal:
                    {
                        if (HandEvaluator::IsEveryCardRoyal(hand))
                            ++outcomes;
                    }
                    break;
                    case HandRanks::TwoPair:
                    {
                        if (HandEvaluator::HasTwoPair(hand))
                            ++outcomes;
                    }
                    break;
                    default:
                        break;
                }

                ++numRuns;
            }

            // End time benchmark and print results
            const auto end = std::chrono::steady_clock::now();
            PrintTestResults(numRuns, outcomes, cards, begin, end);
        }

        static void PrintTestResults(const int numRuns, const int favorableOutcomes, std::vector<Card> cards,
                                     const std::chrono::steady_clock::time_point begin,
                                     const std::chrono::steady_clock::time_point end)
        {
            const auto timeElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

            std::cout << "Check ran: " << numRuns << " times." << '\n';
            std::cout << "Number of favorable outcomes: " << favorableOutcomes << '\n';
            std::cout << "\nTime elapsed: " << timeElapsed << " ms. " << '\n';
            std::cout << "\nHand Value: " << HandEvaluator::GetHandRankValue(cards) << '\n';
            std::cout << "\nCards drawn were: " << '\n';
            for (auto const &c : cards)
                c.PrintCardDetails();
        }
    };
}
