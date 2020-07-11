#pragma once
#include "Character.h"
class LaunchedAttack
{
public:
	bool CheckAttackCost(Player atacker, PhysicalAttack attack);
	bool CheckAttackCost(Enemy atacker, PhysicalAttack attack);
	void LaunchAttack(Player* atacker, Enemy* defender, PhysicalAttack attack);
	void LaunchAttack(Enemy* atacker, Player *defender, PhysicalAttack attack);
};

