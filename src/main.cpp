#include "Card.hpp"
#include "Deck.hpp"
#include "Probabilities.hpp"

#include <thread>
#include "Game.hpp"

int main()
{
	Testing::Probabilities::GetProbabilitiesOfHandConditions(HandRanks::FullHouse, 1);

	system("pause");
	return 0;
}
