#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Character.h"
#include "Matrix.h"

class Game
{
public:
	Player* hero;
    sf::RenderWindow* window;
    sf::Event evnt;
    sf::Clock clock;
    sf::Time elapsed;

    Game();
    void loadAllData();
    void run();

};

