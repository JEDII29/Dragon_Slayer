#include "Game.h"

Game::Game()
{
	Window = new sf::RenderWindow(sf::VideoMode(1200, 720), "Dragon Slayer");
	Hero = new Player;
	LoadAllData();
	CurrentLocation = new Map("testingLocation.txt", TexturesMap);
}

void Game::LoadTextures()
{
	sf::Texture* txtr = new sf::Texture;
	txtr->loadFromFile("Grass.png");
	TexturesMap['a'] = txtr;
	txtr = new sf::Texture;
	txtr->loadFromFile("WallRock.png");
	TexturesMap['b'] = txtr;

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
	Window->setFramerateLimit(60);
	Elapsed = Clk.restart();
	float elapsed = Elapsed.asSeconds();
	while (Window->pollEvent(Evnt))
	{
		// "close requested" event: we close the window
		if (Evnt.type == sf::Event::Closed)
		{
			Window->close();
		}
	}

	Hero->Update(elapsed);


	 Hero->Animation->Update(Hero->Drt, elapsed, Hero->IsMoving);
	 Hero->Body.setTextureRect(Hero->Animation->UvRect);


}

void Game::Render()
{
	Window->clear(sf::Color::Black);

	for (int i = 0; i < CurrentLocation->SpritesMap.size(); i++)
	{
		for (int j = 0; j < CurrentLocation->SpritesMap[i].size(); j++)
		{
			Window->draw(CurrentLocation->SpritesMap[i][j]);
		}
	}

	Window->draw(Hero->Body);

	// end the current frame
	Window->display();
}
