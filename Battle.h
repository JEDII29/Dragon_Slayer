#pragma once
#include "Character.h"
#include "table.h"

class Battle
{
public:
	Battle();
	Battle(Player* hero);
	Battle(Player* hero, Enemy* opponent);

	void Run(sf::RenderWindow* window, sf::Event evnt);
	sf::Texture* Background;
	Enemy* Opponent;

private:
	Player* Hero;
	sf::View Screen;
	sf::RectangleShape Field[2];
	sf::RectangleShape Rectangle;
	Table* Action;
	//Table* MoveSet;

	void Update(sf::RenderWindow* window, sf::Event evnt);
	void Render(sf::RenderWindow* window);
};

