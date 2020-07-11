#include "Game.h"
#include "Battle.h"
#include <cmath>

Game::Game()
{
	Window = new sf::RenderWindow(sf::VideoMode(1200, 720), "Dragon Slayer");
	Hero = new Player;
	EnemysList.push_back(new Enemy());
	LoadAllData();
	CurrentLocation = new Map("testingLocation.txt", TexturesMap, Grass);
	Screen = new sf::View(sf::Vector2f(0.0f,0.0f), sf::Vector2f(1200.0f, 720.0f));
	Timer = 600.0f;
	if (!TimerFont.loadFromFile("lunchds.ttf"))
	{
		std::cout << "Unable to get font";
	}
	TimerDisplay.setFont(TimerFont);
	TimerDisplay.setFillColor(sf::Color::Magenta);

	if (!ClickBuffer.loadFromFile("Click.wav"))
	{
		std::cout << "Unable to get sound";
	}

	ClickSound.setBuffer(ClickBuffer);
	ClickSound.setVolume(4.0f);

	if (!MainTheme.openFromFile("MainTheme.ogg"))
	{
		std::cout << "Unable to get music";
	}

	MainTheme.setVolume(3.0f);
	MainTheme.setLoop(true);
	MainTheme.play();


}

void Game::LoadTextures()
{
	sf::Texture* txtr = new sf::Texture;
	txtr->loadFromFile("Grass.png");
	TexturesMap['a'] = txtr;
	txtr = new sf::Texture;
	txtr->loadFromFile("WallRock.png");
	TexturesMap['b'] = txtr;
	txtr = new sf::Texture;
	txtr->loadFromFile("TallGrassUp.png");
	TexturesMap['g'] = txtr;
	txtr = new sf::Texture;
	txtr->loadFromFile("TallGrassUp.png");
	TexturesMap['h'] = txtr;
	txtr = new sf::Texture;
	txtr->loadFromFile("TallGrassUp.png");
	TexturesMap['i'] = txtr;
	txtr = new sf::Texture;
	txtr->loadFromFile("TallGrassUp.png");
	TexturesMap['j'] = txtr;
	txtr = new sf::Texture;
	txtr->loadFromFile("TallGrassUp.png");
	TexturesMap['k'] = txtr;
	txtr = new sf::Texture;
	txtr->loadFromFile("TallGrassDown.png");
	TexturesMap['l'] = txtr;
}


void Game::LoadAllData()
{
	LoadTextures();
}

bool Game::Run()
{
	return Window->isOpen();
}

void Game::Update()
{
	Window->setFramerateLimit(60);
	Elapsed = Clk.restart();
	float elapsed = Elapsed.asSeconds();
	Timer -= elapsed;
	TimerDisplay.setString("Time: "+std::to_string((int)ceil(Timer)));
	Hero->Update(elapsed);
	Screen->setCenter(Hero->Body.getPosition());
	PlayerStats.Update(Hero->LifePoints, Hero->StaminaPoints, Hero->Maxhealth, Hero->MaxStamina, Hero->GetLvl(), Hero->Exp, Screen->getCenter());
	TimerDisplay.setPosition(Screen->getCenter().x+380, Screen->getCenter().y+250);



	for (int i = Hero->PositionIndeks.x-1; i <= Hero->PositionIndeks.x + 1; i++)
	{
		for (int j = Hero->PositionIndeks.y - 1; j <= Hero->PositionIndeks.y + 1; j++)
		{
			if (CurrentLocation->Location[j][i].IsWall)
				Hero->Stop(Collisions.CheckHeroCollisionWithWalls(Hero, CurrentLocation->Location[j][i]));
		}
	}
	if (CurrentLocation->Location[Hero->PositionIndeks.y][Hero->PositionIndeks.x].CanSpawn
		&& Hero->Checked == false)
	{
		if (Collisions.CheckHeroCollisionWithGrass(Hero, CurrentLocation->
			Location[Hero->PositionIndeks.y][Hero->PositionIndeks.x]))
		{
			MainTheme.pause();
			Battle* Fight = new Battle(Hero, CurrentLocation->
				Location[Hero->PositionIndeks.y][Hero->PositionIndeks.x].Difficulty);
			while (true)
			{
				Timer -= elapsed;
				Fight->Run(Window, Evnt, elapsed);		
				if (Fight->Hero->LifePoints <= 0 || Fight->Running == true || Timer <= 0.0f)
				{
					break;
				}
				if (Fight->Opponent->LifePoints <= 0)
				{
					Hero->Exp += Fight->Difficulty*5;
					Hero->RaiseLvl();
					break;
				}
			}
			delete Fight;
			MainTheme.play();
		}
	}



	


}


void Game::Render()
{
	Window->clear(sf::Color::Black);
	Window->setView(*Screen);

	for (int i = 0; i < CurrentLocation->Location.size(); i++)
	{
		for (int j = 0; j < CurrentLocation->Location[i].size(); j++)
		{
			Window->draw(CurrentLocation->Location[i][j]);
		}
	}

	for (int i = 0; i < EnemysList.size(); i++)
	{
		Window->draw(EnemysList[i]->Body);
	}

	Window->draw(Hero->Body);

	for (int i = 0; i < Grass.size(); i++)
	{
		Window->draw(*Grass[i]);
	}
	PlayerStats.Render(Window);
	Window->draw(TimerDisplay);

	// end the current frame
	Window->display();
}

void Game::PollEvnt()
{
	// "close requested" event: we close the window
	while (Window->pollEvent(Evnt))
	{
		if (Evnt.type == sf::Event::Closed || Evnt.key.code == sf::Keyboard::Escape)
		{
			this->Window->close();
		}
	}
}
