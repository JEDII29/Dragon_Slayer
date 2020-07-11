#include "StatsBadge.h"

StatsBadge::StatsBadge()
{
	if (!font.loadFromFile("lunchds.ttf"))
	{
	}
	//field = new sf::Text("Move", font, 50);
	//field->setFillColor(sf::Color::Red);
	//field->setPosition(300.0f, 600.0f);
	//Options.push_back(field);
	for (int i = 0; i < 4; i++)
	{
		text[i].setFont(font);
		text[i].setCharacterSize(20);
		text[i].setPosition(5.0f, 500+i*30);
	}

	text[0].setFillColor(sf::Color::Red);
	text[1].setFillColor(sf::Color::Yellow);
	text[2].setFillColor(sf::Color::Black);
	text[3].setFillColor(sf::Color(212, 175, 55));

	Back.setPosition(0.0f, 480.0f);
	Back.setSize(sf::Vector2f(150.0f, 150.0f));
	Back.setFillColor(sf::Color(192, 192, 192));

}

void StatsBadge::Update(int lifePoints, int staminaPoints, int maxLife, int maxStamina, int lvl, int _exp, sf::Vector2f view)
{
	text[0].setString("HP:"+std::to_string(lifePoints)+"/"+std::to_string(maxLife));
	text[1].setString("SP:"+std::to_string(staminaPoints) + "/" + std::to_string(maxStamina));
	text[2].setString("Exp:"+std::to_string(_exp) + "/" + std::to_string(lvl*10));
	text[3].setString("Lvl:"+std::to_string(lvl));

	for (int i = 0; i < 4; i++)
	{
		text[i].setPosition(view.x-570, view.y+240+i*20);
	}
	Back.setPosition(view.x - 600, view.y + 210);

}

void StatsBadge::Render(sf::RenderWindow* window)
{
	window->draw(Back);
	for (int i = 0; i < 4; i++)
	{
		window->draw(text[i]);
	}

}
