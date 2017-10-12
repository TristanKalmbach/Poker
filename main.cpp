#include "Cards/Card.hpp"
#include "Cards/Deck.hpp"
#include "Testing/Probabilities.hpp"

#include <thread>
#include "Game/Game.hpp"

static const int numThreads = 10;
static const int numDesiredOutcomes = 1;

// TODO MOVE TO SIMULATION CLASS
void RunSimulation()
{
	Probabilities::GetProbabilitiesOfHandConditions(HandRanks::Straight, numDesiredOutcomes);
}


int main()
{
	Game::InitializeGame();

    system("pause");
    return 0;
}