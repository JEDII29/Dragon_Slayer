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
	sf::Sprite FightBody;
	sf::Texture* Textr;
	sf::Texture* FightTextr;
	int LifePoints;
	int StaminaPoints;
protected:
	int Lvl;
};

class Player : public Character
{
public:
	int Maxhealth, MaxStamina;
	Direction Drt;
	bool Checked;
	int Exp;
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
	void RaiseLvl();
	int GetLvl() { return Lvl; };
private:

	float Speed;
};

class Enemy : public Character
{
public:
	std::vector<PhysicalAttack*> MoveList;
	Weapon* HoldingWeapon;
	Enemy();
	Enemy(int difficulty);
};
