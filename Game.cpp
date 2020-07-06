#include "Game.h"
#include "Battle.h"

Game::Game()
{
	Window = new sf::RenderWindow(sf::VideoMode(1200, 720), "Dragon Slayer");
	Hero = new Player;
	EnemysList.push_back(new Enemy());
	LoadAllData();
	CurrentLocation = new Map("testingLocation.txt", TexturesMap, Grass);
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
	txtr = new sf::Texture;
	txtr->loadFromFile("TallGrassUp.png");
	TexturesMap['g'] = txtr;
	txtr = new sf::Texture;
	txtr->loadFromFile("TallGrassDown.png");
	TexturesMap['h'] = txtr;
	

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

	Hero->Update(elapsed);

	

	for (int i = Hero->PositionIndeks.x-1; i <= Hero->PositionIndeks.x + 1; i++)
	{
		for (int j = Hero->PositionIndeks.y - 1; j <= Hero->PositionIndeks.y + 1; j++)
		{
			if (CurrentLocation->Location[j][i].IsWall)
				Hero->Stop(Collisions.CheckHeroCollisionWithWalls(Hero, CurrentLocation->Location[j][i]));
		}
	}
	if (CurrentLocation->Location[Hero->PositionIndeks.y][Hero->PositionIndeks.x].CanSpawn
		&& Hero->Checked == false)
	{
		if (Collisions.CheckHeroCollisionWithGrass(Hero, CurrentLocation->
			Location[Hero->PositionIndeks.y][Hero->PositionIndeks.x]))
		{
			Battle* Fight = new Battle(Hero);
			while (Fight != NULL)
			{
				Fight->Run(Window, Evnt);		
				if (Fight->Opponent->LifePoints <= 0)
				{
					break;
				}
			}
			delete Fight;
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

	for (int i = 0; i < EnemysList.size(); i++)
	{
		Window->draw(EnemysList[i]->Body);
	}

	Window->draw(Hero->Body);

	for (int i = 0; i < Grass.size(); i++)
	{
		Window->draw(*Grass[i]);
	}

	// end the current frame
	Window->display();
}

void Game::PollEvnt()
{
	// "close requested" event: we close the window
	while (Window->pollEvent(Evnt))
	{
		if (Evnt.type == sf::Event::Closed || Evnt.key.code == sf::Keyboard::Escape)
		{
			this->Window->close();
		}
	}
}
