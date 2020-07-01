#include "Battle.h"


Battle::Battle()
{
}

Battle::Battle(Player* hero, Enemy* opponent)
{
	Hero = hero;
	Opponent = opponent;
	Background->loadFromFile("Grass.png");
}

void Battle::Update(sf::RenderWindow* window, sf:: Event evnt)
{
	Opponent->LifePoints = 100;
	while (window->pollEvent(evnt))
	{
		if (evnt.type == sf::Event::Closed)
		{
			window->close();
		}
		if (evnt.key.code == sf::Keyboard::Q)
		{
			Opponent->LifePoints = 0;
		}
	}
}

void Battle::Render(sf::RenderWindow* window)
{
	window->clear();

	window->display();
}


