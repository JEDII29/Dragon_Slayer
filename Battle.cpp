#include "Battle.h"


Battle::Battle()
{
}

Battle::Battle(Player* hero)
{
	Hero = hero;
	Hero->HoldingWeapon.Damage = 10;
}
