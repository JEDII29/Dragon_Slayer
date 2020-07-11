#include "Attack.h"


PhysicalAttack::PhysicalAttack(std::string name, int attackPoints, int staminaCost)
{
	Name = name;
	AttackPoints = attackPoints;
	StaminaCost = staminaCost;
}
