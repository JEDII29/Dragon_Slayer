#include "Character.h"

Enemy::Enemy()
{
	Textr = new sf::Texture;
	Textr->loadFromFile("Rogue.png");
	Body.setTexture(*Textr);
	Body.setScale(3.0f, 3.0f);
	Body.setPosition(240.0f, 360.0f);
	MoveList.push_back(new PhysicalAttack("cios", 10));
	HoldingWeapon = new Weapon(5);
	LifePoints = 100;
	StaminaPoints = 100;
}