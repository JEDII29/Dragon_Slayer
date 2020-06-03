#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "PlayerAnimation.h" 

enum Direction {down, right, up, left};

class Character
{
public:
	sf::Sprite Body;
	sf::Texture* Textr;
	Direction Drt;
};

class Player : public Character
{
public:
	PlayerAnimation* Animation;
	Player();
	void Walk(Direction _drt, const sf::Time& _elapsed);
private:
	float Speed;
};
