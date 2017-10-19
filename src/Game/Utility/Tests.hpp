#pragma once
#include "HandEvaluator.hpp"

class Card;

namespace Testing::Mechanics
{
    class Tests
    {
    public:

        static void TestCardReplacement(const int index, const Card replacementCard, Hand &hand)
        {
            std::cout << "Before: " << '\n';
            for (auto const &c : hand)
                c.PrintCardDetails();

            // Set value of the index to the new card
            hand.at(index) = replacementCard;

            std::cout << "\n\nAfter: " << '\n';
            for (auto const &cr : hand)
                cr.PrintCardDetails();
        }

    private:


    };
}
