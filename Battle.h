#pragma once
#include "Character.h"
class Battle
{
public:
	Battle();
	Battle(Player* hero, Enemy* opponent);
	void Update(sf::RenderWindow* window, sf::Event evnt);
	void Render(sf::RenderWindow* window);
	sf::Texture* Background;
	Enemy* Opponent;

private:
	Player* Hero;

};

