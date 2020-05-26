#include "Game.h"

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(1000, 600), "Dragon Slayer");
	hero = new Player;
}

void Game::loadAllData()
{

}

void Game::run()
{
	while (window->isOpen())
	{
		while (window->pollEvent(evnt))
		{
			// "close requested" event: we close the window
			if (evnt.type == sf::Event::Closed)
			{
				window->close();
			}

			// clear the window with black color
			window->clear(sf::Color::Black);

			window->draw(hero->body);

			// end the current frame
			window->display();
		}
	}
}
