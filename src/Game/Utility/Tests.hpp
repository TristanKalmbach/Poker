#pragma once
#include "HandEvaluator.hpp"

class Card;

namespace Testing::Mechanics
{
    enum class MechanicTests : std::uint8_t
    {
        TestCardReplacement,
        TestReplaceAllCards,
        TestGetHighCard
    };

    class Tests
    {
    public:
        static void RunTest(const MechanicTests test)
        {
            std::unique_ptr<Deck> deck = std::make_unique<Deck>();
            auto hand = deck->CreateHand();
            auto handAsInts = deck->GetHandAsInts(hand);
            const auto card = deck->GetRandomCardFromDeck();

            std::cout << "Before: " << '\n';
            for (auto const &c : hand)
                c.PrintCardDetails();

            switch (test)
            {
                case MechanicTests::TestCardReplacement:
                    TestCardReplacement(CardOne, card, hand);
                    break;
                case MechanicTests::TestReplaceAllCards:
                    TestReplaceAll(hand, *deck);
                    break;
                default: ;
            }

            std::cout << "After: " << '\n';
            for (auto const &c : hand)
                c.PrintCardDetails();
        }


        static void TestCardReplacement(const int index, const Card replacementCard, Hand &hand)
        {
            hand.at(index) = replacementCard;
        }

        static void TestReplaceAll(Hand &hand, Deck deck)
        {
            for (int i = 0; i < hand.size(); ++i)
                hand.at(i) = deck.GetRandomCardFromDeck();
        }

    private:


    };
}
