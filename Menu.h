#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Table.h"
#include "Game.h"

class Menu
{
public:
	Menu();
	~Menu();
	void Update(bool& startGame);
	void Draw();
	void MoveUp();
	void MoveDown();

	sf::RenderWindow* Window;

protected:
	sf::Clock Clk;
	sf::Event Evnt;
	sf::Text Options[3];
	sf::Text Description;
	sf::Font font;
	sf::Texture BackTexture;
	sf::Sprite Background;
	sf::Music MenuTheme;
	sf::Sound ClickSound;
	sf::SoundBuffer ClickBuffer;
	int SelectedItemIndex;
	bool DescriptionShowed;


	
};

