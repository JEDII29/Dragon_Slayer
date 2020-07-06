#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Character.h"
class Table
{
public:
	Table();
	Table(float width, float height, std::vector<PhysicalAttack*> attackList);
	void Draw(sf::RenderWindow* window);
	void SetItemsPositions();
	void MoveUp();
	void MoveDown();
	int GetSelectedOption(){ return SelectedOption; };
	bool ChoosingAttack;
private:
	int SelectedOption;
	sf::Font font;
	std::vector<sf::Text*> Options;

};

