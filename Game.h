#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <map>
#include "Character.h"
#include "Matrix.h"

class Game
{
public:
	Player* Hero;
    sf::RenderWindow* Window;
    sf::Event Evnt;
    sf::Clock Clk;
    sf::Time Elapsed;
    std::map<char , sf::Texture> MapTextures;

    Game();
    void LoadTextures();
    void LoadAllData();
    bool Run();
    void Update();
    void Render();

};

