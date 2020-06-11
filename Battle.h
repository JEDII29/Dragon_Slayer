#pragma once
#include "Character.h"
class Battle
{
public:
	Battle();
	Battle(Player* hero);
private:
	Player* Hero;
	Enemy Opponent;
};

