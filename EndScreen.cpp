#include "EndScreen.h"

EndScreen::EndScreen(bool win, sf::Vector2f view)
{
	if (!font.loadFromFile("lunchds.ttf"))
	{
		std::cout << "Unable to get font";
	}
	Info.setFont(font);

	if (win)
	{
		Info.setString("You Won");
		Info.setCharacterSize(100);
		Info.setOrigin(Info.getGlobalBounds().width / 2, Info.getGlobalBounds().height / 2);
		Info.setPosition(view);
		Info.setFillColor(sf::Color(212, 175, 55));
	}
	else
	{
		Info.setString("You Lost");
		Info.setCharacterSize(100);
		Info.setOrigin(Info.getGlobalBounds().width / 2, Info.getGlobalBounds().height / 2);
		Info.setPosition(view);
		Info.setFillColor(sf::Color::Red);
	}

}

void EndScreen::Render(sf::RenderWindow* window)
{
	window->clear(sf::Color::Black);
	window->draw(Info);
	window->display();

}
