//
// Created by Tristan Kalmbach on 10/11/17.
//

#pragma once

#include "../Cards/Deck.hpp"
#include "../Game/HandEvaluator.hpp"
#include "../Game/HandRankings.hpp"

class Probabilities
{
public:

    void GetProbabilitiesOfHandConditions(HandRanks handRanks)
    {
        switch (handRanks)
        {
            case HandRanks::Pair:
            {
                // Create a deck and hand
                std::unique_ptr<Deck> deck(new Deck());
                std::vector<Card> cards;
                std::size_t numRuns;
                bool pair = false;
                while (!pair)
                {
                    auto hand = deck->CreateHand();
                    cards = hand->GetCardsInHand();

                    if (HandEvaluator::HasPair(*hand))
                        pair = true;

                    ++numRuns;
                }

                std::cout << "Check ran " << numRuns << " times. Cards were: " << '\n';
                for (auto const &c : cards)
                    c.PrintCardDetails();
            }
            break;
            case HandRanks::Flush:
            {
                // Create a deck and hand
                std::unique_ptr<Deck> deck(new Deck());
                std::vector<Card> cards;
                std::size_t numRuns;
                bool flush = false;
                while (!flush)
                {
                    auto const &hand = deck->CreateHand();
                    cards = hand->GetCardsInHand();

                    if (HandEvaluator::HasFlush(*hand))
                        flush = true;

                    ++numRuns;
                }

                std::cout << "Check ran " << numRuns << " times. Cards were: " << '\n';
                for (auto const &c : cards)
                    c.PrintCardDetails();
            }
            break;
            case HandRanks::Straight:
            {
                // Create a deck and hand
                std::unique_ptr<Deck> deck(new Deck());
                std::vector<Card> cards;
                std::size_t numRuns;
                bool straight = false;
                while (!straight)
                {
                    auto const &hand = deck->CreateHand();
                    cards = hand->GetCardsInHand();

                    if (HandEvaluator::HasStraight(*hand))
                        straight = true;

                    ++numRuns;
                }

                std::cout << "Check ran " << numRuns << " times. Cards were: " << '\n';
                for (auto const &c : cards)
                    c.PrintCardDetails();
            }
            break;
        }
    }
};