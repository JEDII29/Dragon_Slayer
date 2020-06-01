#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <fstream>
#include "Game.h"

using namespace std;

int main() 
{

	Game* game = new Game;
	while (game->Run())
	{
		game->Update();
		game->Render();

	}

	return 0;
}