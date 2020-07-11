#include <SFML\Graphics\Sprite.hpp>
#pragma once
class Tile: public sf::Sprite
{
public:
	bool IsWall;
	bool CanSpawn;
	int Difficulty;
};

