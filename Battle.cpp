#include "Battle.h"


Battle::Battle(Player* hero)
{
	Screen.setCenter(600.0f, 360.0f);
	Screen.setSize(1200.0f, 720.0f);
	Opponent = new Enemy();
	Hero = hero;
	Action = new Table();
	sf::Color color(128,128,128);
	Field[0].setPosition(0.0f, 0.0f);
	Field[0].setFillColor(color);
	Field[0].setSize(sf::Vector2f(200.0f, 580.0f));
	Field[1].setPosition(0.0f, 580.0f);
	Field[1].setFillColor(color);
	Field[1].setSize(sf::Vector2f(1200.0f, 140.0f));
	//Background->loadFromFile("Battlefield.png");
}

Battle::Battle(Player* hero, Enemy* opponent)
{
	Hero = hero;
	Opponent = opponent;
	Background->loadFromFile("Battlefield.png");
}

void Battle::Update(sf::RenderWindow* window, sf:: Event evnt)
{
	Opponent->LifePoints = 100;
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
				Action->MoveUp();
				break;
			}
			case sf::Keyboard::Down:
			{
				Action->MoveDown();
				break;
			}
			case sf::Keyboard::Left:
			{
				Action->MoveUp();
				break;
			}
			case sf::Keyboard::Right:
			{
				Action->MoveDown();
				break;
			}
			case sf::Keyboard::Z:
			{
				switch (Action->GetSelectedOption())
				{
				case 0:
				{
					break;
				}
				case 1:
				{
					break;
				}
				case 2:
				{
					Opponent->LifePoints = 0;
					break;
				}
				default:
					break;
				}
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

void Battle::Render(sf::RenderWindow* window)
{
	window->clear();
	window->setView(Screen);

	window->draw(Hero->FightBody);
	window->draw(Opponent->FightBody);

	window->draw(Field[0]);
	window->draw(Field[1]);

	Action->Draw(window);

	window->display();

}



void Battle::Run(sf::RenderWindow* window, sf::Event evnt)
{
	Update(window, evnt);
	Render(window);
}




