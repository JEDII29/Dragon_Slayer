#pragma once
#include <SFML\Graphics.hpp>
#include <SFML/Window.hpp>
class StatsBadge
{
public:
	StatsBadge();
	void Update(int lifePoints, int staminaPoints, int maxLife, int maxStamina, int lvl, int _exp, sf::Vector2f view);
	void Render(sf::RenderWindow* window);

private:
	//int LifePoints, StaminaPoints, MaxLife, MaxStamina, Lvl, Exp;
	sf::RectangleShape Back;
	sf::Text text[4];
	sf::Font font;
};

