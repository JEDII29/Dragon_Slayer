#include "Menu.h"

Menu::Menu()
{
	Window = new sf::RenderWindow(sf::VideoMode(480, 600), "Dragon Slayer");
	SelectedItemIndex = 0;

	if (!ClickBuffer.loadFromFile("Click.wav"))
	{
		std::cout << "Unable to get sound";
	}

	ClickSound.setBuffer(ClickBuffer);
	ClickSound.setVolume(4.0f);

	if (!MenuTheme.openFromFile("MenuTheme.ogg"))
	{
		std::cout << "Unable to get music";
	}

	MenuTheme.setVolume(3.0f);
	MenuTheme.setLoop(true);
	MenuTheme.play();

	BackTexture.loadFromFile("MenuBackground.png");
	Background.setTexture(BackTexture);
	Background.setScale(2.0f, 2.0f);

	if (!font.loadFromFile("lunchds.ttf"))
	{
		std::cout << "Unable to get font";
	}

	for (int i = 0; i < 3; i++)
	{
		Options[i].setFont(font);
		Options[i].setCharacterSize(40);
		Options[i].setFillColor(sf::Color::White);
	}
	Options[SelectedItemIndex].setFillColor(sf::Color::Red);

	Options[0].setString("Play");
	Options[0].setOrigin(Options[0].getGlobalBounds().width / 2, Options[0].getGlobalBounds().height / 2);
	Options[0].setPosition(sf::Vector2f(Window->getSize().x / 2, Window->getSize().y / 4 * (0 + 1)+40));
	Options[1].setString("Description");
	Options[1].setOrigin(Options[1].getGlobalBounds().width / 2, Options[1].getGlobalBounds().height / 2);
	Options[1].setPosition(sf::Vector2f(Window->getSize().x / 2, Window->getSize().y / 4 * (1 + 1)));
	Options[2].setString("Exit");
	Options[2].setOrigin(Options[2].getGlobalBounds().width / 2, Options[2].getGlobalBounds().height / 2);
	Options[2].setPosition(sf::Vector2f(Window->getSize().x / 2, Window->getSize().y / 4 * (2 + 1)-40));


	Description.setFont(font);
	Description.setCharacterSize(25);
	Description.setFillColor(sf::Color::Black);
	Description.setString("X-wykonanie akcji\nZ-cofniecie\n spiesz sie, nasz tylko\n 10 min na zdobycie\n 10 lvl");
	Description.setPosition(sf::Vector2f(80.0f, 180.0f));


}

Menu::~Menu()
{
}

void Menu::Update(bool& startGame)
{
	while (Window->pollEvent(Evnt))
	{
		switch (Evnt.type)
		{
		case sf::Event::KeyReleased:
		{
			switch (Evnt.key.code)
			{
			case sf::Keyboard::Up:
			{
				ClickSound.play();
				if (DescriptionShowed == false)
					MoveUp();
				break;
			}
			case sf::Keyboard::Down:
			{
				ClickSound.play();
				if(DescriptionShowed == false)
					MoveDown();
				break;
			}

			case sf::Keyboard::X:
			{
				ClickSound.play();
				switch (SelectedItemIndex)
				{
				case 0:
				{
					startGame = true;
					Window->close();
					break;
				}
				case 1:
				{
					if (DescriptionShowed == false)
						DescriptionShowed = true;
					break;
				}
				case 2:
				{
					Window->close();
					break;
				}
				}
				break;
			}
			case sf::Keyboard::Z:
			{
				ClickSound.play();
				if (DescriptionShowed)
				{
					DescriptionShowed = false;
				}
				else
				{
					Options[SelectedItemIndex].setFillColor(sf::Color::White);
					SelectedItemIndex = 2;
					Options[SelectedItemIndex].setFillColor(sf::Color::Red);
				}

				break;
			}
			}
			break;
		}
		case sf::Event::Closed:
		{
			Window->close();
		}

		}
	}
}

void Menu::Draw()
{
	Window->clear(sf::Color::Black);
	Window->draw(Background);
	if (DescriptionShowed)
	{
		Window->draw(Description);
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			Window->draw(Options[i]);
		}
	}



	Window->display();	
}

void Menu::MoveUp()
{
	Options[SelectedItemIndex].setFillColor(sf::Color::White);
	if (SelectedItemIndex - 1 >= 0)
	{
		SelectedItemIndex--;
		Options[SelectedItemIndex].setFillColor(sf::Color::Red);
	}
	else
	{
		SelectedItemIndex = 2;
		Options[SelectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	Options[SelectedItemIndex].setFillColor(sf::Color::White);
	if (SelectedItemIndex + 1 <= 2)
	{
		SelectedItemIndex++;
		Options[SelectedItemIndex].setFillColor(sf::Color::Red);
	}
	else
	{
		SelectedItemIndex = 0;
		Options[SelectedItemIndex].setFillColor(sf::Color::Red);
	}
}

