#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Character
{
public:
	sf::Sprite body;
	sf::Texture textr;
	
};

class Player : public Character
{
public:
	Player();
	void 
	void move();
};
