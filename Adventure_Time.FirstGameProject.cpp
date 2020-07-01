#include "Game.h"

using namespace std;

int main() 
{

	Game* game = new Game;
	while (game->Run())
	{
		game->PollEvnt();
		game->Update();
		game->Render();

	}

	return 0;
}