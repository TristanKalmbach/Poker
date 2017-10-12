#include "Game.hpp"
#include "../Cards/Deck.hpp"
#include "../Game/Player.hpp"

Game::Game()
{
}

void Game::InitializeGame()
{
	bool isInitialized = false;
	if (!isInitialized)
	{
		// Initialize the deck. This will be the central deck used in the game by both players (or dealer)
		std::shared_ptr<Deck> l_Deck(new Deck());

		// Administer hands to the players and dealers
		auto const &playerHand = l_Deck->CreateHand();
		auto dealerHand = l_Deck->CreateHand();

		const std::unique_ptr<Player> player(new Player(playerHand));
		for (auto const &c : player->GetHand())
			c.PrintCardDetails();

		// Start game loop for mechanics

		// Set game to initialized so this method never happens again
		isInitialized = true;
	}
}
