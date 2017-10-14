#include "Card.hpp"
#include "Deck.hpp"
#include "Probabilities.hpp"

#include <thread>
#include "Game.hpp"

static const int numThreads = 10;
static const int numDesiredOutcomes = 1;

// TODO MOVE TO SIMULATION CLASS
void RunSimulation()
{
	Probabilities::GetProbabilitiesOfHandConditions(HandRanks::FullHouse, numDesiredOutcomes);
}


int main()
{
	//Game::InitializeGame();
	RunSimulation();

	//std::unique_ptr<Deck> deck(new Deck());
	//deck->PrintDeckDetails();

	system("pause");
	return 0;
}
