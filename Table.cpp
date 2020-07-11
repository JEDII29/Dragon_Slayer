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
	field->setPosition(300.0f,600.0f);
	Options.push_back(field);

	field = new sf::Text("Block", font, 50);
	field->setFillColor(sf::Color::White);
	field->setPosition(500.0f, 600.0f);
	Options.push_back(field);
	field = new sf::Text("Run", font, 50);
	field->setPosition(700.0f, 600.0f);
	Options.push_back(field);
}

Table::Table(std::vector<PhysicalAttack*> attackList)
{
	if (!font.loadFromFile("lunchds.ttf"))
	{
		std::cout << "Unable to get font";
	}
	SelectedOption = 0;
	sf::Text* field;
	
	for (int i = 0; i < attackList.size(); i++)
	{
		field = new sf::Text(attackList[i]->Name, font, 40);
		field->setFillColor(sf::Color::White);
		Options.push_back(field);
	}
	Options[SelectedOption]->setFillColor(sf::Color::Red);

}

void Table::Draw(sf::RenderWindow* window)
{
	for (int i = 0; i < Options.size(); i++)
	{
		window->draw(*Options[i]);
	}
}

void Table::Draw5Items(sf::RenderWindow* window)
{
	sf::Text item;

	item = *Options[(SelectedOption + 2) % Options.size()];
	item.setPosition(10.0f, 100.0f);
	item.setFillColor(sf::Color::White);
	window->draw(item);

	item = *Options[(SelectedOption + 1) % Options.size()];
	item.setPosition(10.0f, 200.0f);
	item.setFillColor(sf::Color::White);
	window->draw(item);

	item = *Options[(SelectedOption) % Options.size()];
	item.setPosition(10.0f, 300.0f);
	window->draw(item);

	item = *Options[(SelectedOption -1 + Options.size()) % Options.size()];
	item.setPosition(10.0f, 400.0f);
	item.setFillColor(sf::Color::White);
	window->draw(item);

	item = *Options[(SelectedOption - 2 + Options.size()) % Options.size()];
	item.setPosition(10.0f, 500.0f);
	item.setFillColor(sf::Color::White);
	window->draw(item);

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

void Table::SelectExit()
{
	Options[SelectedOption]->setFillColor(sf::Color::White);
	SelectedOption = 2;
	Options[SelectedOption]->setFillColor(sf::Color::Red);
}
