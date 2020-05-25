#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <fstream>

using namespace std;

int main() {

	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(1100, 700), "Pupcia");

	sf::Texture wall, grass, guy;
	wall.loadFromFile("wall.png");
	grass.loadFromFile("grass.png");
	guy.loadFromFile("guy.png");
	vector<int> map 

	ifstream mapa("mapa.txt");
	if (mapa.is_open())
	{
		while (mapa.good())
		{

		}
	}


	//sf::Sprite sprite;
	//sprite.setTexture(grass);
	//sprite.setScale(0.5, 0.5);
	//sprite.setPosition(500, 300);

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (i == 0 || i == 6 || j == 0 || j == 10)
				map[i][j].setPosition(j*100,i*100);
			else
				map[i][j].setPosition(j * 100, i * 100);
		}
	}

	sf::Clock zegar;

	while (window.isOpen()) {
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		sf::Time elapsed = zegar.restart();
//		sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();


		//std::cout<<elapsed.asMicroseconds()<<std::endl;
		while (window.pollEvent(event)) {
			// "close requested" event: we close the window

			if (event.type == sf::Event::Closed)
				window.close();

		}


		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here... 

		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				window.draw(map[i][j]);
			}
		}

		


		// end the current frame
		window.display();
	}

	return 0;
}