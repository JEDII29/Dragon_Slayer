#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

enum Direction {up, down, left, right};

class Character
{
public:
	sf::Sprite Body;
	sf::Texture Textr;
	Direction Drt;
};

class Player : public Character
{
public:
	Player();
	void Walk(Direction _drt, const sf::Time& _elapsed);
};
