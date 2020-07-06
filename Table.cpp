#include "Table.h"

Table::Table()
{
	if (!font.loadFromFile("lunchds.ttf"))
	{
		std::cout << "Unable to get font";
	}
	SelectedOption = 0;
	ChoosingAttack = false;
	sf::Text* field;
	field = new sf::Text("Move", font, 50);
	field->setFillColor(sf::Color::Red);
	field->setPosition(100.0f,600.0f);
	Options.push_back(field);

	field = new sf::Text("Block", font, 50);
	field->setFillColor(sf::Color::White);
	field->setPosition(300.0f, 600.0f);
	Options.push_back(field);
	field = new sf::Text("Run", font, 50);
	field->setPosition(500.0f, 600.0f);
	Options.push_back(field);
}

Table::Table(float width, float height, std::vector<PhysicalAttack*> attackList)
{
	if (!font.loadFromFile("lunchds.ttf"))
	{
		std::cout << "Unable to get font";
	}
	SelectedOption = 0;
	sf::Text* field;
	
	for (int i = 0; i < attackList.size(); i++)
	{
		field = new sf::Text(attackList[i]->Name, font, 50);
		field->setFillColor(sf::Color::White);
		Options.push_back(field);
	}
	Options[SelectedOption]->setFillColor(sf::Color::Red);
	SetItemsPositions();

}

void Table::Draw(sf::RenderWindow* window)
{
	for (int i = 0; i < Options.size(); i++)
	{
		window->draw(*Options[i]);
	}
}

void Table::SetItemsPositions()
{

}

void Table::MoveUp()
{
	if (SelectedOption - 1 >= 0)
	{
		Options[SelectedOption]->setFillColor(sf::Color::White);
		SelectedOption--;
		Options[SelectedOption]->setFillColor(sf::Color::Red);
	}
	else
	{
		Options[SelectedOption]->setFillColor(sf::Color::White);
		SelectedOption=Options.size()-1;
		Options[SelectedOption]->setFillColor(sf::Color::Red);
	}
}

void Table::MoveDown()
{
	if (SelectedOption + 1 < Options.size())
	{
		Options[SelectedOption]->setFillColor(sf::Color::White);
		SelectedOption++;
		Options[SelectedOption]->setFillColor(sf::Color::Red);
	}
	else
	{
		Options[SelectedOption]->setFillColor(sf::Color::White);
		SelectedOption = 0;
		Options[SelectedOption]->setFillColor(sf::Color::Red);
	}
}
