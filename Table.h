#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Character.h"
class Table
{
public:
	Table();
	Table(std::vector<PhysicalAttack*> attackList);
	void Draw(sf::RenderWindow* window);
	void Draw5Items(sf::RenderWindow* window);
	void MoveUp();
	void MoveDown();
	int GetSelectedOption(){ return SelectedOption; };
	void SelectExit();
	bool ChoosingAttack;
private:
	int SelectedOption;
	sf::Font font;
	std::vector<sf::Text*> Options;

};

