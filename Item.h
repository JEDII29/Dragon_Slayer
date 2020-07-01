#pragma once
#include <SFML\Graphics.hpp>



class Item
{
public:
	sf::Texture Skin;
};

class Weapon : public Item
{
public:
	int Damage;
	Weapon(int damage);
};

