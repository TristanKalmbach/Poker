#include "Game/Utility/HandRankings.hpp"
#include "Game/Utility/Probabilities.hpp"
#include "Tests.hpp"


int main()
{
    std::unique_ptr<Deck> deck = std::make_unique<Deck>();
    auto hand = deck->CreateHand();
    const auto card = Card({ CardSuits::Spade, CardRank::Ace });

    Testing::Mechanics::Tests::TestCardReplacement(CardOne, card, hand);

	system("pause");
}
