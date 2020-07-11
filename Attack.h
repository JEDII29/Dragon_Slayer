#pragma once
#include <iostream>
class Attack
{
public:
	std::string Name;
	int AttackPoints;
	int StaminaCost;
	//virtual void MakeMove() = 0;

};

class PhysicalAttack : public Attack
{
public: 
	PhysicalAttack(std::string name, int attackPoints, int staminaCost);
};

class Spell
{
};

