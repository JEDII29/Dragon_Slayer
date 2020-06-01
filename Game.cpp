#include "Game.h"

Game::Game()
{
	Window = new sf::RenderWindow(sf::VideoMode(1000, 600), "Dragon Slayer");
	Hero = new Player;
}

void Game::LoadTextures()
{

}


void Game::LoadAllData()
{
	LoadTextures();
}

bool Game::Run()
{
	return Window->isOpen();
}

void Game::Update()
{
	Window->setFramerateLimit(30);
	Elapsed = Clk.restart();

	while (Window->pollEvent(Evnt))
	{
		// "close requested" event: we close the window
		if (Evnt.type == sf::Event::Closed)
		{
			Window->close();
		}
	}

	 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		Hero->Walk(right, Elapsed);

	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		Hero->Walk(left, Elapsed);

	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		Hero->Walk(down, Elapsed);

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		Hero->Walk(up, Elapsed);


}

void Game::Render()
{
	Window->clear(sf::Color::Black);


	Window->draw(Hero->Body);

	// end the current frame
	Window->display();
}
