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
	Direction Drt;
};

class Player : public Character
{
public:
	Weapon HoldingWeapon;
	int LifePoints;
	int StaminaPoints;
	std::vector<PhysicalAttack> MoveList;

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

class Enemy
{

};
