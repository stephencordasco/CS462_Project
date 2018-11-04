//main for windows app
#pragma once

#ifdef _WIN32
#include "../UI/Windows/UI_console_win.h"
#include "Game/Windows/Game_win.h"
#else
#include "../UI/Windows/UI_console_linux.h"
#include "Game/Windows/Game_linux.h"
#endif

class MainFactory
{
public:
	static UI::UI_console* create_UI()
	{
#ifdef _WIN32
		return new UI::UI_console_win();
#else
		return new UI::UI_console_linux();
#endif		
	}
	static Domain::Game* create_Game(UI::UI_console* game_UI)
	{
#ifdef _WIN32
		return new Domain::Game_win(game_UI);
#else
		return new Domain::Game_linux(game_UI);
#endif		
	}
};

int main(void) 
{

	UI::UI_console * game_UI = MainFactory::create_UI();
	Domain::Game * game = MainFactory::create_Game(game_UI);
	Services::Game_server * server = new Services::Game_server();
	
	game->set_game_Server(server);
	game_UI->set_Game(game);
	game_UI->set_Server(server);

	bool cont = true;
	while (cont) 
	{
		// login first
		cont = game_UI->login();
		// if cont is still true (user did not choose to quit application), continue execution
		while (cont)
		{
			// now print main menu
			cont = game_UI->mainMenu();
		}
	}

	delete game_UI;
	delete game;
	delete server;

	system("pause");
	return 0;
}