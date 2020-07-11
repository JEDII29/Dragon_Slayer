#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

class EndScreen
{
public:
	EndScreen(bool win, sf::Vector2f view);
	void Render(sf::RenderWindow* window);
private:
	sf::Font font;
	sf::Text Info;
};

