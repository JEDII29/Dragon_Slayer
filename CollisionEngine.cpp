#include "CollisionEngine.h"

bool CollisionEngine::CheckHeroCollisionWithWalls(Player* hero, Tile wall)
{
	float deltaX = hero->Body.getPosition().x - wall.getPosition().x;
	float deltaY = hero->Body.getPosition().y - wall.getPosition().y;
	float intersectX = abs(deltaX) - 60.0f;
	float intersectY = abs(deltaY) - 60.0f;

	if (intersectX < 0.0f && intersectY < 0.0f)
		return true;
	else
		return false;
}

bool CollisionEngine::CheckHeroCollisionWithGrass(Player* hero, Tile grass)
{
	hero->Checked = true;
	if (rand() % 4 == 0)
	{
		return true;
	}
	else
		return false;
}
