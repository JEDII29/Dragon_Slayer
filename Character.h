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
	bool IsMoving;
	PlayerAnimation* Animation;
	sf::Vector2i Movement;
	sf::Vector2f StartPosition;
	Player();
	void Update(const float&);
	void Walk(Direction _drt, const float& _elapsed);
private:
	float Speed;
};
