#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "PlayerAnimation.h" 
#include "Item.h"
#include "Attack.h"

enum Direction {down, right, up, left};

class Character
{
public:
	sf::Sprite Body;
	sf::Texture* Textr;
	int LifePoints;
	int StaminaPoints;
};

class Player : public Character
{
public:
	Direction Drt;
	Weapon* HoldingWeapon;
	std::vector<PhysicalAttack*> MoveList;

	PlayerAnimation* Animation;
	sf::Vector2i PositionIndeks;
	bool IsMoving;
	sf::Vector2i Movement;
	Player();
	void Update(const float&);
	void Walk(Direction _drt, const float& _elapsed);
	void Stop(bool isCollision);
	bool CheckCollision(const sf::Vector2f& objectPosition);
private:
	float Speed;
};

class Enemy : public Character
{
public:
	std::vector<PhysicalAttack*> MoveList;
	Weapon* HoldingWeapon;
	Enemy();
};
