#include "Card.hpp"
#include "Deck.hpp"
#include "Probabilities.hpp"

#include <thread>
#include "Game.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
	// Create the game window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Five Card Draw - Poker", sf::Style::Default);
	window.setFramerateLimit(60);

	// Keep window open until the clsoe event is invoked.
	while (window.isOpen())
	{
		// Check events for closing event
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close the window on request
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Clear to black color
		window.clear(sf::Color::Black);

		// End current frame
		window.display();
	}

	return 0;
}
