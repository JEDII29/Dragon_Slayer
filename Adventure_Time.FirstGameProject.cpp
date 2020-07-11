#include "Game.h"
#include "Menu.h"
#include "EndScreen.h"

using namespace std;



int main() 
{
	srand(time(0));
	bool StartGame = false;
	Game* game;
	Menu* menu = new Menu();
	while (menu->Window->isOpen())
	{
		menu->Update(StartGame);
		menu->Draw();
	}

	delete menu;

	if (StartGame)
	{
		game = new Game();
		while (game->Run())
		{
			game->PollEvnt();
			game->Update();
			game->Render();
			if (game->Hero->LifePoints <= 0 || game->Timer<= 0.0f)
			{
				auto endscreen = std::make_unique<EndScreen>(false, game->Screen->getCenter());
				for (int i = 0; i < 500; i++)
				{
					endscreen->Render(game->Window);
				}
				game->Window->close();
				break;
			}
			if (game->Hero->GetLvl()>=10)
			{
				auto endscreen = std::make_unique<EndScreen>(true, game->Screen->getCenter());
				for (int i = 0; i < 500; i++)
				{
					endscreen->Render(game->Window);
				}
				game->Window->close();
				break;
			}
		}
		delete game;
	}



	return 0;
}