#include "PlayerAnimation.h"

PlayerAnimation::PlayerAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	SwitchTime = switchTime;
	ImageCount = imageCount;
	TotalTime = 0.0f;
	CurrentImage.x = 0;

	UvRect.width = texture->getSize().x / float(imageCount.x);
	UvRect.height = texture->getSize().y / float(imageCount.y);
}

void PlayerAnimation::Update(int row, float deltaTime, bool isMoving)
{
	if (isMoving)
		row += 4;
	CurrentImage.y = row;
	TotalTime += deltaTime;

	if (TotalTime >= SwitchTime)
	{
		TotalTime -= SwitchTime;
		CurrentImage.x++;
	}

	if (CurrentImage.x >= ImageCount.x)
	{
		CurrentImage.x = 0;
	}

	UvRect.left = CurrentImage.x * UvRect.width;
	UvRect.top = CurrentImage.y * UvRect.height;
}
