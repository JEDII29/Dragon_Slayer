#include "Battle.h"
#include "LaunchedAttack.h"


Battle::Battle(Player* hero, int difficulty)
{
	Screen.setCenter(600.0f, 360.0f);
	Screen.setSize(1200.0f, 720.0f);
	Difficulty = difficulty;
	Opponent = new Enemy(Difficulty);
	Hero = hero;
	SetTables();
	BackTexture = new sf::Texture();
	BackTexture->loadFromFile("Battlefield.png");
	Background.setTexture(*BackTexture);
	Background.setScale(3.0f, 3.0f);
	PlayerTurn = rand() % 2;

	if (!ClickBuffer.loadFromFile("Click.wav"))
	{
		std::cout << "Unable to get sound";
	}
	ClickSound.setBuffer(ClickBuffer);
	ClickSound.setVolume(4.0f);
	if (!DamageBuffer.loadFromFile("DamageSound.wav"))
	{
		std::cout << "Unable to get sound";
	}
	DamageSound.setBuffer(DamageBuffer);
	DamageSound.setVolume(4.0f);
	if (!AttackBuffer.loadFromFile("AttackSound.wav"))
	{
		std::cout << "Unable to get sound";
	}
	AttackSound.setBuffer(AttackBuffer);
	AttackSound.setVolume(5.0f);
	if (!BlockBuffer.loadFromFile("BlockSound.wav"))
	{
		std::cout << "Unable to get sound";
	}
	BlockSound.setBuffer(BlockBuffer);
	BlockSound.setVolume(4.0f);

	if (!BattleTheme.openFromFile("FightTheme.ogg"))
	{
		std::cout << "Unable to get music";
	}
	BattleTheme.setVolume(3.0f);
	BattleTheme.setLoop(true);
	BattleTheme.play();
}

Battle::Battle(Player* hero, Enemy* opponent)
{
	Hero = hero;
	Opponent = opponent;
	BackTexture->loadFromFile("Battlefield.png");
}

void Battle::Update(sf::RenderWindow* window, sf:: Event evnt)
{
	if (PlayerTurn)
	{
		MakePlayerMove(window, evnt);
	}
	else
	{
		MakeEnemyMove();
	}

	HeroLifePoints.setString(std::to_string(Hero->LifePoints));
	HeroStaminaPoints.setString(std::to_string(Hero->StaminaPoints));
	EnemyLifePoints.setString(std::to_string(Opponent->LifePoints));
}

void Battle::Render(sf::RenderWindow* window)
{
	window->clear();
	window->setView(Screen);

	window->draw(Background);
	window->draw(Hero->FightBody);
	window->draw(Opponent->FightBody);

	window->draw(Field[0]);
	window->draw(Field[1]);

	window->draw(HeroLifePoints);
	window->draw(HeroStaminaPoints);
	window->draw(EnemyLifePoints);

	Action->Draw(window);
	if (Action->ChoosingAttack)
	{
		MoveSet->Draw5Items(window);
	}
	

	window->display();

}

void Battle::MakePlayerMove(sf::RenderWindow* window, sf::Event evnt)
{
	while (window->pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::KeyReleased:
		{
			switch (evnt.key.code)
			{
			case sf::Keyboard::Up:
			{
				ClickSound.play();
				if (Action->ChoosingAttack)
				{
					MoveSet->MoveUp();
				}
				else
				{
					Action->MoveUp();
				}
				break;
			}
			case sf::Keyboard::Down:
			{
				ClickSound.play();
				if (Action->ChoosingAttack)
				{
					MoveSet->MoveDown();
				}
				else
				{
					Action->MoveDown();
				}
				break;
			}
			case sf::Keyboard::Left:
			{
				ClickSound.play();
				if (Action->ChoosingAttack)
				{
					MoveSet->MoveUp();
				}
				else
				{
					Action->MoveUp();
				}
				break;
			}
			case sf::Keyboard::Right:
			{
				ClickSound.play();
				if (Action->ChoosingAttack)
				{
					MoveSet->MoveDown();
				}
				else
				{
					Action->MoveDown();
				}
				break;
			}
			case sf::Keyboard::X:
			{
				ClickSound.play();
				if (Action->ChoosingAttack)
				{
					AttackSound.play();
					auto Move = std::make_unique<LaunchedAttack>();
					if (Move->CheckAttackCost(*Hero, *Hero->MoveList[MoveSet->GetSelectedOption()]))
					{
						Move->LaunchAttack(Hero, Opponent, *Hero->MoveList[MoveSet->GetSelectedOption()]);
						PlayerTurn = false;
					}
				}
				else
				{
					switch (Action->GetSelectedOption())
					{
					case 0:
					{
						Action->ChoosingAttack = true;
						break;
					}
					case 1:
					{
						BlockSound.play();
						Hero->StaminaPoints += rand() % 11 + 20;
						if (Hero->StaminaPoints > Hero->MaxStamina)
						{
							Hero->StaminaPoints = Hero->MaxStamina;
						}
						PlayerTurn = false;
						break;
					}
					case 2:
					{
						Running = true;
						break;
					}
					default:
						break;
					}
					break;
				}
			}
			case sf::Keyboard::Z:
			{
				ClickSound.play();
				if (Action->ChoosingAttack)
					Action->ChoosingAttack = false;
				else
					Action->SelectExit();
				break;
			}
			}
			break;
		}
		case sf::Event::Closed:
		{
			window->close();
		}

		default:
			break;
		}
	}
}

void Battle::MakeEnemyMove()
{
	NextMove += Elapsed;
	if (NextMove >= 3)
	{
		NextMove = 0;
		int ChosenAttack;
		while (true)
		{
			ChosenAttack = rand() % Opponent->MoveList.size();
			auto Move = std::make_unique<LaunchedAttack>();
			if (Move->CheckAttackCost(*Opponent, *Opponent->MoveList[ChosenAttack]))
			{
				Move->LaunchAttack(Opponent, Hero, *Opponent->MoveList[ChosenAttack]);
				DamageSound.play();
				PlayerTurn = true;
				break;
			}
		}
	}
}

void Battle::SetTables()
{
	if (!Letters.loadFromFile("lunchds.ttf")) {
	}
	Action = new Table();
	MoveSet = new Table(Hero->MoveList);
	sf::Color color(128, 128, 128);
	Field[0].setPosition(0.0f, 0.0f);
	Field[0].setFillColor(color);
	Field[0].setSize(sf::Vector2f(200.0f, 580.0f));
	Field[1].setPosition(0.0f, 580.0f);
	Field[1].setFillColor(color);
	Field[1].setSize(sf::Vector2f(1200.0f, 140.0f));

	HeroLifePoints.setCharacterSize(30);
	HeroLifePoints.setFont(Letters);
	HeroLifePoints.setFillColor(sf::Color::Red);
	HeroLifePoints.setPosition(50.0f,580.0f);

	HeroStaminaPoints.setCharacterSize(30);
	HeroStaminaPoints.setFont(Letters);
	HeroStaminaPoints.setFillColor(sf::Color::Yellow);
	HeroStaminaPoints.setPosition(50.0f, 640.0f);

	EnemyLifePoints.setCharacterSize(30);
	EnemyLifePoints.setFont(Letters);
	EnemyLifePoints.setFillColor(sf::Color::Red);
	EnemyLifePoints.setPosition(1100.0f, 580.0f);
}



void Battle::Run(sf::RenderWindow* window, sf::Event evnt, float elapsed)
{
	Elapsed = elapsed;
	Update(window, evnt);
	Render(window);
}




