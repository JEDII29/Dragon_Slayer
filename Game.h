#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Character.h"

class Game
{
public:
	Player hero;
    sf::RenderWindow* window;
    sf::Event evnt;
    sf::Clock clock;
    sf::Time elapsed;
    
    
    std::map<std::string, sf::Texture*> map_textures;

    std::vector<sf::Sprite*> sprites;

    std::vector<sf::IntRect> v_intrect_sprite;

};

