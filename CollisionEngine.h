#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Tile.h"
#include "Character.h"

class CollisionEngine
{
public:
	bool CheckHeroCollisionWithWalls(Player* hero, Tile wall);
	bool CheckHeroCollisionWithGrass(Player* hero, Tile grass);
};

