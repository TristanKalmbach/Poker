#include "Game.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Dealer.hpp"

void Game::StartGame()
{
	bool isInitialized = false;
	if (!isInitialized)
	{
		// Initialize the deck. This will be the central deck used in the game by both players (or dealer)
		const auto deck = std::make_shared<Deck>();

		const auto &player = std::make_unique<Player>(deck->CreateHand());
		for (auto const& c : player->GetHand())
			c.PrintCardDetails();

		/*const auto &dealer = std::make_unique<Dealer>(deck->CreateHand());
		for (auto const& c : dealer->GetHand())
			c.PrintCardDetails();*/
		
	}
}
