#pragma once
#include <iostream>
class Attack
{
public:
	std::string Name;
	int AttackPoints;
	//virtual void MakeMove() = 0;

};

class PhysicalAttack : public Attack
{
public:

	PhysicalAttack(std::string name, int attackPoints);
};

class Spell
{
};

