#include "Game.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Dealer.hpp"

void Game::InitializeGame()
{
	bool isInitialized = false;
	if (!isInitialized)
	{
		// Initialize the deck. This will be the central deck used in the game by both players (or dealer)
		std::shared_ptr<Deck> l_Deck(new Deck());

		const std::unique_ptr<Player> player(new Player(l_Deck->CreateHand()));
		for (auto const& c : player->GetHand())
			c.PrintCardDetails();

		const std::unique_ptr<Dealer> dealer(new Dealer(l_Deck->CreateHand()));
		for (auto const& c : dealer->GetHand())
			c.PrintCardDetails();

		// Set game to initialized so this method never happens again
		isInitialized = true;

		// Start game loop for mechanics
		GameLoop();
	}
}

void Game::GameLoop()
{
	bool isGameComplete = false;
	while (!isGameComplete)
	{
	}
}
