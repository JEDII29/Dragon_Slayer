#include "LaunchedAttack.h"

bool LaunchedAttack::CheckAttackCost(Player atacker, PhysicalAttack attack)
{
	return atacker.StaminaPoints >= attack.StaminaCost;
}

bool LaunchedAttack::CheckAttackCost(Enemy atacker, PhysicalAttack attack)
{
	return atacker.StaminaPoints >= attack.StaminaCost;
}

void LaunchedAttack::LaunchAttack(Player* atacker, Enemy* defender, PhysicalAttack attack)
{
	int damage = attack.AttackPoints;
	damage = damage * atacker->HoldingWeapon->Damage;
	damage = 0.7f * damage + rand() % (int)(damage * 0.6);
	atacker->StaminaPoints -= attack.StaminaCost;
	defender->LifePoints -= damage;
}

void LaunchedAttack::LaunchAttack(Enemy* atacker, Player* defender, PhysicalAttack attack)
{
	int damage = attack.AttackPoints;
	damage = damage * atacker->HoldingWeapon->Damage;
	atacker->StaminaPoints -= attack.StaminaCost;
	defender->LifePoints -= damage;
}
