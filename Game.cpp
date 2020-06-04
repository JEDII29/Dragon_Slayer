#include "Game.h"

Game::Game()
{
	Window = new sf::RenderWindow(sf::VideoMode(1200, 720), "Dragon Slayer");
	Hero = new Player;
	LoadAllData();
	CurrentLocation = new Map("testingLocation.txt", TexturesMap);
	Screen = new sf::View(sf::Vector2f(0.0f,0.0f), sf::Vector2f(1200.0f, 720.0f));
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
	
	for (int i = Hero->PositionIndeks.x-1; i <= Hero->PositionIndeks.x + 1; i++)
	{
		for (int j = Hero->PositionIndeks.y - 1; j <= Hero->PositionIndeks.y + 1; j++)
		{
			if (CurrentLocation->Location[j][i].IsWall)
				Hero->Stop(Hero->CheckCollision(CurrentLocation->Location[j][i].getPosition()));
		}
	}

}


void Game::Render()
{
	Screen->setCenter(Hero->Body.getPosition());
	Window->clear(sf::Color::Black);
	Window->setView(*Screen);

	for (int i = 0; i < CurrentLocation->Location.size(); i++)
	{
		for (int j = 0; j < CurrentLocation->Location[i].size(); j++)
		{
			Window->draw(CurrentLocation->Location[i][j]);
		}
	}

	Window->draw(Hero->Body);

	// end the current frame
	Window->display();
}
