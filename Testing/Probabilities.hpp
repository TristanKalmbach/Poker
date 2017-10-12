//
// Created by Tristan Kalmbach on 10/11/17.
//

#pragma once

#include "../Cards/Deck.hpp"
#include "../Game/HandEvaluator.hpp"

class Probabilities
{
public:

    void GetProbabilitiesOfHandConditions()
    {
        // First, we'll need to create a deck
        std::unique_ptr<Deck> deck(new Deck());

        // Now, we'll need to create hands until we get a royal flush
        size_t numRuns = 0;
        bool isRoyalFlush = false;

        std::vector<Card> cards;

        // Loop until royal flush
        while (!isRoyalFlush)
        {
            // Create the hand
            if (auto const &hand = deck->CreateHand())
                if (HandEvaluator::IsRoyalFlush(*hand))
                {
                    isRoyalFlush = true;
                    cards = hand->GetCardsInHand();
                }

            ++numRuns;
        }

        std::cout << "Simulation ran " << numRuns << " times. Cards were: " << "\n";
        for (auto const &c : cards)
            c.PrintCardDetails();

    }

private:
};