#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class PlayerAnimation
{
public:
	sf::IntRect UvRect;

	PlayerAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	void Update(int row, float deltaTime);


private:
	sf::Vector2u ImageCount;
	sf::Vector2u CurrentImage;

	float TotalTime;
	float SwitchTime;
};

