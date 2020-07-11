#pragma once
#include "Character.h"
#include "table.h"
#include "SFML/Audio.hpp"

class Battle
{
public:
	Battle();
	Battle(Player* hero, int difficulty);
	Battle(Player* hero, Enemy* opponent);

	void Run(sf::RenderWindow* window, sf::Event evnt, float elapsed);
	sf::Texture* BackTexture;
	Enemy* Opponent;
	Player* Hero;
	bool Running;
	int Difficulty;

private:
	bool PlayerTurn;
	float Elapsed, NextMove;

	sf::Sprite Background;
	sf::View Screen;
	sf::RectangleShape Field[2];
	sf::RectangleShape Rectangle;
	Table* Action;
	Table* MoveSet;
	sf::Font Letters;
	sf::Text HeroLifePoints;
	sf::Text HeroStaminaPoints;
	sf::Text EnemyLifePoints;

	sf::Music BattleTheme;
	sf::Sound ClickSound;
	sf::SoundBuffer ClickBuffer;
	sf::Sound DamageSound;
	sf::SoundBuffer DamageBuffer;
	sf::Sound AttackSound;
	sf::SoundBuffer AttackBuffer;
	sf::Sound BlockSound;
	sf::SoundBuffer BlockBuffer;

	void Update(sf::RenderWindow* window, sf::Event evnt);
	void Render(sf::RenderWindow* window);
	void MakePlayerMove(sf::RenderWindow* window, sf::Event evnt);
	void MakeEnemyMove();
	void SetTables();
};

