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
	MoveList.push_back(new PhysicalAttack("cios", 10, 5));
	MoveList.push_back(new PhysicalAttack("wpierdol", 20, 10 ));
	HoldingWeapon = new Weapon(1);
	LifePoints = 100;
	StaminaPoints = 100;
}

Enemy::Enemy(int difficulty)
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
	MoveList.push_back(new PhysicalAttack("pac", 1, 0));
	switch (difficulty)
	{
	case 4:
	{
		MoveList.push_back(new PhysicalAttack("wpierdol", 20, 30));
	}
	case 3:
	{
		MoveList.push_back(new PhysicalAttack("cios", 10, 20));
	}
	case 2:
	{
		MoveList.push_back(new PhysicalAttack("punch", 15, 20));
	}
	case 1:
	{
		MoveList.push_back(new PhysicalAttack("szturch", 5, 5));
		break;
	}
	default:
	{
	}
	}


	HoldingWeapon = new Weapon(5);
	LifePoints = difficulty*50;
	StaminaPoints = 100;
}
