#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdio.h>
#include <map>
#include <fstream>
#include "Character.h"
#include "Map.h"
#include "CollisionEngine.h"
#include "StatsBadge.h"

class Game
{
public:
    Player* Hero;
    sf::RenderWindow* Window;
    sf::Text TimerDisplay;
    sf::View* Screen;
    float Timer;

    Game();
    bool Run();
    void Update();
    void Render();
    void PollEvnt();

private:
    StatsBadge PlayerStats;
    CollisionEngine Collisions;
    std::vector<Enemy*> EnemysList;
    std::vector<sf::Sprite*> Grass;
    std::map<char, sf::Texture*> TexturesMap;
    sf::Event Evnt;
    sf::Clock Clk;
    sf::Time Elapsed;
    Map* CurrentLocation;
    sf::Music MainTheme;
    sf::Sound ClickSound;
    sf::SoundBuffer ClickBuffer;
    sf::Font TimerFont;

    void LoadTextures();
    void LoadAllData();
};

