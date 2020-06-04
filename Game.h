#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <map>
#include <fstream>
#include "Character.h"
#include "Map.h"

class Game
{
public:
	Player* Hero;
    sf::RenderWindow* Window;
    Map* CurrentLocation;
    sf::View* Screen;
    sf::Event Evnt;
    sf::Clock Clk;
    sf::Time Elapsed;
    std::map<char , sf::Texture*> TexturesMap;
    
    

    Game();
    void LoadTextures();
    void LoadAllData();
    bool Run();
    void Update();
    void Render();
};

