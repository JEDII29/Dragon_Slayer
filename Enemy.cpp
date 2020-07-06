#include "Character.h"

Enemy::Enemy()
{
	Textr = new sf::Texture;
	FightTextr = new sf::Texture;
	Textr->loadFromFile("Rogue.png");
	FightTextr->loadFromFile("EnemyStance.png");
	Body.setTexture(*Textr);
	Body.setScale(3.0f, 3.0f);
	Body.setPosition(240.0f, 360.0f);
	FightBody.setTexture(*FightTextr);
	FightBody.setScale(2.0f, 2.0f);
	FightBody.setPosition(900.0f, 400.0f);
	MoveList.push_back(new PhysicalAttack("cios", 10));
	HoldingWeapon = new Weapon(5);
	LifePoints = 100;
	StaminaPoints = 100;
}